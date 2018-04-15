# -*- coding: utf-8 -*-
"""
Created on Tue Apr 10 22:14:48 2018

@author: Jacob
"""

import numpy as np
import matplotlib.pyplot as plt

directory = "C:/Users/Jacob/Documents/Junior/IDEAlab/datas/"

file='data.csv'
U = np.genfromtxt(directory+'Unity Results/'+file, delimiter=',')
P = np.genfromtxt(directory+'Pynamics Results/'+file, delimiter=',')

plt.plot(U[:,0],U[:,1])
plt.plot(P[:,0],P[:,1])
plt.figure()
plt.plot(U[:,0],U[:,2])
plt.plot(P[:,0],P[:,2])