import numpy as np

#lengths
a1 = 5
a2 = 6
a3 = 5.5
a4 = 5.5
#angles in degrees
theta1 = 45.0 
theta2 = 45.0
#convert to rad
theta1=theta1/180.0*np.pi
theta2 = theta2/180.0*np.pi

# define rotation matrices
R0_1=[[np.cos(theta1),-np.sin(theta1),0], [np.sin(theta1),np.cos(theta1),0], [0,0,1]]
R1_2=[[np.cos(theta2),-np.sin(theta2),0], [np.sin(theta2),np.cos(theta2),0], [0,0,1]]

#calculate full rotation
R0_2 = np.dot(R0_1, R1_2)

#print(np.matrix(R0_1))
print("\n")

d0_1 = [[a2*np.cos(theta1)],[a2*np.sin(theta1)],[a1]]
d1_2 = [[a4*np.cos(theta2)],[a4*np.sin(theta2)],[a3]]

#print(np.matrix(d0_1))
print("\n")

H0_1 = np.concatenate((R0_1,d0_1),1)
H0_1 = np.concatenate((H0_1,[[0,0,0,1]]),0)

#print(np.matrix(H0_1))
print("\n")

H1_2 = np.concatenate((R1_2,d1_2),1)
H1_2 = np.concatenate((H1_2,[[0,0,0,1]]))

H0_2 = np.dot(H0_1,H1_2)

print(np.matrix(H0_2))
