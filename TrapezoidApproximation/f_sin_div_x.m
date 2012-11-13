function y = f_sin_div_x(x)

format long;

y = sin(x)./x;


% The full result wasn't being shown because the output was limited to 4
% decimal places. By adding format long, this is resolved. The approximate
% answer is 0.772096827090069 after 80 iterations. This approximation
% overestimates the result by 1.041608068796940e-06.


% end of function f_sin_div_x.m