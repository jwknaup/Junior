# -*- coding: utf-8 -*-
"""
Created on Thu Jan 18 13:33:03 2018

@author: Jacob
"""

import numpy as np
import sympy as sp


def dhHeval(theta, alpha, r, d):
    row1 = [np.cos(theta), -np.sin(theta)*np.cos(alpha), np.sin(theta)*np.sin(alpha), r*np.cos(theta)]
    row2 = [np.sin(theta), np.cos(theta)*np.cos(alpha), -np.cos(theta)*np.sin(alpha), r*np.sin(theta)]
    row3 = [0,np.sin(alpha), np.cos(alpha), d]
    row4 = [0,0,0,1]
    return[row1,row2,row3,row4]
def dhHsym(theta, alpha, r, d):
    row1 = [sp.cos(theta), -sp.sin(theta)*sp.cos(alpha), sp.sin(theta)*sp.sin(alpha), r*sp.cos(theta)]
    row2 = [sp.sin(theta), sp.cos(theta)*sp.cos(alpha), -sp.cos(theta)*sp.sin(alpha), r*sp.sin(theta)]
    row3 = [0,sp.sin(alpha), sp.cos(alpha), d]
    row4 = [0,0,0,1]
    return[row1,row2,row3,row4]
    
def jacobianColSym(Hi, Hn, jointType = 'rev'):
    if (jointType == 'rev'):
        linA = Hi[:-1,:-1].dot([[0],[0],[1]])
        linB = Hn[:-1,-1] - Hi[:-1,-1]
        lin = np.cross(linA,linB, axis=0)
        rot = linA
    else:
        lin = Hi[:-1,:-1].dot([[0],[0],[1]])
        rot = [[0],[0],[0]]
    ans = np.concatenate((lin,rot),0)
    ans = sp.Matrix(ans)
    ans = sp.trigsimp(ans)
    return sp.simplify(ans)
    
###
q1 = sp.Symbol("q1")
q2 = sp.Symbol("q2")
a1 = sp.Symbol("a1")
a2 = sp.Symbol("a2")
a3 = sp.Symbol("a3")

theta1 = -90.0*sp.pi/180.0+q1
alpha1 = -90.0*sp.pi/180.0
r1 = 0.0
d1 = a1

theta2 = 0.0
alpha2 = 0.0
r2 = 0.0
d2 = a2+a3 +q2

H0_0 = np.matrix(np.identity(4))
H0_1 = np.matrix(dhHsym(theta1,alpha1,r1,d1))
H1_2 = np.matrix(dhHsym(theta2,alpha2,r2,d2))
H0_2 = H0_1.dot(H1_2)

jac1 = jacobianColSym(H0_0,H0_2)
jac2 = jacobianColSym(H0_1,H0_2, 'prism')
print(np.matrix(jac1))
