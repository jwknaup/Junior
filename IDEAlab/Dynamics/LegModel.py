# -*- coding: utf-8 -*-
"""
Written by Daniel M. Aukes
Email: danaukes<at>gmail.com
Please see LICENSE for full license.
"""

import pynamics
from pynamics.frame import Frame
from pynamics.variable_types import Differentiable,Constant
from pynamics.system import System
from pynamics.body import Body
from pynamics.dyadic import Dyadic
from pynamics.output import Output
from pynamics.particle import Particle
import pynamics.integration

#import sympy
import numpy
#import scipy.integrate
import matplotlib.pyplot as plt
plt.ion()
from sympy import pi
system = System()

top_length = 0.01333
leg_length = 0.12
top_mass = 0.030372
leg_mass = 0.095*10**-3*leg_length*100.0
leg_width = 0.01
leg_thickness = .002
gear_ratio = 75.0
Tmax = 0.2118/100.0*gear_ratio
wMax = 320.0/60.0*2.0*3.14159*100/gear_ratio

####VARIOUS DESIGN CONSTANTS#####
#define length constants
# top, then each leg segment
lO = Constant(top_length,'lO',system)
lA = Constant(leg_length-top_length/2.0,'lA',system)
lB = Constant(leg_length,'lB',system)
lC = Constant(leg_length-top_length/2.0,'lC',system)
lD = Constant(leg_length,'lD',system)

#define mass cnstants for each segment
mO = Constant(top_mass,'mO',system)
mA = Constant(leg_mass,'mA',system)
mB = Constant(leg_mass,'mB',system)
mC = Constant(leg_mass,'mC',system)
mD = Constant(leg_mass,'mD',system)

#define inertia constants
I_xx = Constant(leg_mass/12.0*(leg_thickness*leg_thickness + leg_width*leg_width),'I_xx',system)
I_yy = Constant(leg_mass/12.0*(leg_length*leg_length + leg_width*leg_width),'I_yy',system)
I_zz = Constant(leg_mass/12.0*(leg_length*leg_length + leg_thickness*leg_thickness),'I_zz',system)

#define misc constants
g = Constant(9.81,'g',system)
b = Constant(1e0,'b',system)
k = Constant(1e3,'k',system)

###INTEGRATION INTERVAL####
tinitial = 0
tfinal = 2
tstep = .5 ##0.01!!!
t = numpy.r_[tinitial:tfinal:tstep]

##give joints stiffness -- just for initial conditions
preload1 = Constant(0*pi/180,'preload1',system)
preload2 = Constant(0*pi/180,'preload2',system)
preload3 = Constant(-180*pi/180,'preload3',system)
preload4 = Constant(0*pi/180,'preload4',system)
preload5 = Constant(180*pi/180,'preload5',system)

#state variables for the whole device
x,x_d,x_dd = Differentiable('x',system)
y,y_d,y_dd = Differentiable('y',system)
qO,qO_d,qO_dd = Differentiable('qO',system)
qA,qA_d,qA_dd = Differentiable('qA',system)
qB,qB_d,qB_dd = Differentiable('qB',system)
qC,qC_d,qC_dd = Differentiable('qC',system)
qD,qD_d,qD_dd = Differentiable('qD',system)

#initial joint positions & system location 
initialvalues = {}
initialvalues[x]=0
initialvalues[x_d]=0
initialvalues[y]=0.20
initialvalues[y_d]=0
initialvalues[qO]=0*pi/180
initialvalues[qO_d]=0*pi/180
initialvalues[qA]=-10*pi/180
initialvalues[qA_d]=0*pi/180
initialvalues[qB]=-170*pi/180
initialvalues[qB_d]=0*pi/180
initialvalues[qC]=-170*pi/180
initialvalues[qC_d]=0*pi/180
initialvalues[qD]=-10*pi/180
initialvalues[qD_d]=0*pi/180

# =============================================================================
# A & B are right side 
# C & D are left side
# A & C are upper
# =============================================================================

#pynamics stuff
statevariables = system.get_state_variables()
ini = [initialvalues[item] for item in statevariables]

#######define frames########
N = Frame('N')
O = Frame('O')
A = Frame('A')
B = Frame('B')
C = Frame('C')
D = Frame('D')

system.set_newtonian(N)
O.rotate_fixed_axis_directed(N,[0,0,1],qO,system)
A.rotate_fixed_axis_directed(N,[0,0,1],qA,system)
B.rotate_fixed_axis_directed(N,[0,0,1],qB,system)
C.rotate_fixed_axis_directed(N,[0,0,1],qC,system)
D.rotate_fixed_axis_directed(N,[0,0,1],qD,system)

