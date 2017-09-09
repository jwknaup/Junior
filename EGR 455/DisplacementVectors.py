import numpy as np

#lengths
a1 = 1
a2 = 1
a3 = 1
a4 = 1
#angles in degrees
theta1 = 10.0 
theta2 = 70.0
#convert to rad
theta1=theta1/180.0*np.pi
theta2 = theta2/180.0*np.pi

# define rotation matrices
R0_1=[[np.cos(theta1),-np.sin(theta1),0], [np.sin(theta1),np.cos(theta1),0], [0,0,1]]
R1_2=[[np.cos(theta2),-np.sin(theta2),0], [np.sin(theta2),np.cos(theta2),0], [0,0,1]]

#calculate full rotation
R0_2 = np.dot(R0_1, R1_2)
#print(R0_2)

d0_1 = [[a2*np.cos(theta1)],[a2*np.sin(theta1)],[a1]]
d1_2 = [[a4*np.cos(theta2)],[a4*np.sin(theta2)],[a3]]
print(np.matrix(d0_1))
print(np.matrix(d1_2))
