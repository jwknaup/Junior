# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
confirmed against:https://www.ee.usyd.edu.au/tutorials_online/matlab/examples/motor/motor.html
"""

import pynamics
from pynamics.frame import Frame
from pynamics.variable_types import Differentiable,Constant,Variable
from pynamics.system import System
from pynamics.body import Body
from pynamics.dyadic import Dyadic
from pynamics.output import Output
from pynamics.particle import Particle
import pynamics.integration

#import sympy
import numpy
import matplotlib.pyplot as plt
plt.ion()
from math import pi

def add_motor_dynamics():
    pass


system = System()

L = Constant(name='L',system=system)
V = Constant(name='V',system=system)
R = Constant(name='R',system=system)
Im = Constant(name='Im',system=system)
Il = Constant(name='Il',system=system)
G = Constant(name='G',system=system)
b = Constant(name='b',system=system)
f0 = Constant(name='f0',system=system)
kv = Constant(name='kv',system=system)
kt = Constant(name='kt',system=system)
Tl = Constant(name='Tl',system=system)
m = Constant(name='m',system=system)
g = Constant(name='g',system=system)

tinitial = 0
tfinal = 10
tstep = .01
t = numpy.r_[tinitial:tfinal:tstep]

#qA,qA_d,qA_dd = Differentiable('qA',system)
qB,qB_d,qB_dd = Differentiable('qB',system)
#wB,wB_d= Differentiable('wB',ii=1,limit=3,system=system)
i,i_d= Differentiable('i',ii=1,system=system)


constants = {}
constants[L] = .0166
constants[V] = 5.0
constants[R] = 4.3586
constants[G] = 1.0
constants[Im] = .00000001
constants[Il] = 0.0
constants[b] = 0.1798*10**-3
constants[f0] = 1.7999*10**-4
constants[kv] = .0016
constants[kt] = .0016
constants[Tl] = 0
constants[m] = 1
constants[g] = 9.81

initialvalues = {}
#initialvalues[qA]=0*pi/180
#initialvalues[qA_d]=0*pi/180
initialvalues[qB]=0*pi/180
initialvalues[qB_d]=0*pi/180
#initialvalues[wB]=0*pi/180
#initialvalues[a]=0
initialvalues[i]=0

statevariables = system.get_state_variables()
ini = [initialvalues[item] for item in statevariables]

N = Frame('N')
#A = Frame('A')
B = Frame('B')
M = Frame('M')

system.set_newtonian(N)
#A.rotate_fixed_axis_directed(N,[0,0,1],qA,system)
B.rotate_fixed_axis_directed(N,[0,0,1],qB,system)

pO = 0*N.x
#wNA = N.getw_(A)
wNB = N.getw_(B)
wNA = G*wNB
aNA = wNA.time_derivative()
#wNB = wB*B.z
#aNB = wB_d*B.z

I_motor = Dyadic.build(B,Im,Im,Im)
I_load = Dyadic.build(B,Il,Il,Il)

#Motor = Body('Motor',A,pO,0,I_motor,system)
Motor = Body('Motor',B,pO,0,I_motor,system,wNBody = wNA,alNBody = aNA)
Inductor = Particle(0*M.x,L,name='Inductor',vCM = i*M.x,aCM = i_d*M.x)

#Load = Body('Load',B,pO,0,I_load,system,wNBody = wNB,alNBody = aNB)
Load = Body('Load',B,pO,m,I_load,system)

#T = kt*(V/R)-kv*G*qB_d
T = kt*i
system.addforce(T*N.z,wNA)
#system.addforce(-b*wNA,wNA)
#system.addforce(-Tl*B.z,wNB)
system.addforce(-f0*B.z,wNA)
system.addforce((V-i*R - kv*G*qB_d)*M.x,i*M.x)
eq_d = []
#eq_d = [N.getw_(A).dot(N.z) - G*wB]
#eq_d = [N.getw_(A).dot(N.z) - G*N.getw_(B).dot(N.z)]
eq_dd= [system.derivative(item) for item in eq_d]


#import sympy
#ind = sympy.Matrix([wB])
#dep = sympy.Matrix([qA_d])
#
#EQ = sympy.Matrix(eq_d)
#A = EQ.jacobian(ind)
#B = EQ.jacobian(dep)
#dep2 = sympy.simplify(B.solve(-(A),method = 'LU'))

f,ma = system.getdynamics()
#f,ma = system.getdynamics([qB_d])
#f,ma = system.getdynamics([qA_d,wB])
#f.append(V-i*R - kv*G*qB_d)
#ma.append(L*i_d )
res = system.solve_f_ma(f,ma,system.get_q(2))
#func1 = system.state_space_pre_invert(f,ma,constants = system.constant_values)
func1 = system.state_space_post_invert(f,ma,eq_dd)
states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-10,atol=1e-10,args=({'constants':constants,'alpha':1e2,'beta':1e1},))

# =============================================================================
KE = system.get_KE()
PE = system.getPEGravity(0*N.x) - system.getPESprings()
energy = Output([KE-PE], constant_values = constants)
energy.calc(states)
energy.plot_time()
# =============================================================================

positions = Output(system.get_q(0), constant_values = constants)
positions.calc(states)
#positions.plot_time()

speeds = Output(system.get_q(1), constant_values = constants)
speeds.calc(states)
speeds.plot_time(t)

y= Output([G*qB_d], constant_values=constants)
y.calc(states)
y.plot_time(t)

#################################################################
directory = 'C:/Users/Jacob/Documents/Junior/IDEAlab/datas/Motor Characterization/Inertia/'
gear = '1'
file = 'motorAccel' + gear + '.csv'
tVIe = numpy.genfromtxt(directory + file, delimiter=',')
i0 = numpy.argmax(tVIe[:,1]<6.0)
t0 = tVIe[i0,0]
plt.figure()
plt.plot((tVIe[i0:-1,0]-t0)*1000, numpy.abs(tVIe[i0:-1,3]))
positions.plot_time(t)

