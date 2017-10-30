trial1Start = .25145;
trial2Start = .25258;
trial3Start = .25151;

trial1End = .35515;
trial2End = .36140;
trial3End = .36243;

trial1Change = trial1End - trial1Start;
trial2Change = trial2End - trial2Start;
trial3Change = trial3End - trial3Start;

averageChange = mean([trial1Change trial2Change trial3Change]);
legLength = .095;
jumpHeight = averageChange - legLength