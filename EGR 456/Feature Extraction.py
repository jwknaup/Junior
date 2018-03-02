# -*- coding: utf-8 -*-
"""
Created on Thu Feb 08 16:49:18 2018

@author: Jacob
"""

import numpy as np
import cv2
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

cap=cv2.VideoCapture(0)
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
for j in np.arange(1,3,1):
    while 1:
        _, frame=cap.read()
        
        red=frame[:,:,2]
        green=frame[:,:,1]
        blue=frame[:,:,0]

        redOnly = np.int16(red)-0.75*np.int16(green)-0.75*np.int16(blue)
        redOnly[redOnly<75]=0
        redOnly[redOnly>=75]=255
        redOnly=np.uint8(redOnly)
        
        greenOnly = np.int16(green)-0.3*np.int16(red)-0.75*np.int16(blue)
        greenOnly[greenOnly<40]=0
        greenOnly[greenOnly>=40]=255
        greenOnly=np.uint8(greenOnly)

        blueOnly = np.int16(blue)-0.75*np.int16(red)-0.75*np.int16(green)
        blueOnly[blueOnly<50]=0
        blueOnly[blueOnly>=50]=255
        blueOnly=np.uint8(blueOnly)

        allOnly = redOnly + greenOnly + blueOnly

        mask=np.ones((5,5),np.uint8)
        opening=cv2.morphologyEx(allOnly, cv2.MORPH_OPEN, mask)
        cv2.imshow('masked', opening)

        _,labels=cv2.connectedComponents(opening, 4)
        b=np.matrix(labels)

        for i in np.arange(0,np.amax(labels)+1,1):
            obj=b==i
            obj=np.uint8(obj)
            obj[obj>0]=255
            cv2.imshow('object '+str(i),obj)
            if (i > 10):
                break
            
        cv2.imshow('Frame',frame)
        #cv2.imshow('allOnly', allOnly)
        #cv2.imshow('green',greenOnly)
        
        k=cv2.waitKey(5)
        if k==27:
            break

    cv2.destroyAllWindows()

    avgRed=[]
    avgGreen=[]
    avgBlue=[]
    avgSize=[]
    width=[]

    for i in np.arange(1,np.amax(labels)+1,1):
        obj=b==i
        redValues=np.array(obj)*np.array(red)
        greenValues=np.array(obj)*np.array(green)
        blueValues=np.array(obj)*np.array(blue)

        size=np.sum(obj)
        avgSize=size/255.0

        pixels = np.array(obj)*np.array(opening)
        columnSums=np.matrix(np.sum(pixels,0))
        print(columnSums)
        columnTrue = (columnSums > 0)
        print(columnTrue)
        width = np.sum(columnTrue)
        print(width)

##        column_numbers=np.matrix(np.arange(640))
##        columnMult = np.multiply(columnSums,column_numbers)
##        total = np.sum(columnMult)
##        totalTotal = np.sum(np.sum(redOnly))
##        columnLocation = total/totalTotal
        
        avgRed=np.append(avgRed,np.sum(redValues)/size)
        avgGreen=np.append(avgGreen,np.sum(greenValues)/size)
        avgBlue=np.append(avgBlue,np.sum(blueValues)/size)

        if i > 10:
            break
    if(j==1):
        ax.scatter(avgRed,avgSize,width)
    if j==2:
        ax.scatter(avgRed,avgSize,width,c='r')

        
ax.set_xlabel('red')
ax.set_ylabel('size')
ax.set_zlabel('blue')

plt.show()
