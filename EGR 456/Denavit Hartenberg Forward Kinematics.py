import numpy as np

#const lengths
a1 = 4.9
a2 = 6.0
a3 = 5.5
a4 = 7.2
a5 = 8.9

#state variables (angles in degrees)
theta1 = 45.0 
theta2 = 45.0
d1 = 1.0
#convert to rad
theta1 = theta1/180.0*np.pi
theta2 = theta2/180.0*np.pi

# define homogenous transformation matrices
H0_1=[[np.cos(theta1),-np.sin(theta1),0, a2*np.cos(theta1)], [np.sin(theta1),np.cos(theta1),0, a2*np.sin(theta1)], [0,0,1, a1], [0,0,0,1]]
H1_2=[[np.cos(theta2),np.sin(theta2),0, a4*np.cos(theta2)], [np.sin(theta2),-np.cos(theta2),0, a4*np.sin(theta2)], [0,0,-1, a3], [0,0,0,1]]
H2_3=[[1,0,0,0],[0,1,0,0],[0,0,1,a5+d1],[0,0,0,1]]

print(np.matrix(H0_1))
print("\n")

H0_2 = np.dot(H0_1,H1_2)
H0_3 = np.dot(H0_2,H2_3)

print(np.matrix(H0_3))
