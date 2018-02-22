import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from sklearn import svm
from sklearn.neural_network import MLPClassifier

color=np.array([1,1,1,1,2,2,2,2,3,3,3,3,3,3])
sides=np.array([4,3,1,1,4,4,3,1,4,4,3,3,1,1])
size=np.array([2,2,2,1,2,1,1,1,2,1,2,1,2,1])

training = np.zeros([14,3])

for i in range(14):
    training[i,:] = [color[i],sides[i],size[i]]

labels=[0,0,0,0,1,1,1,1,0,0,0,0,0,0]

testing=np.array([[1,4,1],[1,3,1],[2,3,2],[2,1,2]])

clf=svm.SVC()
model=clf.fit(training,labels)
classification = clf.predict(testing)
print(classification)

fig1 = plt.figure()
ax1=fig1.add_subplot(121, projection='3d')
ax1.scatter([item[0] for item in testing],[item[1] for item in testing],[item[2] for item in testing],c=classification, marker='x')
ax1.scatter([item[0] for item in training],[item[1] for item in training],[item[2] for item in training],c=labels, marker='o')

ax1.set_xlabel('color')
ax1.set_ylabel('sides')
ax1.set_zlabel('size')

clf=MLPClassifier(solver='lbfgs',alpha=1e-5,hidden_layer_sizes=(1000,100), random_state=1)
model=clf.fit(training,labels)
classification=clf.predict(testing)

ax2=fig1.add_subplot(122, projection='3d')
ax2.scatter([item[0] for item in testing],[item[1] for item in testing],[item[2] for item in testing],c=classification, marker='x')
ax2.scatter([item[0] for item in training],[item[1] for item in training],[item[2] for item in training],c=labels, marker='o')

ax2.set_xlabel('color')
ax2.set_ylabel('sides')
ax2.set_zlabel('size')
plt.show()