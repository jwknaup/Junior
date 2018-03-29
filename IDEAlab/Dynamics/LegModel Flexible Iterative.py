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
from sympy import sin
from sympy import pi
import os    

system = System()

top_length = 0.01333
leg_length = 0.01
top_mass = 0.03022
leg_mass = 0.095*(10**-3)*leg_length*100.0
clamp_mass = 2.1*10**-3
leg_width = 0.01
leg_thickness = .0007
E = 5122768405
areaI = leg_width * (leg_thickness**3) / 12.0;
flexk = .00265;
# =============================================================================
gear_ratio = 75.0
# Tmax = 0.1554/75.0*gear_ratio
# wMax = 400.0/60.0*2.0*3.14159*75.0/gear_ratio
# =============================================================================

debugging = 1

####VARIOUS DESIGN CONSTANTS#####
#gear_ratio = Constant(75.0, 'gear_ratio',system)
Tmax = Constant(0.1554/75.0*gear_ratio, 'Tmax', system)
wMax = Constant(400.0/60.0*2.0*3.14159*75.0/gear_ratio, 'wMax', system)
#define length constants
# top, then each leg segment
lO = Constant(top_length,'lO',system)
lA = Constant((leg_length-top_length/2.0),'lA',system)
lA2 = Constant((leg_length-top_length/2.0),'lA2',system)
lB = Constant(leg_length,'lB',system)
lC = Constant((leg_length-top_length/2.0),'lC',system)
lC2 = Constant((leg_length-top_length/2.0),'lC2',system)
lD = Constant(leg_length,'lD',system)

#define mass cnstants for each segment
mO = Constant(top_mass,'mO',system)
mA = Constant(leg_mass/2.0+clamp_mass,'mA',system)
mA2 = Constant(leg_mass/2.0,'mA2',system)
mB = Constant(leg_mass,'mB',system)
mC = Constant(leg_mass/2.0+clamp_mass,'mC',system)
mC2 = Constant(leg_mass/2.0,'mC2',system)
mD = Constant(leg_mass,'mD',system)

#define inertia constants
I_xx = Constant(leg_mass/12.0*(leg_thickness*leg_thickness + leg_width*leg_width),'I_xx',system)
I_yy = Constant(leg_mass/12.0*(leg_length*leg_length + leg_width*leg_width),'I_yy',system)
I_zz = Constant(leg_mass/12.0*(leg_length*leg_length + leg_thickness*leg_thickness),'I_zz',system)
I_xx2 = Constant(0.5 * leg_mass/12.0*(leg_thickness**2 + leg_width**2),'I_xx2',system)
I_yy2 = Constant(0.5*leg_mass/12.0*(leg_length/2.0*leg_length/2.0 + leg_width*leg_width),'I_yy2',system)
I_zz2 = Constant(0.5*leg_mass/12.0*(leg_length/2.0*leg_length/2.0 + leg_thickness*leg_thickness),'I_zz2',system)
I_xxT = Constant((0.5*leg_mass + clamp_mass)/12.0*(leg_thickness**2 + leg_width**2),'I_xxT',system)
I_yyT = Constant((0.5*leg_mass + clamp_mass)/12.0*(leg_length/2.0*leg_length/2.0 + leg_width*leg_width),'I_yyT',system)
I_zzT = Constant((0.5*leg_mass + clamp_mass)/12.0*(leg_length/2.0*leg_length/2.0 + leg_thickness*leg_thickness),'I_zzT',system)

#define misc constants
g = Constant(9.81,'g',system)
b = Constant(1e-1,'b',system)
k = Constant(1e-1,'k',system)

spring_constant = Constant(1e1, 'spring_constant',system)

###INTEGRATION INTERVAL####
# =============================================================================
# tinitial = 0
# tfinal = 2
# tstep = .5 ##0.01!!!
# t = numpy.r_[tinitial:tfinal:tstep]
# =============================================================================

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
qA2,qA2_d,qA2_dd = Differentiable('qA2',system)
qB,qB_d,qB_dd = Differentiable('qB',system)
qC,qC_d,qC_dd = Differentiable('qC',system)
qC2,qC2_d,qC2_dd = Differentiable('qC2',system)
qD,qD_d,qD_dd = Differentiable('qD',system)

