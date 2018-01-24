# -*- coding: utf-8 -*-
"""
Created on Tue Jan 23 11:53:40 2018

@author: Jacob
"""

import KinematicsTools as kt
import numpy as np
import sympy as sp


q1 = sp.Symbol("q1")
q2 = sp.Symbol("q2")
a1 = sp.Symbol("a1")
a2 = sp.Symbol("a2")
a3 = sp.Symbol("a3")
a4 = sp.Symbol("a4")


xDot = sp.Symbol('xDot')
yDot = sp.Symbol('yDot')


theta1 = q1
alpha1 = 0.0
r1 = a2
d1 = a1

theta2 = q2
alpha2 = 0.0
r2 = a4
d2 = a3

H0_0 = np.matrix(np.identity(4))
H0_1 = np.matrix(kt.dhHsym(theta1,alpha1,r1,d1))
H1_2 = np.matrix(kt.dhHsym(theta2,alpha2,r2,d2))
H0_2 = H0_1.dot(H1_2)
print(H0_2[:,-1])
print('\n')

jac1 = kt.jacobianColSym(H0_0,H0_2)
jac2 = kt.jacobianColSym(H0_1,H0_2)

jac = jac1.col_insert(1, jac2)

jacXY = jac[:2,:]
print(np.matrix(jacXY))
print('\n')

stateVarDers = jacXY.LUsolve(sp.Matrix([[xDot],[yDot]]))

stateVarDers.simplify()

print(stateVarDers[0].subs([(xDot, 1), (yDot, 1), (q1, 0.01), (q2, 1.5)]))