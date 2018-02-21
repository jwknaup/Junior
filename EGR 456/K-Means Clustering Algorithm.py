# -*- coding: utf-8 -*-
"""
Created on Thu Feb 15 13:18:56 2018

@author: Jacob
"""

import numpy as np
import matplotlib.pyplot as plt
#from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax=fig.add_subplot(111,projection='3d')

color=np.array([1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3])
sides=np.array([4,4,3,3,1,1,4,4,3,3,1,1,4,4,3,3,1,1])
size=np.array([2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1])

seed1=np.array([1,3,2])
seed2=np.array([2,3,1])


for runs in range(5):
    seed1MembersColor = []
    seed1MembersSides = []
    seed1MembersSize = []
    seed2MembersColor = []
    seed2MembersSides = []
    seed2MembersSize = []
    
    for i in range(0,color.size):
        distanceFromSeed1 = np.sqrt((color[i]-seed1[0])**2+(sides[i]-seed1[1])**2+(size[i]-seed1[2])**2)
        distanceFromSeed2 = np.sqrt((color[i]-seed2[0])**2+(sides[i]-seed2[1])**2+(size[i]-seed2[2])**2)
        
        if(distanceFromSeed1<distanceFromSeed2):
            seed1MembersColor=np.append(seed1MembersColor, [color[i]])
            seed1MembersSides=np.append(seed1MembersSides, [sides[i]])
            seed1MembersSize=np.append(seed1MembersSize, [size[i]])
        else:
            seed2MembersColor=np.append(seed2MembersColor, [color[i]])
            seed2MembersSides=np.append(seed2MembersSides, [sides[i]])
            seed2MembersSize=np.append(seed2MembersSize, [size[i]])
    
    seed1=np.array([np.mean(seed1MembersColor), np.mean(seed1MembersSides),np.mean(seed1MembersSize)])
    seed2=np.array([np.mean(seed2MembersColor), np.mean(seed2MembersSides),np.mean(seed2MembersSize)])

    print('seed1 = ', seed1)
    print('seed2 = ', seed2)


#scatter(color,sides,size)
        
ax.scatter(seed1MembersColor,seed1MembersSides,seed1MembersSize, c='b')
ax.scatter(seed2MembersColor,seed2MembersSides,seed2MembersSize, c='r')


ax.set_xlabel('color')
ax.set_ylabel('sides')
ax.set_zlabel('seize')

plt.show()