%% Find ideal moment arm for highest jump

%linear velocity function
syms v(t);
maxJumpHeight = 0;
%from 1 cm to 2.5m (takes awhile)
for moment_arm = linspace(0.01, 2.5, 100)
    %omega
    w = v/moment_arm/cosd(45);
    %maximum torque for 2 motors
    Tmax = 0.4943*2;
    %max angular velocity in rad/s
    wmax = 100*2*pi()/60;
    %mass of leg with motors
    mass = .021;

    T = Tmax - w * Tmax/wmax;
    F = T/moment_arm / cosd(45) - 9.81*mass;
    initialForce = Tmax/moment_arm/cosd(45) - 9.81*mass;

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
    %find velocity at that time
    velo = subs(velocity, t, time);

    %kinetic energy when leaving the ground
    K1 = 1/2*mass*velo^2;
    K2 = 0;

    %solve for h2
    jumpHeight = solve(K1+U1 == K2+U2);
    %find change in height after leaving the ground
    jumpHeight = double(jumpHeight) - h1;

    %check if new moment_arm results in higher jump
    if jumpHeight > maxJumpHeight
        idealConfig = [moment_arm, jumpHeight];
        maxJumpHeight = jumpHeight;
    end
end
%print results
idealConfig
