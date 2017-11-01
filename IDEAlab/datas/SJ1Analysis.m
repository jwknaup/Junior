trial1Pos = csvread('position11.csv');
trial2Pos = csvread('position12.csv');

trial1Start = trial1Pos(5,3);
trial2Start = trial2Pos(5,3);

trial1Max = max(trial1Pos(:,3));
trial2Max = max(trial2Pos(:,3));

trial1Dif = trial1Max-trial1Start;
trial2Dif = trial2Max-trial2Start;

averageDif = mean([trial1Dif trial2Dif])

leg_length = .187*2;
jumpHeight = averageDif - leg_length + .04

height = trial2Pos(885:1066,3);
time = trial2Pos(885:1066,1) - trial2Pos(885,1);

trial2Force = csvread('force12.csv');
force = trial2Force(:,2);
weight = 0.7;
tf = 66.9531;
t0 = 66.6719;
dt = tf-t0;
time2 = linspace(0, dt, 50)';
plot(time, height)
hold on
plot(time2, force, '.')
axis([0, .6, 0, 2]);
legend('Height', 'Force');
xlabel('time (s)');
ylabel('Height (m) / Force (N)');