#initial joint positions & system location 
initialvalues = {}
initialvalues[x]=0
initialvalues[x_d]=0
initialvalues[y]=0.60
initialvalues[y_d]=0
initialvalues[qO]=0*pi/180
initialvalues[qO_d]=0*pi/180
initialvalues[qA]=-10*pi/180
initialvalues[qA_d]=0*pi/180
initialvalues[qA2]=-5*pi/180
initialvalues[qA2_d]=0*pi/180
initialvalues[qB]=-170*pi/180
initialvalues[qB_d]=0*pi/180
initialvalues[qC]=-170*pi/180
initialvalues[qC_d]=0*pi/180
initialvalues[qC2]=-175*pi/180
initialvalues[qC2_d]=0*pi/180
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
A2 = Frame('A2')
B = Frame('B')
C = Frame('C')
C2 = Frame('C2')
D = Frame('D')

system.set_newtonian(N)
O.rotate_fixed_axis_directed(N,[0,0,1],qO,system)
A.rotate_fixed_axis_directed(N,[0,0,1],qA,system)
A2.rotate_fixed_axis_directed(N,[0,0,1],qA2,system)
B.rotate_fixed_axis_directed(N,[0,0,1],qB,system)
C.rotate_fixed_axis_directed(N,[0,0,1],qC,system)
C2.rotate_fixed_axis_directed(N,[0,0,1],qC2,system)
D.rotate_fixed_axis_directed(N,[0,0,1],qD,system)

####WRITE KINEMATIC EQUATIONS#####
pOcm=x*N.x+y*N.y #position of top
vOcm = pOcm.time_derivative(N, system)
pOA = pOcm+lO/2.0*O.x #right edge of top
pOC = pOcm-lO/2.0*O.x #left edge of top
pAA2 = pOA+lA*A.x #position of right joint
vAA2 = pAA2.time_derivative(N,system)
pAB = pAA2+lA2*A2.x
vAB = pAB.time_derivative(N,system) #velocity of right joint


pBtip = pAB + lB*B.x #position of bottom from right side
vBtip = pBtip.time_derivative(N,system) #velocity of bottom

pCC2 = pOC + lC*C.x
vCC2 = pCC2.time_derivative(N,system)
pCD = pCC2 + lC2*C2.x #positon of left joint
vCD = pCD.time_derivative(N,system) # velocity of left joint
pDtip = pCD + lD*D.x #position of bottom from left side
vDtip = pDtip.time_derivative(N,system) #velocity of bottom from left side

#positions of centers of mass of members
pAcm=pOA+lA/2.0*A.x
pA2cm = pAA2 + lA2/2.0*A2.x
pBcm=pAB+lB/2.0*B.x
pCcm=pOC+lC/2.0*C.x
pC2cm = pCC2 + lC2/2.0*C2.x
pDcm=pCD+lD/2.0*D.x

#get relative angular velocities
wOA = O.getw_(A)
wAA2 = A.getw_(A2)
wAB = A2.getw_(B)
wOC = O.getw_(C)
wCC2 = C.getw_(C2)
wCD = C2.getw_(D)
wBD = B.getw_(D)

#####DEFINE BODIES#######
IO = Dyadic.build(O,top_mass/12.0*.06**2,top_mass/12.0*.06**2,top_mass/12.0*.06**2)
IA = Dyadic.build(A,I_xxT,I_yyT,I_zzT)
IA2 = Dyadic.build(A2,I_xx2,I_yy2,I_zz2)
IB = Dyadic.build(B,I_xx,I_yy,I_zz)
IC = Dyadic.build(C,I_xxT,I_yyT,I_zzT)
IC2 = Dyadic.build(C2,I_xx2,I_yy2,I_zz2)
ID = Dyadic.build(D,I_xx,I_yy,I_zz)

