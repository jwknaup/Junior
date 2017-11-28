# -*- coding: utf-8 -*-
"""
Created on Mon Nov 27 10:07:06 2017

@author: Jacob
"""

# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import pynamics
from pynamics.frame import Frame
from pynamics.variable_types import Differentiable,Constant
from pynamics.system import System
from pynamics.body import Body
from pynamics.dyadic import Dyadic
from pynamics.output import Output
from pynamics.particle import Particle

#import sympy
import numpy
import scipy.integrate
import matplotlib.pyplot as plt
plt.ion()
from sympy import pi
system = System()

thigh_length = Constant(.5,'l1',system)
calf_length = Constant(1.0, 'l2',system)
top_length = Constant(1.0, 'l0',system)
foot_length = Constant(1.0, 'l3',system)

M = Constant(10,'M',system)
m = Constant(2,'m',system)


I_xx = Constant(9,'I_xx',system)
I_yy = Constant(9,'I_yy',system)
I_zz = Constant(9,'I_zz',system)

g = Constant(9.81,'g',system)
b = Constant(1e2,'b',system)
k = Constant(1e4,'k',system)

tinitial = 0
tfinal = 10
tstep = .01
t = numpy.r_[tinitial:tfinal:tstep]

#x,x_d,x_dd = Differentiable('x',system)
q1,q1_d,q1_dd = Differentiable('q1',system)
q2,q2_d,q2_dd = Differentiable('q2',system)
q3,q3_d,q3_dd = Differentiable('q3',system)
q4,q4_d,q4_dd = Differentiable('q4',system)

initialvalues = {}
#initialvalues[x]=0.0
#initialvalues[x_d]=0

initialvalues[q1]=5*pi/180
initialvalues[q1_d]=0*pi/180
initialvalues[q2]=-5*pi/180
initialvalues[q2_d]=0*pi/180
initialvalues[q3]=(-2*q1+180)*pi/180
initialvalues[q3_d]=0*pi/180
initialvalues[q4]=(-2*q2-180)*pi/180
initialvalues[q4_d]=0*pi/180

statevariables = system.get_state_variables()
ini = [initialvalues[item] for item in statevariables]

N = Frame('N')
A = Frame('A')
B = Frame('B')
C = Frame('C')
D = Frame('D')

system.set_newtonian(N)
A.rotate_fixed_axis_directed(N,[0,0,1],q1,system)
B.rotate_fixed_axis_directed(N,[0,0,1],q2,system)
C.rotate_fixed_axis_directed(A,[0,0,1],q3,system)
D.rotate_fixed_axis_directed(B,[0,0,1],q4,system)


p1 = -0.5*top_length*N.x
p3 = p1 - thigh_length*A.x
p5 = p3 - calf_length*C.x
p2 = 0.5*top_length*N.x
p4 = p2 + thigh_length*B.x
p6 = p4 + calf_length*D.x
v1 = p1.time_derivative(N,system)
v2 = p2.time_derivative(N, system)
v3 = p3.time_derivative(N, system)
v4 = p4.time_derivative(N, system)
v5 = p5.time_derivative(N, system)
#v6 = v5



I = Dyadic.build(A,I_xx,I_yy,I_zz)


BodyA = Body('BodyA',A,p1,m,I,system)
BodyB = Body('BodyB',B,p2,m,I,system)
BodyC = Body('BodyC',C,p3,m,I,system)
BodyD = Body('BodyD',D,p4,m,I,system)



#ParticleO = Particle(p1,M,'ParticleO',system)


#stretch = x-xO
#system.add_spring_force(k,(stretch)*N.x,v1)
#system.addforce(-b*v1,v1)

#ParticleO.addforcegravity(-g*N.y)
#BodyA.addforcegravity(-g*N.y)
#system.addforce(-M*g*N.y,v1)
system.addforcegravity(-g*N.y)


eq = []
# =============================================================================
# #eq.append(pOcm.dot(N.y)-initialvalues[y])
# eq.append(p1.dot(N.x)-initialvalues[x])
# eq.append(q-initialvalues[q])
# #eq.append((pBtip-pDtip).dot(N.x))
# #eq.append((pBtip-pDtip).dot(N.y))
# =============================================================================


#eq.append(pBtip.dot(N.y))
#eq.append(pDtip.dot(N.y))

eq_d= [system.derivative(item) for item in eq]
eq_dd= [system.derivative(item) for item in eq_d]

pynamics.tic()
print('solving dynamics...')
f,ma = system.getdynamics()
print('creating second order function...')
func1 = system.state_space_post_invert(f,ma,eq_dd,constants = system.constant_values)
print('integrating...')
states=scipy.integrate.odeint(func1,ini,t,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e2,'beta':1e1},))
pynamics.toc()
print('calculating outputs..')

# =============================================================================
KE = system.get_KE()
PE = system.getPEGravity(0*N.x) - system.getPESprings()
# 
# 
energy = Output([KE-PE])
energy.calc(states)
energy.plot_time()
# =============================================================================


points = [p1,p2]
points = [item2 for item in points for item2 in [item.dot(N.x),item.dot(N.y)]]
points = Output(points)
y = points.calc(states)
y = y.reshape((-1,2,2))
plt.figure()
#for item in y[::30]:
plt.plot(y[:,1,0],y[:,1,1])
plt.axis('equal')

states2= Output([x,q])
states2.calc(states)


plt.figure()
plt.plot(states[:,0])
plt.figure()
plt.plot(states[:,1])
