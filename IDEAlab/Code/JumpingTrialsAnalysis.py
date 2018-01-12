import numpy as np
import matplotlib.pyplot as plt


root = 'C:/Users/Jacob/Documents/Junior/IDEAlab/datas/Jumping Results/'
width  ='01'
length = '12'
gear_ratio = '150'
trial = '1'
file = root + width +'_' + length + '_' + gear_ratio + '/trial' + trial + '/cameras.csv'
position = np.genfromtxt(file, delimiter=',')
print(position)

if(position[0,2] > position[0,5]):
    index = 2
else:
    index = 5

plt.plot(position[:,0], position[:,index])
#plt.plot(position[:,0], position[:,4])
#plt.plot(position[:,0], position[:,6])

maxIndeces = position.argmax(axis=0)
maxTime = position[maxIndeces[index],0]
maxHeight = position[maxIndeces[index], index]
deltaY = maxHeight - position[0,index]
deltaX = position[maxIndeces[index], index-1] - position[0,index-1]
deltaZ = position[maxIndeces[index], index+1] - position[0,index+1]
displacement = np.array([deltaX, deltaY, deltaZ])
legLength = (2*float(length) - 1.43)/100.0
deltaHeight = np.linalg.norm(displacement)
jumpHeight = deltaHeight - legLength
print(maxTime)
print(jumpHeight)

import os

for entry in os.scandir(root):
   if not entry.name.startswith('s') and not entry.is_file():
       designFolder = entry.name
       words = designFolder.split('_')
       width = int(words[0])
       length = int(words[1])
       gear_ratio = int(words[2])
       for entry in os.scandir(root + '/' + designFolder):
           if entry.name.startswith('t') and not entry.is_file():
               trialFolder = entry.name
               

       