BodyO = Body('BodyO',O,pOcm,mO,IO,system)
BodyA = Body('BodyA',A,pAcm,mA,IA,system) #right thigh
BodyA2 = Body('BodyA2',A2,pA2cm,mA,IA2,system)
BodyB = Body('BodyB',B,pBcm,mB,IB,system) #right calf
BodyC = Body('BodyC',C,pCcm,mC,IC,system) #left thigh
BodyC2 = Body('BodyC2',C2,pC2cm,mC,IC2,system)
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
bottomSpring1, _ = system.add_spring_force1(1e5,l*n,vBtip)
bottomSpring2, _ = system.add_spring_force1(1e5,-l*n,vDtip)
bottomDamper1 = system.addforce(-b*100*(vBtip-vDtip),vBtip)
bottomDamper2 = system.addforce(b*100*(vBtip-vDtip),vDtip)

#add spring forces to each joint
spring1, _ = system.add_spring_force1(k*10**-2,(qA-qO-preload1)*N.z,wOA)
spring2, _ = system.add_spring_force1(k*10**-2,(qB-qA2-preload2)*N.z,wAB)
spring3, _ = system.add_spring_force1(k*10**-2,(qC-qO-preload3)*N.z,wOC)
spring4, _ = system.add_spring_force1(k*10**-2,(qD-qC2-preload4)*N.z,wCD)
spring5, _ = system.add_spring_force1(k*10**-2,(qD-qB-preload5)*N.z,wBD)

leftFlexSpring, _ = system.add_spring_force1(spring_constant,lA2/2.0*sin(qA2-qA)*A2.y, vAB)
rightFlexSpring, _ = system.add_spring_force1(spring_constant,lC2/2.0*sin(qC2-qC)*C2.y, vCD)

leftFlexDamper = system.addforce(-b*10**-1*wAA2,wAA2)
rightFlexDamper = system.addforce(-b*10**-1*wCC2,wCC2)

system.addforcegravity(-g*N.y)

#########CONSTRAINTS#########
#hold the leg in the air
eq = []
eq.append(pOcm.dot(N.y)-initialvalues[y])
eq.append(pOcm.dot(N.x)-initialvalues[x])
eq.append(qO-initialvalues[qO])
#eq.append(qA-qA2)
#eq.append(qC-qC2)

eq_d= [system.derivative(item) for item in eq]
eq_dd= [system.derivative(item) for item in eq_d]

#######SOLVING TIP CONSTRAINTS#########
pynamics.tic()
print('solving dynamics...')
f,ma = system.getdynamics()
print('creating second order function...')
func1 = system.state_space_post_invert2(f,ma,eq_dd,eq_d,eq,constants = {})
print('integrating...')
#states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e2,'beta':1e1},))
pynamics.toc()
print('calculating outputs..')

####PLOTTING####
KE = system.get_KE()
PE = system.getPEGravity(0*N.x) - system.getPESprings()

# =============================================================================
# energy = Output([KE-PE])
# energy.calc(states)
# energy.plot_time()
# plt.title('energy')
# =============================================================================



print("!!!!!!finished 1!!!!!!!!!!!!!")




#########2#2#2#2#2#2#2###################################
#remove forces to bring tips together
system.forces.remove(bottomDamper1)
system.forces.remove(bottomDamper2)
system.forces.remove(bottomSpring1)
system.forces.remove(bottomSpring2)

#ground normal force
stretch = -pBtip.dot(N.y)
stretchDot = vBtip.dot(N.y)
stretch_s = (stretch+abs(stretch))
stretchDot_s = (stretchDot-abs(stretchDot))
on = stretch_s/(2*stretch+1e-10)
onDot = stretchDot_s/(2*stretchDot+1e-10)
groundS, _ = system.add_spring_force1(1e3,-stretch_s*N.y,vBtip)
groundD = system.addforce(-1e4*vBtip*onDot*on,vBtip)

#constrain tips together
#constrain rotation and x displacement
eq2 = []
eq2.append((pBtip-pDtip).dot(N.x))
eq2.append((pBtip-pDtip).dot(N.y))
eq2.append(pOcm.dot(N.x)-initialvalues[x])
eq2.append(qO-initialvalues[qO])
#eq2.append(qA-qA2)
#eq2.append(qC-qC2)

eq2_d= [system.derivative(item) for item in eq2]
eq2_dd= [system.derivative(item) for item in eq2_d]

