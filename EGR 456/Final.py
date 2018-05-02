# -*- coding: utf-8 -*-
"""
Created on Thu Feb 08 16:49:18 2018

@author: Jacob
"""

import numpy as np
import cv2
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from sklearn.neural_network import MLPClassifier

cap=cv2.VideoCapture(1)
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

trainingData=[[]]
trainingLabels=[]
testingData=[]
    
for j in np.arange(1,7,1):
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
        greenOnly[greenOnly<30]=0
        greenOnly[greenOnly>=30]=255
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

        #print(np.amax(labels))
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
    maxWidth=[]
    avgWidth=[]
    relWidth=[]
    
    maxHeight=[]
    relHeight=[]
    aspectRatio=[]
    percentFill=[] 

    for i in np.arange(1,np.amax(labels)+1,1):
        obj=b==i
        redValues=np.array(obj)*np.array(red)
        greenValues=np.array(obj)*np.array(green)
        blueValues=np.array(obj)*np.array(blue)

        size=np.sum(obj)
        avgSize=size/255.0

        pixels = np.array(obj)*np.array(opening)
        columnSums=np.matrix(np.sum(pixels,0))
        #print(columnSums)
        columnTrue = (columnSums > 0)
        #print(columnTrue)
        maxWidth = np.sum(columnTrue)
        relWidth = maxWidth/avgSize
        #print(avgWidth)

        rowSums=np.matrix(np.sum(pixels,1))
        #print(columnSums)
        rowTrue = (rowSums > 0)
        #print(columnTrue)
        maxHeight = np.sum(rowTrue)
        relHeight = maxHeight/avgSize
        #print(relHeight)

        aspectRatio = maxWidth/maxHeight
        #print(aspectRatio)

        percentFill=50000*avgSize/(maxHeight*maxWidth)
        #print(i)

##        column_numbers=np.matrix(np.arange(640))
##        columnMult = np.multiply(columnSums,column_numbers)
##        total = np.sum(columnMult)
##        totalTotal = np.sum(np.sum(redOnly))
##        columnLocation = total/totalTotal
        
        avgRed=np.sum(redValues)/size
        avgGreen=np.sum(greenValues)/size
        avgBlue=np.sum(blueValues)/size

        #print(avgRed)

        if i == 1 and j==1:
            trainingData = [[avgRed,avgBlue,avgGreen,maxWidth,maxHeight,percentFill]]
            trainingLabels=[j]
        elif j < 3:
            trainingData = np.vstack((trainingData,[[avgRed,avgBlue,avgGreen,maxWidth,maxHeight,percentFill]]))
            trainingLabels=np.append(trainingLabels,j)
        else:
            testingData = [[avgRed,avgBlue,avgGreen,maxWidth,maxHeight,percentFill]]

        if i > 10:
            break
        
    if(j==1):
        #ax.scatter(avgRed,avgSize,maxWidth)
        #print(trainingData)
        print(trainingLabels)
    elif (j==2):
        print(trainingData)
        print(trainingLabels)
        clf=MLPClassifier(solver='lbfgs',alpha=1e-5,hidden_layer_sizes=(100,), random_state=1)
        model=clf.fit(trainingData,trainingLabels)
        ax.scatter([item[-1] for item in trainingData],[item[3] for item in trainingData],[item[4] for item in trainingData],c=trainingLabels, marker='o')

        ax.set_xlabel('percentFill')
        ax.set_ylabel('width')
        ax.set_zlabel('height')
        plt.show()

    else:
        print(testingData)
        classification=clf.predict(testingData)
        print(classification)
