# -*- coding: utf-8 -*-
"""
Created on Tue Nov 07 10:51:50 2017

@author: Jacob
"""

import matplotlib.pyplot as plt
import numpy as np

t=np.arange(0.0,5.0, 0.2)

plt.figure(1)
plt.subplot(121)
linea = plt.plot([1,2,3,4], [2,4,8,16], 'ro')
plt.ylabel('nums')
plt.annotate('local max', xy=(2, 4), xytext=(1.5, 8),
             arrowprops=dict(facecolor='black', shrink=0.05),
             )
plt.subplot(122)
lineb = plt.plot(t, t**3, 'bs')
plt.setp(lineb, color = 'y')
plt.axis([0,6,0,20])
plt.title('data', fontsize=14)
plt.legend('t')
plt.savefig('plot.png')
plt.show()