####WRITE KINEMATIC EQUATIONS#####
pOcm=x*N.x+y*N.y #position of top
vOcm = pOcm.time_derivative(N, system)
pOA = pOcm+lO/2*O.x #right edge of top
pOC = pOcm-lO/2*O.x #left edge of top
pAB = pOA+lA*A.x #position of right joint
vAB = pAB.time_derivative(N,system) #velocity of right joint


pBtip = pAB + lB*B.x #position of bottom from right side
vBtip = pBtip.time_derivative(N,system) #velocity of bottom

pCD = pOC + lC*C.x #positon of left joint
vCD = pCD.time_derivative(N,system) # velocity of left joint
pDtip = pCD + lD*D.x #position of bottom from left side
vDtip = pDtip.time_derivative(N,system) #velocity of bottom from left side

#positions of centers of mass of members
pAcm=pOA+lA/2*A.x
pBcm=pAB+lB/2*B.x
pCcm=pOC+lC/2*C.x
pDcm=pCD+lD/2*D.x

#get relative angular velocities
wOA = O.getw_(A)
wAB = A.getw_(B)
wOC = O.getw_(C)
wCD = C.getw_(D)
wBD = B.getw_(D)

#####DEFINE BODIES#######
IO = Dyadic.build(O,top_mass/12.0*.06**2,top_mass/12.0*.06**2,top_mass/12.0*.06**2)
IA = Dyadic.build(A,I_xx,I_yy,I_zz)
IB = Dyadic.build(B,I_xx,I_yy,I_zz)
IC = Dyadic.build(C,I_xx,I_yy,I_zz)
ID = Dyadic.build(D,I_xx,I_yy,I_zz)

BodyO = Body('BodyO',O,pOcm,mO,IO,system)
BodyA = Body('BodyA',A,pAcm,mA,IA,system) #right thigh
BodyB = Body('BodyB',B,pBcm,mB,IB,system) #right calf
BodyC = Body('BodyC',C,pCcm,mC,IC,system) #left thigh
BodyD = Body('BodyD',D,pDcm,mD,ID,system) #left calf

#ParticleO = Particle(pOcm,mO,'ParticleO',system)
#ParticleA = Particle(pAcm,mA,'ParticleA',system)
#ParticleB = Particle(pBcm,mB,'ParticleB',system)
#ParticleC = Particle(pCcm,mC,'ParticleC',system)
#ParticleD = Particle(pDcm,mD,'ParticleD',system)

#########FORCES#FORCES#FORCES###################

#damper for each joint
damper1 = system.addforce(-b*wOA,wOA) 
damper2 = system.addforce(-b*wAB,wAB)
damper3 = system.addforce(-b*wOC,wOC)
damper4 = system.addforce(-b*wCD,wCD)
damper5 = system.addforce(-b*wBD,wBD)

#spring constraints for bottom of leg
v = pBtip-pDtip
l = (v.dot(v))**.5
n = 1/l*v
bottomSpring1, _ = system.add_spring_force1(1e7,l*n,vBtip)
bottomSpring2, _ = system.add_spring_force1(1e7,-l*n,vDtip)
bottomDamper1 = system.addforce(-b*(vBtip-vDtip),vBtip)
bottomDamper2 = system.addforce(b*(vBtip-vDtip),vDtip)

#add spring forces to each joint
spring1, _ = system.add_spring_force1(k,(qA-qO-preload1)*N.z,wOA)
spring2, _ = system.add_spring_force1(k,(qB-qA-preload2)*N.z,wAB)
spring3, _ = system.add_spring_force1(k,(qC-qO-preload3)*N.z,wOC)
spring4, _ = system.add_spring_force1(k,(qD-qC-preload4)*N.z,wCD)
spring5, _ = system.add_spring_force1(k,(qD-qB-preload5)*N.z,wBD)

system.addforcegravity(-g*N.y)

#########CONSTRAINTS#########
#hold the leg in the air
eq = []
eq.append(pOcm.dot(N.y)-initialvalues[y])
eq.append(pOcm.dot(N.x)-initialvalues[x])
eq.append(qO-initialvalues[qO])

eq_d= [system.derivative(item) for item in eq]
eq_dd= [system.derivative(item) for item in eq_d]

