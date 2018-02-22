import numpy as np
import matplotlib.pyplot as plt
import random

plt.figure(10)
plt.ion()

state=np.array([[1.0,1.0]])

up=np.array([0.0,1.0])
down=np.array([0.0,-1.0])
left=np.array([-1.0,0.0])
right=np.array([1.0,0.0])

actions=np.array([up,left,right,down])
goal=np.array([[1.0, 10.0]])

xBar = np.append([np.linspace(0,20,21)],[[np.zeros(21)],[np.linspace(0,20,21)],[np.zeros(21)+20]])
yBar = np.append([np.zeros(21)],[[np.linspace(0,20,21)],[np.zeros(21)+20],[np.linspace(0,20,21)]])

bars=[[0,0]]
for i in range(0, np.prod(yBar.shape)):
    bars=np.vstack((bars,[xBar[i],yBar[i]]))
    
potState=np.array([[0,0]])
bars=np.vstack((bars,[[1,8],[2,8],[3,8],[4,8],[5,8],[5,9],[5,10],[5,11]]))

plt.plot(state[0][0],state[0][1], 'ro')
plt.plot(goal[0,0],goal[0,1], 'bo')
plt.plot(bars[:,0],bars[:,1], 'k')
plt.axis([-1,21,-1,21])
plt.draw()

# dist=np.zeros(4)
score=np.zeros(4)
prev = np.array([[0,0]])
prev=np.vstack((prev,state))
moves=0
while(moves<100):
    done=0
    goal=np.array([[0.1*moves, 10.0]])
    for i in range(4):
        px=state[0,0]
        py=state[0,1]
        ax=actions[i,0]
        ay=actions[i,1]
        potState[0][0]=px+ax
        potState[0][1]=py+ay

        xDist = goal[0,0]-potState[0,0]
        yDist = goal[0,1]-potState[0,1]
        dist = np.sqrt(xDist**2 + yDist**2)

        collision = (([[potState[0,0],potState[0,1]]] == bars).all(axis=1)).any(axis=0)
        #print(int(collision))
        already = (([[potState[0,0],potState[0,1]]] == prev).all(axis=1)).any(axis=0)
        cost=1000*int(collision) + 2*already
        score[i] = cost + dist
        #print(i, score[i])
         
    choice = score.argmin()
    print(choice)
    
    state[0,0]=px+actions[choice,0]
    state[0,1]=py+actions[choice,1]   

    prev=np.vstack((prev,state))
  
    moves+=1
    print('state = ', state)    
    plt.cla()
    plt.plot(state[0][0],state[0][1], 'ro')
    plt.plot(goal[0,0],goal[0,1], 'bo')
    plt.plot(bars[:,0],bars[:,1], 'ko')
    plt.axis([-1,21,-1,21])
    plt.draw()

    done=(goal==state).all(1).any()
    #bars=np.vstack((bars,state))
   
    if done:
        print('goal acheived in', moves)
        break

    plt.pause(0.01)

plt.ioff()
plt.show()

#cool, try making every move have a cost, an no move being an option
#make memory dependent on number of previous times