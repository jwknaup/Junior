import numpy as np

#angles in degrees
theta1=-30.0 
theta2 = -60.0
#convert to rad
theta1=theta1/180.0*np.pi
theta2 = theta2/180.0*np.pi

# define rotation matrices
R0_1=[[1,0,0], [0,np.cos(theta1),np.sin(theta1)], [0,-np.sin(theta1),np.cos(theta1)]]
R1_2=[[np.cos(theta2),0,-np.sin(theta2)], [0,1,0], [np.sin(theta2),0,np.cos(theta2)]]

#calculate full rotation
R0_2 = np.dot(R0_1, R1_2)
print(R0_2)
