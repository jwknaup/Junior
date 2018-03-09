import numpy as np
import matplotlib.pyplot as plt


root = 'C:/Users/Jacob/Documents/Junior/IDEAlab/datas/Jumping Results/'
width  ='01'
length = '12'
gear_ratio = '150'
trial = '1'
directory = root + width +'_' + length + '_' + gear_ratio + '/trial' + trial
file = directory + '/cameras.csv'
position = np.genfromtxt(file, delimiter=',')
file=directory + '/loadcell.csv'
force = np.genfromtxt(file, delimiter=',')
file=directory + '/arduino.csv'
arduino = np.genfromtxt(file, delimiter=',')
#print(force)

def maxHeightGet(array, l, ax=0):    
    if(np.min(array[:,2]) < 0.05):
        index = 5
    elif( np.min(array[:,5]) < 0.05):
        index = 2
    elif(np.ptp(array[:,2]) > np.ptp(array[:,5])):
        index = 2
    else:
        index = 5
        
    array[array[:,index] > 0.54, index] = 0.25
    
    if ax is not 0:
        ax.plot(array[:,0], array[:,index])
        ax.set_ylabel('h (m)',color='b' )
    #plt.show()
    #plt.figure()
    #plt.plot(position[:,0], position[:,2])
    #plt.plot(position[:,0], position[:,6])
    
    maxIndeces = array.argmax(axis=0)
    maxTime = array[maxIndeces[index],0]
    maxHeight = array[maxIndeces[index], index]
    deltaY = maxHeight - array[0,index]
    deltaX = array[maxIndeces[index], index-1] - array[0,index-1]
    deltaZ = array[maxIndeces[index], index+1] - array[0,index+1]
    displacement = np.array([deltaX, deltaY, deltaZ])
    legLength = (2*float(l) - 1.43)/100.0
    deltaHeight = np.linalg.norm(displacement)
    jumpHeight = deltaHeight - legLength
    if jumpHeight < 0:
        jumpHeight = 0
    #print(maxTime)
    print(jumpHeight)
    return jumpHeight, deltaHeight

def forceProfile(array, ax):
    ax.plot(array[:,0], array[:,1], 'r')
    ax.set_ylim([0,1.0])
    ax.set_ylabel('F (N)', color='r')
    
def electricalProfile(array, axA, axB):
    axA.plot(array[:,0], array[:,1], 'g')
    axB.plot(array[:,0], array[:,2], 'k')
    axA.set_ylim([0,8.0])
    axB.set_ylim([0,2.0])
    axA.set_ylabel('V (V)', color='g')
    axB.set_ylabel('I (A)', color='k')

    
def encoderProfile(array, ax):
    ax.plot(array[:,0], array[:,3], 'y')
    ax.set_ylim([0,360])
    
def energyProfile(electrical, potential, force, l):
    power = electrical[:,1]*electrical[:,2]
    energyIn = np.trapz(power, x=electrical[:,0])
    
    jH, mH = maxHeightGet(potential, l)
    energyOut = mH*force[0,1]
    return energyIn, energyOut

massTotal=0
def addMass(array):
    global massTotal
    massTotal+=array[0,1]
    return massTotal
    
    
def iterateThroughTrials(p=0):
    data = np.zeros([100,4])
    efficiency = np.zeros([100,3])
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
                   file = 'loadcell.csv'
                   try:
                       force = np.genfromtxt(directory + file, delimiter=',')
                   except:
                       pass
                   file = 'arduino.csv'
                   try:
                       arduino = np.genfromtxt(directory + file, delimiter=',')
                   except:
                       pass
                   if p is not 0:
                       fig, ax1 = plt.subplots()
                       jH, _ = maxHeightGet(position,length, ax1)#change to ax1
                       ax2 = ax1.twinx()
                       forceProfile(force, ax2)
                       ax3 = ax1.twinx()
                       ax3.spines["right"].set_position(("axes", -0.2))
                       encoderProfile(arduino, ax3)
                       ax4 = ax1.twinx()
                       ax4.spines["right"].set_position(("axes", 1.1))
                       ax5 = ax1.twinx()
                       ax5.spines["right"].set_position(("axes", 1.2))
                       electricalProfile(arduino, ax4, ax5)
                       plt.figure()
                       plt.tight_layout()
                       plt.show()
                       data[i,:] = [width, length, gear_ratio, jH]
                   print(designFolder + '/' + trialFolder)
                   massTotal = addMass(force)
                   #Ein, Eout = energyProfile(arduino, position, force, length)
                   #efficiency[i,:] = [length, gear_ratio, Eout/Ein]
                   print('\n')
                   i += 1
    return data, massTotal/i
    
