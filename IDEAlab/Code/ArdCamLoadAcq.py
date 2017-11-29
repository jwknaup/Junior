# -*- coding: utf-8 -*-
"""
Created on Mon Nov 06 20:14:17 2017

@author: Jacob
"""

# -*- coding: utf-8 -*-
"""
Created on Tue Nov 07 12:19:01 2017

@author: Jacob
"""
import matplotlib.pyplot as plt
import numpy as np
import multiprocessing
import serial
import time
import optirx as rx

position = np.zeros([200, 4])    
def cameras(queue):
    time.clock()
    dsock = rx.mkdatasock()
    version = (2, 9, 0, 0)  # NatNet version to use
    time.sleep(0.5)
    for i in range(200):
        data = dsock.recv(rx.MAX_PACKETSIZE)
        packet = rx.unpack(data, version=version)
        if type(packet) is rx.SenderData:
            version = packet.natnet_version
        position[i,0] = time.clock()
        position[i,1:4] = np.asarray(packet.other_markers)[0,:]
    queue.put(position)
        
        

force = np.zeros([150,2])
def loadcell(queue):
    time.clock()
    z = 0;
    lc = serial.Serial()
    lc.baudrate=115200
    lc.port='COM6'
    lc.open()
    time.sleep(0.4)
    for i in range(150):
       lc.write("?\r".encode())
       f = lc.readline()
       t=time.clock()
       force[i,:] = [t, f]
       if (force[i,1]<0.001):
           z+=1
       else:
           z=0
    queue.put(force)
       
VI = np.zeros([100,4])
def arduino(queue):
    time.clock()
    i = 0
    ar = serial.Serial()
    ar.baudrate=115200
    ar.port='COM5'
    ar.open()
    time.sleep(0.5)
    ar.write(55)
    #ar.flush()
    for i in range(100):
        o = ar.readline()
        a = o.split()
        if len(a) < 3:
            continue
        try:
            a0=float(a[0])
        except ValueError:
            continue
        try:
            a1=float(a[1])
        except ValueError:
            continue
        try:
            a2=float(a[2])
        except ValueError:
            continue
        t=time.clock()
        VI[i,:] = [t, a0, a1, a2]   
    ar.close()
    queue.put(VI)
    
if __name__ == '__main__':

    queue = multiprocessing.Queue()
    camProc = multiprocessing.Process(target=cameras, args=((queue),))
    lcProc = multiprocessing.Process(target=loadcell, args=((queue),))
#   reader_p.daemon = True
    ardProc = multiprocessing.Process(target=arduino, args=((queue),))

    _start = time.clock()
    
    ardProc.start()
    
    camProc.start()
    
    lcProc.start()
     
    print("started")
    #lcProc.join()
    VI = queue.get()
    print(1)
    #ardProc.join()
    P = queue.get()
    print(2)
    #camProc.join()
    F = queue.get()
    print("fin")


    

    print("FORCE")
    print(F)
    print("V-I-THETA")
    print(VI)
    print("POSITION x,y,z")
    print(P)
    
    
    np.savetxt('loadcell.csv', F, delimiter=',')
    np.savetxt('arduino.csv', VI, delimiter=',')
    np.savetxt('cameras.csv', P, delimiter=',')

    plt.figure(1)
    plt.subplot(221)
    plt.plot(F[:,0], F[:,1])
    plt.title("Force (N)")
    plt.subplot(222)
    plt.plot(VI[:,0], VI[:,1], 'ro')
    plt.plot(VI[:,0], VI[:,2], 'bs')
    plt.title("V-I")
    plt.legend(['V', 'I (A)'])
    plt.subplot(223)
    plt.plot(VI[:,0], VI[:,3], 'c:')
    plt.title('encoder')
    plt.subplot(224)
    plt.plot(P[:,0], P[:, 2], 'gv')
    plt.title('Height (m)')
    #plt.axis([0,.5, -1, 2])
    plt.show() 

    #print(queue.get())

    lcProc.terminate()
    ardProc.terminate()
    camProc.terminate()

#os.system("pause")
