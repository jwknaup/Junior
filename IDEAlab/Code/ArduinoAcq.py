import matplotlib.pyplot as plt
import numpy as np
import multiprocessing
import serial
import time


VI = np.zeros([100,4])
def arduino(queue):
    time.clock()
    i = 0
    ar = serial.Serial()
    ar.baudrate=115200
    ar.port='COM6'
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
    ardProc = multiprocessing.Process(target=arduino, args=((queue),))

    _start = time.clock()
    
    ardProc.start()

     
    print("started")
    #lcProc.join()
    VI = queue.get()
    print(1)

    print("V-I-THETA")
    print(VI)

    
    np.savetxt('arduino.csv', VI, delimiter=',')
   
    plt.figure(1)
    plt.subplot(211)
    plt.plot(VI[:,0], VI[:,1], 'ro')
    plt.plot(VI[:,0], VI[:,2], 'bs')
    plt.title("V-I")
    plt.legend(['V', 'I (A)'])
    plt.subplot(212)
    plt.plot(VI[:,0], VI[:,3], 'c:')
    plt.title('encoder')
    #plt.axis([0,.5, -1, 2])
    plt.show() 

    #print(queue.get())

    ardProc.terminate()