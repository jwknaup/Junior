%% Velo DifEq
clear
clc
 
global Tmax wmax mass moment_arm gear_ratio;
maxJumpHeight = 0;
loops1 = 50;
loops2 = 100;
jumpHeights = zeros(1, loops1*loops2);
speeds = zeros(1, loops1*loops2);
lengths = zeros(1, loops1*loops2);
i=0;

for gear_ratio = linspace(1, 10, loops1)%1.02m moment arm gives 1.447m extra height
    for moment_arm = linspace(0.03, 1.0, loops2)
        i=i+1;
%gear_ratio = 1;
Tmax =0.4943*2/gear_ratio; 
wmax = gear_ratio*100*2*pi()/60;
%moment_arm = .1;
mass = .019 + .2674*moment_arm;

start_angle = 5*pi/180;
end_angle = 85*pi/180;

tFinal = moment_arm/gear_ratio + .15;
tspan = [0,tFinal];
x0 = [0; start_angle];
options = odeset('MaxStep', tFinal*.01);
[time, x] = ode45(@odes, tspan, x0, options);
velocity = x(:, 1);
angle = x(:, 2);
indexAngle = find(end_angle-angle < .1, 1);
if(isempty(indexAngle))
    break
end
v1= velocity(indexAngle);

%[~, indexVelo] = max(velocity)
%height = cumtrapz(time, velocity) + 2*sin(start_angle)*moment_arm;

% height at which leaves the ground
    h1 = sin(end_angle)*moment_arm*2;
    %final height
    syms h2;
    
    %potential energies
    U1 = mass * 9.81 * h1;
    U2 = mass * 9.81 * h2;
    
    %kinetic energy when leaving the ground
    K1 = 1/2*mass*v1^2;
    K2 = 0;

    %solve for h2
    finalHeight = vpa(solve(K1+U1 == K2+U2));
    jumpHeight = finalHeight-h1;
    
    speeds(i) = gear_ratio;
    lengths(i) = moment_arm;
    jumpHeights(i) = jumpHeight;
    end 
end

results = [lengths' speeds' jumpHeights']
csvwrite('matlabOpt3.csv', results);

%results = [time velocity height]
%csvwrite('matlabOne.csv', results);


function dxdt = odes(t, x)
    global Tmax wmax mass moment_arm;
    
    w = 0.5*x(1)/moment_arm/cos(x(2));
    T = (Tmax - w * Tmax/wmax);
    F = T*cos(x(2))/moment_arm - 9.81*mass;
    a = F/mass;

    dxdt = [ a
        w];
end
