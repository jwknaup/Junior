trial1Pos = csvread('position4.csv');
trial2Pos = csvread('position5.csv');

trial1Start = trial1Pos(5,3);
trial2Start = trial2Pos(5,3);

trial1Max = max(trial1Pos(:,3));
trial2Max = max(trial2Pos(:,3));

trial1Dif = trial1Max-trial1Start;
trial2Dif = trial2Max-trial2Start;

averageDif = mean([trial1Dif trial2Dif])

leg_length = .095;
jumpHeight = averageDif - leg_length + .015

height = trial2Pos(666:762,3);
time = trial2Pos(666:762,1) - trial2Pos(666,1);

trial2Force = csvread('force4.csv');
force = trial2Force(1:30,2);
weight = .38;
tf = .2969;
t0 = .1719;
dt = tf-t0;
time2 = linspace(0, dt, 30)';
plot(time, height)
hold on
plot(time2, force, '.')
axis([0, .6, 0, 1.6]);
legend('Height (large leg)', 'Force (large leg)', 'Height (small leg)', 'Force (small leg)');
xlabel('time (s)');
ylabel('Height (m) / Force (N)');