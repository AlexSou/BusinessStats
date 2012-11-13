function [ v ] = tdist( data )
%Input data set, output t-dist parameter.
n = length(data);
mean = sum(data)/n;
meansq=0;
for i = 1 : n %calculate sample std.
    meansq = meansq + (data(i)-mean)^2;
end
vare = (1/(n-1)) * meansq;
var = (1/n)  * meansq;
V = (n-1)* vare/var;
%Chi-sq
Z = sqrt(n)/sqrt(var);
T = sqrt(n)/sqrt(vare);

v = V / ((Z/T)^2);


end

% Alejandro Soulier
%as4094