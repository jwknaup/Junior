# -*- coding: utf-8 -*-
"""
Created on Wed Feb 28 13:18:19 2018

@author: Jacob
"""
import matplotlib.pyplot as plt
import numpy as np

a = np.arange(0,10,1)
b=a
l = 10

plt.plot(a,b)
plt.title('Height of Top as Jumping')
plt.suptitle('length = ' + str(l) + ' (m), gear ratio = ' + str(l))
plt.xlabel('time (s)')
plt.ylabel('height (m)')