#######SOLVING TIP CONSTRAINTS#########
pynamics.tic()
print('solving dynamics...')
f,ma = system.getdynamics()
print('creating second order function...')
func1 = system.state_space_post_invert2(f,ma,eq_dd,eq_d,eq,constants = system.constant_values)
print('integrating...')
states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e2,'beta':1e1},))
pynamics.toc()
print('calculating outputs..')

####PLOTTING####
KE = system.get_KE()
PE = system.getPEGravity(0*N.x) - system.getPESprings()


energy = Output([KE-PE])
energy.calc(states)
energy.plot_time()


points = [pDtip,pCD,pOC,pOA,pAB,pBtip]
points = [item2 for item in points for item2 in [item.dot(N.x),item.dot(N.y)]]
points = Output(points)
y = points.calc(states)
y = y.reshape((-1,6,2))
plt.figure()
plt.title('leg constraint solving')
for item in y[::60]:
    plt.plot(*(item.T))

print("!!!!!!finished 1!!!!!!!!!!!!!")
#########2#2#2#2#2#2#2###################################
#remove forces to bring tips together
system.forces.remove(bottomDamper1)
system.forces.remove(bottomDamper2)
system.forces.remove(bottomSpring1)
system.forces.remove(bottomSpring2)

#ground normal force
stretch = -pBtip.dot(N.y)
stretch_s = (stretch+abs(stretch))
on = stretch_s/(2*stretch+1e-10)
groundS, _ = system.add_spring_force1(1e4,-stretch_s*N.y,vBtip)
groundD = system.addforce(-1e2*vBtip*on,vBtip)

#constrain tips together
#constrain rotation and x displacement
eq2 = []
eq2.append((pBtip-pDtip).dot(N.x))
eq2.append((pBtip-pDtip).dot(N.y))
eq2.append(pOcm.dot(N.x)-initialvalues[x])
eq2.append(qO-initialvalues[qO])

eq2_d= [system.derivative(item) for item in eq2]
eq2_dd= [system.derivative(item) for item in eq2_d]

ini = states[-1]
ini[2] = 0
ini[7:] = 0
#ini[7] = 10
ini = list(ini)

tinitial = 0
tfinal = 2
tstep = 0.1 ## was 1/30

######SOLVE TO PLACE IT ON THE GROUND#############
f,ma = system.getdynamics()
func1 = system.state_space_post_invert2(f,ma,eq2_dd,eq2_d,eq2,constants = system.constant_values)
states2=pynamics.integration.integrate_odeint(func1,ini,numpy.r_[tinitial:tfinal:tstep],hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e3,'beta':1e1},))
y = points.calc(states2)
y = y.reshape((-1,6,2))
plt.figure()
for item in y[::25]:
    plt.plot(*(item.T))
plt.axis('equal')

energy = Output([KE-PE])
energy.calc(states2)
energy.plot_time()

tip = Output([pBtip.dot(N.y),stretch])
tip.calc(states2)
tip.plot_time()

print("!!!!!!finished 2!!!!!!!!!!!!!")


########3#3#3#3#3#3#3#3#################################

#add force to compress the top #1.42 cm
contraction, _ = system.add_spring_force1(1.0e3,(pOcm.dot(N.y) - pBtip.dot(N.y) - 0.0142)*N.y, vOcm)
contractionD = system.addforce(-1e1*vOcm,vOcm)

#remove joint stiffness
system.forces.remove(spring1)
system.forces.remove(spring2)
system.forces.remove(spring3)
system.forces.remove(spring4)
system.forces.remove(spring5)

#temporarilly remove ground reaction force
system.forces.remove(groundS)
system.forces.remove(groundD)

#constrain tips, rotation, x displacement, and tip to ground
eq3 = []
eq3.append((pBtip-pDtip).dot(N.x))
eq3.append((pBtip-pDtip).dot(N.y))
eq3.append(pOcm.dot(N.x)-initialvalues[x])
eq3.append(qO-initialvalues[qO])
eq3.append(pBtip.dot(N.y))

eq3_d= [system.derivative(item) for item in eq3]
eq3_dd= [system.derivative(item) for item in eq3_d]

ini = states2[-1]
ini[2] = 0
ini[7:] = 0
#ini[7] = 10
ini = list(ini)

tinitial = 0
tfinal = 2
tstep = 0.1 ## was 1/30!!!!

###########SOLVE FOR COMPRESSION#########
f,ma = system.getdynamics()
func1 = system.state_space_post_invert2(f,ma,eq3_dd,eq3_d,eq3,constants = system.constant_values)
states3=pynamics.integration.integrate_odeint(func1,ini,numpy.r_[tinitial:tfinal:tstep],hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e3,'beta':1e1},))
y = points.calc(states3)
y = y.reshape((-1,6,2))
plt.figure()
for item in y[::25]:
    plt.plot(*(item.T))
