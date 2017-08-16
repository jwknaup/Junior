function [qm] = QuatMult(q1,q2)
% It produces the q1 * q2 in Quatrenion
s1 = q1(1);
v1 = [q1(2) q1(3) q1(4)];
s2 = q2(1);
v2 = [q2(2) q2(3) q2(4)];
qm(1) = s1 * s2 - dot(v1,v2);
qm(2:4) = s1*v2 + s2*v1 + cross(v2,v1);
end

