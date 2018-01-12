import numpy as np
import matplotlib.pyplot as plt


root = 'C:/Users/Jacob/Documents/Junior/IDEAlab/datas/Jumping Results/'
width  ='01'
length = '08'
gear_ratio = '75'
trial = '1'
file = root + width +'_' + length + '_' + gear_ratio + '/trial' + trial + '/cameras.csv'
position = np.genfromtxt(file, delimiter=',')
print(position)

def maxHeightGet(array):    
    if(np.min(array[:,2]) < 0.05):
        index = 5
    elif( np.min(array[:,5]) < 0.05):
        index = 2
    elif(np.ptp(array[:,2]) > np.ptp(array[:,5])):
        index = 2
    else:
        index = 5
        
    array[array[:,index] > 0.54, index] = 0.25
    
    plt.plot(array[:,0], array[:,index])
    plt.show()
    plt.figure()
    #plt.plot(position[:,0], position[:,2])
    #plt.plot(position[:,0], position[:,6])
    
    maxIndeces = array.argmax(axis=0)
    maxTime = array[maxIndeces[index],0]
    maxHeight = array[maxIndeces[index], index]
    deltaY = maxHeight - array[0,index]
    deltaX = array[maxIndeces[index], index-1] - array[0,index-1]
    deltaZ = array[maxIndeces[index], index+1] - array[0,index+1]
    displacement = np.array([deltaX, deltaY, deltaZ])
    legLength = (2*float(length) - 1.43)/100.0
    deltaHeight = np.linalg.norm(displacement)
    jumpHeight = deltaHeight - legLength
    #print(maxTime)
    print(jumpHeight)
    return jumpHeight

#maxHeightGet(position)


import os

data = np.zeros([100,4])
i=0

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
               words = trialFolder.split('l')
               trial = words[1]
               directory = root + '/' + designFolder + '/' + trialFolder + '/'
               file = 'cameras.csv'
               try:
                   position = np.genfromtxt(directory + file, delimiter=',')
               except:
                   pass
               print(designFolder + '/' + trialFolder)
               jH = maxHeightGet(position)
               data[i,:] = [width, length, gear_ratio, jH]
               print('\n')
               i += 1
               
print(data)
plt.figure()
plt.subplot(221)
plt.title("length")
plt.plot(data[:,1], data[:,3], 'o')
plt.subplot(222)
plt.title("gear ratio")
plt.plot(data[:,2], data[:,3], 'o')      
