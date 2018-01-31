# -*- coding: utf-8 -*-
"""
Created on Tue Jan 30 12:25:48 2018

@author: Jacob
"""

import numpy as np
import matplotlib.pyplot as plt

plt.figure(1)
plt.ion()
plt.hold(False)

p=np.array([[0.3],[2.0]])
R=np.array([[1.0,0.0],[0.0,1.0]])

a1=np.array([[0.0],[0.5]])
a2=np.array([[1.0],[0.0]])

b1=np.array([[-0.2],[0.0]])
b2=np.array([[0.1],[0.0]])

for i in np.arange(0, np.pi/2.0, np.pi/100.0):

#calc ouputs
    s1=p+np.dot(R,b1)-a1
    s2 = p+np.dot(R,b2)-a2
    
    s1Mag=np.linalg.norm(s1)
    s2Mag=np.linalg.norm(s2)
    
    print "Length s1 = ", s1Mag," Length s2 = ",s2Mag

    plt.plot([a1[0],s1[0]+a1[0],p[0],s2[0]+a2[0],a2[0]],
             [a1[1],s1[1]+a1[1],p[1],s2[1]+a2[1], a2[1]])
    plt.draw()
    plt.pause(0.02)
    theta=i
    R = [[np.cos(theta), np.sin(theta)],[np.sin(theta), -np.cos(theta)]]
  
plt.ioff()
plt.show()


# -*- coding: utf-8 -*-
"""
Created on Tue Jan 30 12:25:48 2018

@author: Jacob
"""

# =============================================================================
# import numpy as np
# import matplotlib.pyplot as plt
# 
# plt.figure(2)
# plt.ion()
# plt.hold(False)
# 
# p=np.array([[5.0],[5.0]])
# R=np.array([[0.866,-0.5],[0.5,0.866]])
# 
# a1=np.array([[0.0],[0.0]])
# a2=np.array([[10.0],[0.0]])
# 
# b1=np.array([[-2.0],[0.0]])
# b2=np.array([[2.0],[0.0]])
# 
# #calc ouputs
# s1=p+np.dot(R,b1)-a1
# s2 = p+np.dot(R,b2)-a2
# 
# s1Mag=np.linalg.norm(s1)
# s2Mag=np.linalg.norm(s2)
# 
# print "Length s1 = ", s1," Length s2 = ",s2Mag
# 
# plt.plot([a1[0],s1[0]+a1[0],p[0],s2[0]+a2[0],a2[0]],
#          [a1[1],s1[1]+a1[1],p[1],s2[1]+a2[1], a2[1]])
# plt.draw()
# plt.pause(0.02)
# theta=i
# R = [[np.cos(theta), np.sin(theta)],[np.sin(theta), -np.cos(theta)]]
#   
# plt.ioff()
# plt.show()
# =============================================================================