# =============================================================================
# ini = states[-1]
# ini[2] = 0
# ini[7:] = 0
# #ini[7] = 10
# ini = list(ini)
# 
# tinitial = 0
# tfinal = 2
# tstep = 0.1 ## was 1/30
# =============================================================================

######SOLVE TO PLACE IT ON THE GROUND#############
f,ma = system.getdynamics()
func2 = system.state_space_post_invert2(f,ma,eq2_dd,eq2_d,eq2,constants = {})
#states2=pynamics.integration.integrate_odeint(func2,ini,numpy.r_[tinitial:tfinal:tstep],hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e3,'beta':1e1},))

# =============================================================================
# y = points.calc(states2)
# y = y.reshape((-1,6,2))
# plt.figure()
# for item in y[::25]:
#     plt.plot(*(item.T))
# plt.axis('equal')
# =============================================================================

energy = Output([KE-PE])
# =============================================================================
# energy.calc(states2)
# energy.plot_time()
#plt.title('energy of falling to ground')
# =============================================================================

tip = Output([pBtip.dot(N.y),stretch])
# =============================================================================
# tip.calc(states2)
# tip.plot_time()
#plt.title('position as falling to gnd')
# =============================================================================

print("!!!!!!finished 2!!!!!!!!!!!!!")


########3#3#3#3#3#3#3#3#################################

#add force to compress the top #1.42 cm
contraction, _ = system.add_spring_force1(k*(10**3),(pOcm.dot(N.y) - pBtip.dot(N.y) - 0.0142)*N.y, vOcm)
contractionD = system.addforce(-b*(10**-3)*vOcm,vOcm)

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
#eq3.append(qA-qA2)
#eq3.append(qC-qC2)

eq3_d= [system.derivative(item) for item in eq3]
eq3_dd= [system.derivative(item) for item in eq3_d]

# =============================================================================
# ini = states2[-1]
# ini[2] = 0
# ini[7:] = 0
# #ini[7] = 10
# ini = list(ini)
# 
# tinitial = 0
# tfinal = 2
# tstep = 0.1 ## was 1/30!!!!
# =============================================================================

###########SOLVE FOR COMPRESSION#########
f,ma = system.getdynamics()
func3 = system.state_space_post_invert2(f,ma,eq3_dd,eq3_d,eq3,constants = {})
#states3=pynamics.integration.integrate_odeint(func3,ini,numpy.r_[tinitial:tfinal:tstep],hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e3,'beta':1e1},))
# =============================================================================
# y = points.calc(states3)
# y = y.reshape((-1,6,2))
# plt.figure()
# for item in y[::25]:
#     plt.plot(*(item.T))
# plt.axis('equal')
# plt.title('show pre? compressed')
# =============================================================================

energy = Output([KE-PE])
# =============================================================================
# energy.calc(states3)
# energy.plot_time()
# plt.title('energy as compressed')
# =============================================================================

top = Output([pOcm.dot(N.y)])
# =============================================================================
# top.calc(states3)
# top.plot_time()
# plt.title('position as compressed')
# =============================================================================
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

stretch = pCC2.dot(N.x) - pAA2.dot(N.x)
stretch_s = (stretch+abs(stretch))
on = stretch_s/(2*stretch+1e-8)
legColc2S, legCola2S, _ = system.add_spring_force2(1e1,stretch_s*N.x,vCC2, -vAA2)
legColc2D = system.addforce(-1e2*wOC*on,wOC)
legCola2D = system.addforce(-1e2*wOA*on,wOA)

#ground normal force
stretch = -pBtip.dot(N.y)
stretchDot = vBtip.dot(N.y)
stretch_s = (stretch+abs(stretch))
stretchDot_s = (stretchDot-abs(stretchDot))
on = stretch_s/(2*stretch+1e-10)
onDot = stretchDot_s/(2*stretchDot+1e-10)
groundS, _ = system.add_spring_force1(1e3,-stretch_s*N.y,vBtip)
groundD = system.addforce(-1e4*vBtip*onDot*on,vBtip)

#only constrain tip
eq4 = []
eq4.append((pBtip-pDtip).dot(N.x))
eq4.append((pBtip-pDtip).dot(N.y))
#eq4.append(qA-qA2)
#eq4.append(qC-qC2)

