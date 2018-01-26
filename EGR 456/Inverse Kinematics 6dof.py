# -*- coding: utf-8 -*-
"""
Created on Thu Jan 25 16:41:01 2018

@author: Jacob
"""

import numpy as np

x=5.0
y=0.0

theta2=np.arctan2(y,x)

R0_6 = [[0.707,-0.707,0.0],[0.707,0.707,0.0],[0.0,0.0,1.0]]

R0_3 = [[-np.sin(theta2),0.0,np.cos(theta2)],
        [np.cos(theta2), 0.0, np.sin(theta2)],
        [0.0,1.0,0.0]]

Ro_3inv = np.linalg.inv(R0_3)

R3_6=np.dot(Ro_3inv,R0_6)

print 'R3_6 = ', np.matrix(R3_6)
print '\n'

theta5=np.arccos(R3_6[2,2])+np.pi
print 'theta5 = ',theta5, 'rad'
theta6 = np.arccos(-R3_6[2,0]/np.sin(theta5))
print 'theta6 = ',theta6, 'rad'
theta4 = np.arccos(R3_6[1,2]/np.sin(theta5))
print 'theta4 = ',theta4, 'rad'

R3_6check = [[-np.sin(theta4)*np.cos(theta5)*np.cos(theta6)-np.cos(theta4)*np.sin(theta6),np.sin(theta4)*np.cos(theta5)*np.sin(theta6)-np.cos(theta4)*np.cos(theta6), -np.sin(theta4)*np.sin(theta5)],
            [np.cos(theta4)*np.cos(theta5)*np.cos(theta6)-np.sin(theta4)*np.sin(theta6), -np.cos(theta4)*np.cos(theta5)*np.sin(theta6)-np.sin(theta4)*np.cos(theta6), np.cos(theta4)*np.sin(theta5)],
            [-np.sin(theta5)*np.cos(theta6), np.sin(theta5)*np.sin(theta6)-np.cos(theta5), np.cos(theta5)]]

print'\n'
print 'R3_6check = ',np.matrix(R3_6check)

#######ARTICULATED ARM WITH SPHERICAL WRIST#######
import sympy as sp
import KinematicsTools as kt

q1 = sp.Symbol("q1")
q2 = sp.Symbol("q2")
q3 = sp.Symbol("q3")
q4 = sp.Symbol("q4")
q5 = sp.Symbol("q5")
q6 = sp.Symbol("q6")
a1 = sp.Symbol("a1")
a2 = sp.Symbol("a2")
a3 = sp.Symbol("a3")
a4 = sp.Symbol("a4")
a5 = sp.Symbol("a5")
a6 = sp.Symbol("a6")
a7 = sp.Symbol("a7")

H0_1 = kt.dhHsym(0.0, 0.0, 0.0, a1+q1)
H1_2 = kt.dhHsym(sp.pi/2+q2, sp.pi/2, 0.0, a2)
H2_3 = kt.dhHsym(0.0, 0.0, 0.0, a3+a4+q3)
H0_3 = H0_1*H1_2*H2_3
R0_3 = H0_3[:-1,:-1]
print R0_3
print '\n'
H3_4 = kt.dhHsym(sp.pi/2+q4, -sp.pi/2, 0.0, a5)
H4_5 = kt.dhHsym(q5, sp.pi/2, 0.0, 0.0)
H5_6 = kt.dhHsym(q6, 0.0, 0.0, a6+a7)
H3_6 = H3_4*H4_5*H5_6
R3_6 = H3_6[:-1,:-1]
print(R3_6)
