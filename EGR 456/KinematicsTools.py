# -*- coding: utf-8 -*-
"""
Created on Tue Jan 23 11:58:46 2018

@author: Jacob
"""
import sympy as sp
import numpy as np

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