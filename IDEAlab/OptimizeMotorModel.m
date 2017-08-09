%% Find ideal moment arm for highest jump

%linear velocity function
syms v(t);
maxJumpHeight = 0;
loops = 25;
totalHeights = zeros(1, loops*loops);
jumpHeights = zeros(1, loops*loops);
speeds = zeros(1, loops*loops);
lengths = zeros(1, loops*loops);
i=0;

%from 1 cm to 2.5m (takes awhile)
for gear_ratio = linspace(1, 9, loops)%1.02m moment arm gives 1.447m extra height
    for moment_arm = linspace(0.05, 0.5, loops)
    i= i+1;
    %omega
    w = v/moment_arm/cosd(theta);
    %maximum torque for 2 motors
    Tmax = 0.4943/gear_ratio;
    %max angular velocity in rad/s
    wmax = 100*2*pi()/60*gear_ratio;
    %mass of leg with motors
    mass = .021;

    T = Tmax - w * Tmax/wmax;
    
    F = T/moment_arm / cosd(45) - 9.81*mass;
    initialForce = Tmax/moment_arm/cosd(45) - 9.81*mass;
    
    if(initialForce<0)
        break;
    end

    a = F/mass;
    %dv/dt = a(t)
    ode = diff(v,t) == a;
    %initial condition
    cond = v(0) == 0;
    %solve
    velocity = dsolve(ode, cond);

    % height at which leaves the ground
    h1 = sind(45)*moment_arm*2;
    %final height
    syms h2;
    
    %potential energies
    U1 = mass * 9.81 * h1;
    U2 = mass * 9.81 * h2;
    
    %integrate v(t) to find height function
    height = int(velocity);
    %find time at which leaving the ground
    time = solve(height == h1);
    if isreal(vpa(time)) == 0 && vpa(time) < 0
        break
    end
    %find velocity at that time
    velo = subs(velocity, t, time);

    %kinetic energy when leaving the ground
    K1 = 1/2*mass*velo^2;
    K2 = 0;

    %solve for h2
    jumpHeight = solve(K1+U1 == K2+U2);
    
    totalHeights(i) = jumpHeight;
    speeds(i) = gear_ratio;
    lengths(i) = moment_arm;
    
    %find change in height after leaving the ground
    jumpHeight = double(jumpHeight) - h1;
    
    jumpHeights(i) = jumpHeight;
    totalHeights;

    %check if new moment_arm results in higher jump
%     if jumpHeight > maxJumpHeight
%         idealConfig = [moment_arm, jumpHeight];
%         maxJumpHeight = jumpHeight;
%     end
    end
end
%print results
totalHeights;
jumpHeights;
speeds;
lengths;
scatter(speeds, jumpHeights)
figure(2);
scatter(speeds, totalHeights)
results = [lengths' speeds' jumpHeights' totalHeights']
csvwrite('matlabOpt.csv', results);