def plotJumpHeights2(data):
    print(data)
    scaled_z = (data[:,2] - data[:,2].min()) / data[:,2].ptp()
    colors = plt.cm.coolwarm(scaled_z)
    #plt.scatter(x, y, marker='+', edgecolors=colors, s=150, linewidths=4)
    plt.show()
    plt.figure()
    plt.subplot(221)
    plt.ylabel('jump height (m)')
    plt.title("length")
    plt.scatter(data[:,1], data[:,3], marker='o',color=colors)
    plt.xlabel('(cm)')
    plt.subplot(222)
    plt.title("gear ratio")
    plt.scatter(data[:,2], data[:,3], marker='o',color=colors)  
    plt.xlabel('(reduction)')
    plt.tight_layout()
    plt.savefig('height results.png', dpi = 600)
    
def plotJumpHeights1(data):
    print(data)
    scaled_z = (data[:,2] - data[:,2].min()) / data[:,2].ptp()
    colors = plt.cm.coolwarm(scaled_z)
    #plt.scatter(x, y, marker='+', edgecolors=colors, s=150, linewidths=4)
    plt.figure()
    plt.ylabel('jump height (m)')
    plt.title("Jump Height vs. Length and Gear Ratio")
    plt.scatter(data[:,1], data[:,3], marker='o',c=data[:,2], cmap='coolwarm')
    plt.xlabel('leg length (cm)')
    cbar = plt.colorbar()
    cbar.set_label('gear ratio')
    #plt.tight_layout()
    plt.savefig('height results.png', dpi = 600)
    plt.show()
    
def plotJumpHeightsA(data):
    print(data)
    scaled_z = (data[:,2] - data[:,2].min()) / data[:,2].ptp()
    colors = plt.cm.coolwarm(scaled_z)
    plt.figure()
    length = data[:,1]
    ratio = data[:,2]
    height = data[:,3]
    ratios = set(ratio)
    for r in ratios:
        area = np.array([[0,0,0]])
        if r == 0:
            continue
        print(r)
        indecesr = np.where(data[:,2] == r)
        #print(indeces)
        lengths = set(length[indecesr])
        for l in lengths:
            indeces = np.where(((data[:,1:3] == (l,r)).all(axis=1)))
            print('indeces', indeces)
            heights = height[indeces]
            maxHeight = heights.max()
            minHeight = heights.min()
            area = np.append(area,[[l,minHeight,maxHeight]], axis=0)
        area = area[area[:,0].argsort()]
        print(area)
        print(r)
        plt.fill_between(area[:,0],area[:,1],area[:,2], color = plt.cm.coolwarm(r/120.0))
            
            
    plt.ylabel('jump height (m)')
    plt.title("Jump Height vs. Length and Gear Ratio")
    plt.scatter(data[:,1], data[:,3], marker='o',c=data[:,2], cmap='coolwarm')
    plt.xlabel('leg length (cm)')
    cbar = plt.colorbar()
    cbar.set_label('gear ratio')
    plt.tight_layout()
    plt.savefig('height results.png', dpi = 600)
    plt.show()
    
def plotEfficiencies(eff):
    plt.subplot(211)
    plt.plot(eff[:,0], eff[:,2], 'o')
    plt.title("Efficiency vs Length")
    plt.xlabel('(cm)')
    plt.ylabel('efficiency')
    
    plt.subplot(212)
    plt.plot(eff[:,1], eff[:,2], 'o')
    plt.title("Efficiency vs Gear Ratio")
    plt.xlabel('(reduction)')
    plt.tight_layout()
    plt.savefig('efficiency results.png', dpi = 600)
               

#maxHeightGet(position)
#forceProfile(force)


import os

data, massAve = iterateThroughTrials(1)
plotJumpHeightsA(data)
#plotEfficiencies(eff)

print(massAve)

# =============================================================================
# data = np.zeros([100,4])
# i=0
# 
# for entry in os.scandir(root):
#    if not entry.name.startswith('s') and not entry.is_file():
#        designFolder = entry.name
#        words = designFolder.split('_')
#        width = int(words[0])
#        length = int(words[1])
#        gear_ratio = int(words[2])
#        for entry in os.scandir(root + '/' + designFolder):
#            if entry.name.startswith('t') and not entry.is_file():
#                trialFolder = entry.name
#                words = trialFolder.split('l')
#                trial = words[1]
#                directory = root + '/' + designFolder + '/' + trialFolder + '/'
#                file = 'loadcell.csv'
#                try:
#                    force = np.genfromtxt(directory + file, delimiter=',')
#                except:
#                    pass
#                print(designFolder + '/' + trialFolder)
#                forceProfile(force)
#                #data[i,:] = [width, length, gear_ratio, jH]
#                print('\n')
#                i += 1
# =============================================================================
               


