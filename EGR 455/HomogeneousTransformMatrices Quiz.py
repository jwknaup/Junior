import numpy as np

#lengths
a1 = 1
a2 = 2
a3 = 3

#angles in degrees
theta1 = 15.0 
d2 = 1.0
#convert to rad
theta1=theta1/180.0*np.pi

# define rotation matrices
R0_1=[[-np.cos(theta1),0,-np.sin(theta1)],
      [-np.sin(theta1),0,np.cos(theta1)],
      [0,1,0]]
R1_2=[[1,0,0], [0,1,0], [0,0,1]]

#calculate full rotation
R0_2 = np.dot(R0_1, R1_2)

#print(np.matrix(R0_1))
print("\n")

d0_1 = [[0],[0],[a1]]
d1_2 = [[0],[0],[a2+a3+d2]]

#print(np.matrix(d0_1))
print("\n")

H0_1 = np.concatenate((R0_1,d0_1),1)
H0_1 = np.concatenate((H0_1,[[0,0,0,1]]),0)

#print(np.matrix(H0_1))
print("\n")

H1_2 = np.concatenate((R1_2,d1_2),1)
H1_2 = np.concatenate((H1_2,[[0,0,0,1]]),0)

H0_2 = np.dot(H0_1,H1_2)

print(np.matrix(H0_2))