eq4_d= [system.derivative(item) for item in eq4]
eq4_dd= [system.derivative(item) for item in eq4_d]

# =============================================================================
# ini = states3[-1]
# ini[2] = 0
# ini[7:] = 0
# #ini[7] = 10
# ini = list(ini)
# 
# tinitial = 0
# tfinal = 1.2
# tstep = 0.01 ## was 1/30
# t=numpy.r_[tinitial:tfinal:tstep]
# =============================================================================

######SOLVE FOR JUMPING#######
f,ma = system.getdynamics()
func4 = system.state_space_post_invert2(f,ma,eq4_dd,eq4_d,eq4,constants = {})
#states4=pynamics.integration.integrate_odeint(func4,ini,t,hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':{},'alpha':1e3,'beta':1e1},))

print("!!!!!!finished 4!!!!!!!!!!!!!")

if debugging:
    lengthSet = numpy.arange(.14,.16,.2)
else:#.04
    lengthSet = numpy.arange(.04,.14,.01)
    
for length in lengthSet:
    leg_length = length
    print(leg_length)
    
    leg_mass = 0.095*(10**-3)*leg_length*100.0
    
    system.constant_values[lA] = (leg_length-top_length/2.0)/2.0
    system.constant_values[lA2] = (leg_length-top_length/2.0)/2.0
    system.constant_values[lB] = leg_length
    system.constant_values[lC] = (leg_length-top_length/2.0)/2.0
    system.constant_values[lC2] = (leg_length-top_length/2.0)/2.0
    system.constant_values[lD] = leg_length
    
    #define mass cnstants for each segment

    system.constant_values[mA] = leg_mass/2.0+clamp_mass
    system.constant_values[mA2] = leg_mass/2.0
    system.constant_values[mB] = leg_mass
    system.constant_values[mC] = leg_mass/2.0+clamp_mass
    system.constant_values[mC2] = leg_mass/2.0
    system.constant_values[mD] = leg_mass
    
    #define inertia constants
    system.constant_values[I_xx] = leg_mass/12.0*(leg_thickness*leg_thickness + leg_width*leg_width)
    system.constant_values[I_yy] = leg_mass/12.0*(leg_length*leg_length + leg_width*leg_width)
    system.constant_values[I_zz] = leg_mass/12.0*(leg_length*leg_length + leg_thickness*leg_thickness)
    system.constant_values[I_xx2] = 0.5*leg_mass/12.0*(leg_thickness**2 + leg_width**2)
    system.constant_values[I_yy2] = 0.5*leg_mass/12.0*(leg_length/2.0*leg_length/2.0 + leg_width*leg_width)
    system.constant_values[I_zz2] = 0.5*leg_mass/12.0*(leg_length/2.0*leg_length/2.0 + leg_thickness*leg_thickness)
    system.constant_values[I_xxT] = (0.5*leg_mass + clamp_mass)/12.0*(leg_thickness**2 + leg_width**2)
    system.constant_values[I_yyT] = (0.5*leg_mass + clamp_mass)/12.0*(leg_length/2.0*leg_length/2.0 + leg_width*leg_width)
    system.constant_values[I_zzT] = (0.5*leg_mass + clamp_mass)/12.0*(leg_length/2.0*leg_length/2.0 + leg_thickness*leg_thickness)

    forcePerTheta = 3* areaI * E / (leg_length)**3
    system.constant_values[spring_constant] = forcePerTheta#*180.0/3.14159;
    
    
    
    #1
    print('****Integrating 1*******')
    tinitial = 0
    tfinal = 2
    tstep = .1 ##0.01!!!
    t = numpy.r_[tinitial:tfinal:tstep]
    
    statevariables = system.get_state_variables()
    ini = [initialvalues[item] for item in statevariables]
    
    states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-3,atol=1e-3,args=({'constants':system.constant_values,'alpha':1e3,'beta':1e1},))
    
    #leg constraint check
    points = [pDtip,pCD,pCC2,pOC,pOA,pAA2,pAB,pBtip]
    points = [item2 for item in points for item2 in [item.dot(N.x),item.dot(N.y)]]
    points = Output(points)
    if(debugging):
        y = points.calc(states)
        y = y.reshape((-1,8,2))
        plt.figure()
        plt.title('leg constraint solving')
        for item in y[::5]:
            plt.plot(*(item.T))
    plt.show()
    
    #2
    print('****Integrating 2*******')
    ini = states[-1]
    #ini[2] = 0
    #ini[7:] = 0
    #ini[7] = 10
    ini = list(ini)
    
    tinitial = 0
    tfinal = 2
    tstep = 0.1 ## was 1/30
    t = numpy.r_[tinitial:tfinal:tstep]
    
    states2=pynamics.integration.integrate_odeint(func2,ini,t,rtol=1e-3,atol=1e-3,args=({'constants':system.constant_values,'alpha':1e2,'beta':1e1},))
    #states2=pynamics.integration.integrate_odeint(func2,ini,numpy.r_[tinitial:tfinal:tstep],hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':system.constant_values,'alpha':1e3,'beta':1e1},))
    
    if(debugging):
        y = points.calc(states2)
        y = y.reshape((-1,8,2))
        plt.figure()
        for item in y[::1]:
            plt.plot(*(item.T))
        plt.axis('equal')
    plt.show()
    
    
    #3
    print('****Integrating 3*******')
    ini = states2[-1]
    #ini[2] = 0
    #ini[7:] = 0
    #ini[7] = 10
    ini = list(ini)
    
    tinitial = 0
    tfinal = 2
    tstep = 0.1 ## was 1/30!!!!
    t = numpy.r_[tinitial:tfinal:tstep]
    
    states3=pynamics.integration.integrate_odeint(func3,ini,t,rtol=1e-3,atol=1e-3,
                                                  args=({'constants':system.constant_values,'alpha':1e3,'beta':1e1},))
    
    if(debugging):
        y = points.calc(states3)
        y = y.reshape((-1,8,2))
        plt.figure()
        for item in y[::2]:
            plt.plot(*(item.T))
        plt.axis('equal')
        plt.title('show pre? compressed')
    
    
    root = 'C:/Users/Jacob/Documents/Junior/IDEAlab/Dynamics/leg modelling flex'
    lenDir = root + '/01_' + "%02d"%(leg_length*100)
    
    if debugging:
        gearSet = numpy.arange(75,100,25)
    else:
        gearSet = numpy.arange(25,175,12.5)
    
    for g in gearSet:
        gearDir = lenDir + '_' + str(g)
        if not os.path.exists(gearDir):
            os.makedirs(gearDir)
        os.chdir(gearDir)
        print(g)
        gear_ratio = g
        system.constant_values[Tmax] = 0.1554/75.0*gear_ratio
        system.constant_values[wMax] = 400.0/60.0*2.0*3.14159*75.0/gear_ratio
        
        #4
        print('*****Integrating 4*******')
        ini = states3[-1]
        #ini[2] = 0
        #ini[7:] = 0
        #ini[7] = 10
        ini = list(ini)
        
        tinitial = 0
        tfinal = 0.8
        tstep = 0.01 ## was 1/30
        t=numpy.r_[tinitial:tfinal:tstep]
        states4=pynamics.integration.integrate_odeint(func4,ini,t,hmax = .01,rtol=1e-3,atol=1e-3,args=({'constants':system.constant_values,'alpha':1e3,'beta':1e1},))
        
        
        
        y = points.calc(states4)
        y = y.reshape((-1,8,2))
        plt.figure()
        for item in y[::10]:
            plt.plot(*(item.T))
        plt.axis('equal')
        plt.title('Jumping Visualization')
        plt.suptitle('length = ' + str(leg_length) + ' (m), gear ratio = ' + str(gear_ratio))
        plt.xlabel('(m)')
        plt.ylabel('(m)')
        plt.savefig('Jumping Visualization.pdf', transparent = True)
        
        energy = Output([KE-PE])
        # =============================================================================
        # energy.calc(states4)
        # energy.plot_time()
        # plt.title('energy as jumping')
        # =============================================================================
        
        top = Output([pOcm.dot(N.y)])
        toparray = top.calc(states4)
        top.plot_time(t)
        plt.title('Height of Top as Jumping')
        plt.suptitle('length = ' + str(leg_length) + ' (m), gear ratio = ' + str(gear_ratio))
        plt.xlabel('time (s)')
        plt.ylabel('height (m)')
        plt.savefig('Top Height.pdf', transparent = True)
        numpy.savetxt('top height.csv', numpy.transpose([t,toparray]), delimiter=',')
        
        tip = Output([pBtip.dot(N.y)])
        bottomarray = tip.calc(states4)
        tip.plot_time(t)
        plt.title('Height of Bottom as Jumping')
        plt.suptitle('length = ' + str(leg_length) + ' (m), gear ratio = ' + str(gear_ratio))
        plt.xlabel('time (s)')
        plt.ylabel('height (m)')
        plt.savefig('Bottom Height.pdf', transparent = True)
        numpy.savetxt('bottom height.csv', numpy.transpose([t,bottomarray]), delimiter=',')
        
        forcy = Output([groundS.f.dot(N.y) + groundD.f.dot(N.y)])
        forcyarray = forcy.calc(states4)
        forcy.plot_time(t)
        plt.title('Force on Ground as Jumping')
        plt.suptitle('length = ' + str(leg_length) + ' (m), gear ratio = ' + str(gear_ratio))
        plt.xlabel('time (s)')
        plt.ylabel('force (N)')
        plt.savefig('Force.pdf', transparent = True)
        numpy.savetxt('force.csv', numpy.transpose([t,forcyarray]), delimiter=',')
        
        enc = Output([qA*-180.0/3.14159])
        encarray = enc.calc(states4)
        enc.plot_time(t)
        plt.title('Encoder Rotation as Jumping')
        plt.suptitle('length = ' + str(leg_length) + ' (m), gear ratio = ' + str(gear_ratio))
        plt.xlabel('time (s)')
        plt.ylabel('rotation (rad)')
        plt.savefig('Encoder.pdf', transparent = True)
        numpy.savetxt('enc.csv', numpy.transpose([t,encarray]), delimiter=',')
        
        plt.show()

        
