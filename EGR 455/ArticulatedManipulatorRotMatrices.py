import numpy as np

#angles in degrees
theta1 = 15.0 
theta2 = 30.0
theta3 = 60.0

#convert to rad
theta1 = theta1/180.0*np.pi
theta2 = theta2/180.0*np.pi
theta3 = theta3/180.0*np.pi

# define rotation matrices
R0_1 = np.dot([[1,0,0], [0,0,1], [0,-1,0]], [[np.cos(theta1),0,-np.sin(theta1)], [0,1,0], [np.sin(theta1),0,np.cos(theta1)]])
R1_2 = np.dot([[1,0,0], [0,1,0], [0,0,1]], [[np.cos(theta2),np.sin(theta2),0], [-np.sin(theta2),np.cos(theta2),0], [0,0,1]])
R2_3 = np.dot([[1,0,0], [0,1,0], [0,0,1]], [[np.cos(theta3),np.sin(theta3),0], [-np.sin(theta3),np.cos(theta3),0], [0,0,1]])

#calculate full rotation
R0_2 = np.dot(R0_1, R1_2)
R0_3 = np.dot(R0_2, R2_3)

print(R0_3)
