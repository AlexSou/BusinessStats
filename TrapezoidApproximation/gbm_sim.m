% 4. gbm_sim script.

s0= 100;
u=0.05;
o=0.2;
T=20;


n = 1000;
m=30;
s_mat = cumprod (randn(m+1, n)); % m+1 by n random matrix.

plot(s_mat); %Plot matrix.
ylabel('Y axis');
xlabel('Time');


plot(log(s_mat));

hist(s_mat,15); %Plot histogram.