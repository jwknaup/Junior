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
b = Constant(1e-1,'b',system)
k = Constant(1e-1,'k',system)

def createBlock(name, pos, rot, scale, mass):
    dx = scale[0]
    dy = scale[1]
    dz = scale[2]
    
    lx = Constant(dx[0], name+'lx', system)
    ly = Constant(dy[1], name+'ly', system)
    lz = Constant(dz[2], name+'lz', system)
    
    m = Constant(mass, name+'m', system)
    
    I_xx = Constant(m/12.0*(dy*dy + dz*dz), name+'I_xx',system)
    I_yy = Constant(m/12.0*(dx*dx + dz*dz), name+'I_yy',system)
    I_zz = Constant(m/12.0*(dx*dx + dy*dy), name+'I_zz',system)
    
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
    
    frame = Frame(name)
    
    I = Dyadic.build(frame, I_xx, I_yy, I_zz)
    
    body = Body(name+'body', frame, pcm, m, I, system)
    
createBlock('A', [0,0,0], 0, [0.01,0.001,0.05], 0.01)

