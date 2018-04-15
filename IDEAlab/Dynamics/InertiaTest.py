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
#k = Constant(1e-1,'k',system)

def createBlock(name, pos, rot, scale, mass):
    dx = scale[0]
    dy = scale[1]
    dz = scale[2]
    
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
    initialvalues[x]=pos[0]
    initialvalues[x_d]=0
    initialvalues[y]=pos[1]
    initialvalues[y_d]=0
    initialvalues[q]=rot*pi/180
    initialvalues[q_d]=0*pi/180
    
    pcm = x*N.x+y*N.y
    vcm=pcm.time_derivative(N,system)
    theta=q*N.z
    theta_d=theta.time_derivative(N,system)
    
    frame = Frame(name)
    
    frame.rotate_fixed_axis_directed(N,[0,0,1], q, system)
    
    I = Dyadic.build(frame, I_xx, I_yy, I_zz)
    
    body = Body(name+'body', frame, pcm, m, I, system)
    
    dictionary = {'y':y,'q':q, 'q_d':q_d, 'ini':initialvalues}
    
    return dictionary
    
variables = createBlock('A', [0,0,0], 0, [0.01,0.001,0.10], 0.01)

statevariables = system.get_state_variables()
ini = [variables['ini'][item] for item in statevariables]

tau = system.addforce(0.00001*N.z, variables['q_d']*N.z)
system.addforcegravity(-g*N.y)

f,ma = system.getdynamics()
func1 = system.state_space_post_invert(f,ma)

tinitial = 0
tfinal = 0.1
tstep = .01
t = numpy.r_[tinitial:tfinal:tstep]



states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-3,atol=1e-3,hmin=1e-14,args=({'constants':system.constant_values,'alpha':1e3,'beta':1e1},))

path="C:/Users/Jacob/Documents/Junior/IDEAlab/datas/Pynamics Results/"
rotation = Output([variables['q']*180/3.14159],system)
rotarray=rotation.calc(states)
rotation.plot_time(t)
height = Output([-variables['y']],system)
heightarray=rotation.calc(states)
numpy.savetxt(path+'data.csv', numpy.transpose([t,rotarray,heightarray]), delimiter=',')