plt.axis('equal')

energy = Output([KE-PE])
energy.calc(states3)
energy.plot_time()

tip = Output([pBtip.dot(N.y),stretch])
tip.calc(states3)
tip.plot_time()
print("!!!!!!finished 3!!!!!!!!!!!!!")


#######4#4#4#4#4#4#4#4#4#4#4#4#4#########################

#remove compression force
system.forces.remove(contraction)
system.forces.remove(contractionD)

system.forces.remove(damper1)
system.forces.remove(damper2)
system.forces.remove(damper3)
system.forces.remove(damper4)
system.forces.remove(damper5)


#torque = Tmax - Tmax/wMax*w

#add torque
system.addforce((Tmax - Tmax/wMax*abs(wOA.dot(N.z)))*-N.z, wOA)
system.addforce((Tmax - Tmax/wMax*abs(wOA.dot(N.z)))*N.z, wOC)

#leg collision force
stretch = pCD.dot(N.x) - pAB.dot(N.x)
stretch_s = (stretch+abs(stretch))
on = stretch_s/(2*stretch+1e-8)
legColcS, legColaS, _ = system.add_spring_force2(1e1,stretch_s*N.x,vCD, -vAB)
legColcD = system.addforce(-1e2*wCD*on,wCD)
legColaD = system.addforce(-1e2*wAB*on,wAB)

#ground normal force
stretch = -pBtip.dot(N.y)
stretch_s = (stretch+abs(stretch))
on = stretch_s/(2*stretch+1e-10)
groundS, _ = system.add_spring_force1(1e4,-stretch_s*N.y,vBtip)
groundD = system.addforce(-1e2*vBtip*on,vBtip)

#only constrain tip
eq4 = []
eq4.append((pBtip-pDtip).dot(N.x))
eq4.append((pBtip-pDtip).dot(N.y))

eq4_d= [system.derivative(item) for item in eq4]
eq4_dd= [system.derivative(item) for item in eq4_d]

ini = states3[-1]
ini[2] = 0
ini[7:] = 0
#ini[7] = 10
ini = list(ini)

tinitial = 0
tfinal = 1.2
tstep = 0.01 ## was 1/30

######SOLVE FOR JUMPING#######
f,ma = system.getdynamics()
func1 = system.state_space_post_invert2(f,ma,eq4_dd,eq4_d,eq4,constants = system.constant_values)
states4=pynamics.integration.integrate_odeint(func1,ini,numpy.r_[tinitial:tfinal:tstep],hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e3,'beta':1e1},))
y = points.calc(states4)
y = y.reshape((-1,6,2))
plt.figure()
for item in y[::25]:
    plt.plot(*(item.T))
plt.axis('equal')

energy = Output([KE-PE])
energy.calc(states4)
energy.plot_time()

tip = Output([pBtip.dot(N.y),stretch])
tip.calc(states4)
tip.plot_time()
plt.title('tip')
print("!!!!!!finished 4!!!!!!!!!!!!!")


#########################################################


import os
import idealab_tools.makemovie
idealab_tools.makemovie.clear_folder()
folder = idealab_tools.makemovie.prep_folder()
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax.axis('tight')

for ii,item in enumerate(y):
    [item.remove() for item in ax.lines]
    plt.plot(*(item.T),'ro-')
    ax.set_xlim((y[:,:,0].min(),y[:,:,0].max()))
    ax.set_ylim((y[:,:,1].min(),y[:,:,1].max()))
    plt.savefig(os.path.join(folder,'{0:04d}.png'.format(ii)), dpi = 100)

def make_gif(output_filename='render.gif',images_folder='render',fps=30,output_folder='.',image_name_format='*.png'):
    import imageio
    import glob
    
    if os.path.exists(output_folder+'/'+output_filename):
        os.remove(output_folder+'/'+output_filename)

    filenames = glob.glob(os.path.join(images_folder,image_name_format))
    images = []
    for filename in filenames:
        images.append(imageio.imread(filename))
    imageio.mimsave(os.path.join(output_folder,output_filename), images,duration=1/fps ) 
plt.ion()
make_gif()
#idealab_tools.makemovie.render(movie_folder="C:/Users/Jacob/Documents/Junior/IDEAlab/Dynamics")
#idealab_tools.makemovie.clear_folder()