k1 = 20.9736; %N/m
k2 = 7.7922; %N/m

L1 = .150;%m
L2 = .175; %m

k1*L1*L1*L1
k2*L2*L2*L2

%%
thickness = 1.3*10^-3;
width = .02;
syms deflection F L E I
deflection = F*L^3/(3*E*I);
forcePerDeflection = (L^3/(3*E*I))^-1

I = width * thickness^3 / 12;
E=k1*L^3/(3*I);

%a = subs(E, forcePerDeflection, k1);
a = vpa(subs(E, L, L1))
E=k2*L^3/(3*I);
b = vpa(subs(E, L, L2))
elasticModulus  = (a+b)/2

deflectionPerTheta = L;
forcePerTheta = forcePerDeflection*deflectionPerTheta

%chosen 5cm and 1000 rpm and 1 cm wide