#damper should be turned on with velocity
#and try just increasing both

# =============================================================================
# for inertia1 in inertia_test_range:
#     constants[Im] = inertia1
#     states=pynamics.integration.integrate_odeint(func1,ini,t,rtol=1e-10,atol=1e-10,args=({'constants':constants,'alpha':1e2,'beta':1e1},))
#     positions.calc(states)
#     y_simulation = positions.y
#     ax1.plot(t,y_simulation,label='I={0:5.2e}'.format(inertia1))
# 
# =============================================================================


#########################################################


# =============================================================================
# import os
# import idealab_tools.makemovie
# idealab_tools.makemovie.clear_folder()
# folder = idealab_tools.makemovie.prep_folder()
# fig = plt.figure()
# ax = fig.add_subplot(1,1,1)
# ax.axis('tight')
# 
# for ii,item in enumerate(y):
#     [item.remove() for item in ax.lines]
#     plt.plot(*(item.T),'ro-')
#     ax.set_xlim((y[:,:,0].min(),y[:,:,0].max()))
#     ax.set_ylim((y[:,:,1].min(),y[:,:,1].max()))
#     plt.savefig(os.path.join(folder,'{0:04d}.png'.format(ii)), dpi = 100)
# 
# def make_gif(output_filename='render.gif',images_folder='render',fps=30,output_folder='.',image_name_format='*.png'):
#     import imageio
#     import glob
#     
#     if os.path.exists(output_folder+'/'+output_filename):
#         os.remove(output_folder+'/'+output_filename)
# 
#     filenames = glob.glob(os.path.join(images_folder,image_name_format))
#     images = []
#     for filename in filenames:
#         images.append(imageio.imread(filename))
#     imageio.mimsave(os.path.join(output_folder,output_filename), images,duration=1/fps ) 
# plt.ion()
# make_gif()
# =============================================================================
#idealab_tools.makemovie.render(movie_folder="C:/Users/Jacob/Documents/Junior/IDEAlab/Dynamics")
#idealab_tools.makemovie.clear_folder()