# -*- coding: utf-8 -*-
"""
Created on Thu Apr  5 11:28:13 2018

@author: Jacob
"""

import pynamics
from pynamics.frame import Frame
from pynamics.variable_types import Differentiable,Constant
from pynamics.system import System
from pynamics.body import Body
from pynamics.dyadic import Dyadic
from pynamics.output import Output
from pynamics.particle import Particle
import pynamics.integration

#import sympy
import numpy
#import scipy.integrate
import matplotlib.pyplot as plt
plt.ion()
from sympy import sin
from sympy import pi
import os    

system = System()

N = Frame('N')
system.set_newtonian(N)


g = Constant(9.81,'g',system)
#b = Constant(1e-1,'b',system)
k = Constant(1e0,'k',system)

def createBlock(name, pos, rot, scale, mass):
    dx = scale[2]
    dy = scale[1]
    dz = scale[0]
    
    lx = Constant(dx, name+'lx', system)
    ly = Constant(dy, name+'ly', system)
    lz = Constant(dz, name+'lz', system)
    
    m = Constant(mass, name+'m', system)
    
    I_xx = Constant(mass/12.0*(dy*dy + dz*dz), name+'I_xx',system)
    I_yy = Constant(mass/12.0*(dx*dx + dz*dz), name+'I_yy',system)
    I_zz = Constant(mass/12.0*(dx*dx + dy*dy), name+'I_zz',system)
    
    x,x_d,x_dd = Differentiable(name+'x',system)
    y,y_d,y_dd = Differentiable(name+'y',system)
    q, q_d, q_dd = Differentiable(name+'q',system)
    
    initialvalues = {}
    system.set_ini(x, pos[0])
    system.set_ini(x_d,0)
    system.set_ini(y,pos[1])
    system.set_ini(y_d,0)
    system.set_ini(q,rot*pi/180)
    system.set_ini(q_d,0*pi/180)
    
    pcm = x*N.x+y*N.y
    vcm=pcm.time_derivative(N,system)
    theta=q*N.z
    theta_d=theta.time_derivative(N,system)
    
    frame = Frame(name)
    
    frame.rotate_fixed_axis_directed(N,[0,0,1], q, system)
    
    I = Dyadic.build(frame, I_xx, I_yy, I_zz)
    
    body = Body(name+'body', frame, pcm, m, I, system)
    
    dictionary = {'pcm':pcm, 'vcm':vcm, 'y':y,'q':q, 'q_d':q_d, 'ini':initialvalues, 'dy':dy}
    
    return dictionary
    
A = createBlock('A', [0,0.5,0], 0, [0.05,0.05,0.05], 0.01)
B = createBlock('B', [0,0.4,0], 0, [0.05,0.05,0.05], 0.01)

statevariables = system.get_state_variables()
ini = system.get_ini()

spring = system.add_spring_force2(k, A['pcm']-B['pcm']-0.2*N.y, A['vcm'], -B['vcm'])
system.addforcegravity(-g*N.y)

stretch = -(B['pcm'].dot(N.y)-0.5*B['dy'])
stretchDot = B['vcm'].dot(N.y)
stretch_s = (stretch+abs(stretch))
stretchDot_s = (stretchDot-abs(stretchDot))
on = stretch_s/(2*stretch+1e-10)
onDot = stretchDot_s/(2*stretchDot+1e-10)
groundS, _ = system.add_spring_force1(1e4,-stretch_s*N.y,B['vcm'])
groundD = system.addforce(-1e2*B['vcm']*onDot*on,B['vcm'])


f,ma = system.getdynamics()
func1 = system.state_space_post_invert(f,ma)

tinitial = 0
tfinal = 1.0
tstep = .001
t = numpy.r_[tinitial:tfinal:tstep]



states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-3,atol=1e-3,hmin=1e-14,args=({'constants':system.constant_values,'alpha':1e3,'beta':1e1},))

path="C:/Users/Jacob/Documents/Junior/IDEAlab/datas/Pynamics Results/"
rotation = Output([A['y']],system)
rotarray=rotation.calc(states)
rotation.plot_time(t)
height = Output([B['y']],system)
heightarray=height.calc(states)
height.plot_time(t)
numpy.savetxt(path+'pogo.csv', numpy.transpose([t,rotarray,heightarray]), delimiter=',')

