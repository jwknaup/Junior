syms Vgs;
Id1 = 10*(1-Vgs/-3.5)^2;
Id2 = (2.157-Vgs)/1.1;

VgsQ = solve(Id1 == Id2);
VgsQ = vpa(VgsQ);
VgsQ = VgsQ(2,:)
IdQ = subs(Id2, Vgs, VgsQ);
IdQ = vpa(IdQ)
fplot(Id1, [-4,1]);
hold on;
fplot(Id2, [-4,1]);
title('Transfer Curve');
xlabel('Vgs (V)');
ylabel('Ids (mA)');
plot(VgsQ, IdQ, 'kx');
text(VgsQ, IdQ, '    Qpoint (-1.486V, 3.312mA)')