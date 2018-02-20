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
goal=np.array([[10.0, 10.0]])

xBar = np.append([np.linspace(0,20,21)],[[np.zeros(21)],[np.linspace(0,20,21)],[np.zeros(21)+20]])
yBar = np.append([np.zeros(21)],[[np.linspace(0,20,21)],[np.zeros(21)+20],[np.linspace(0,20,21)]])

bars=[[0,0]]
for i in range(0, np.prod(yBar.shape)):
    bars=np.vstack((bars,[xBar[i],yBar[i]]))
    
potState=[[0,0]]
bars=np.vstack((bars,[[1,8],[2,8],[3,8],[4,8],[5,8],[6,8],[7,8],[8,8]]))

plt.plot(state[0][0],state[0][1], 'ro')
plt.plot(goal[0,0],goal[0,1], 'bo')
plt.plot(bars[:,0],bars[:,1], 'k')
plt.axis([-1,21,-1,21])
plt.draw()

#bars=np.vstack((bars,state))
moves=0
while(1):
    done=0
    bad=1
    #check=0
    check=random.choice([0,1,2,3])
    while not done and bad:
        px=state[0,0]
        py=state[0,1]
        ax=actions[check,0]
        ay=actions[check,1]
        potState[0][0]=px+ax
        potState[0][1]=py+ay
        
        done=(goal==state).all(1).any()
        bad=(bars==potState).all(1).any()
        #check+=1
        check=random.choice([0,1,2,3])
        if check==4 and bad:
           print('stuck')
           break    
    state[0,0]=px+ax
    state[0,1]=py+ay   
    
    #bars=np.vstack((bars,state))
   
    if done:
        print('goal acheived in', moves)
        break
    
    moves+=1
    print('state = ', state)    
    plt.cla()
    plt.plot(state[0][0],state[0][1], 'ro')
    plt.plot(goal[0,0],goal[0,1], 'bo')
    plt.plot(bars[:,0],bars[:,1], 'ko')
    plt.axis([-1,21,-1,21])
    plt.draw()
    plt.pause(0.01)

plt.ioff()
plt.show()