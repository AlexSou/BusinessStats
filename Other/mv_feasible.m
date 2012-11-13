function mv_feasible(r_mat, m, rseed)
% MV_FEASIBLE  function to plot feasible portfolios in mv space
% inputs:  r_mat, m, rseed
%          where r_mat is a matrix of historical returns with
%          rows corresponding to time and columns to securities
%          m is the number of points in mv space
%          rseed is the random number seed
% outputs: none (a graph will be displayed)

%  YOUR CODE GOES HERE

mu    = mean(r_mat);
sig   = std(r_mat);
covar = cov(r_mat);

[M,N] = size(r_mat); 
xMatrix = rand(m, N); %Produce all random values.
%Normalize values so a row adds up to 1
xMatrix = xMatrix./repmat(sum(xMatrix,2),1,N);
%Calculate means/std for all random values.
for i = 1:m
   currX = xMatrix(i,:);
   meanX = currX * mu';
   stdX = sqrt(currX*covar*currX');
   xAxis(i) = meanX;
   yAxis(i) = stdX;
end

%Plot random values.
gscatter(yAxis,xAxis); hold on;
scatter(sig, mu, '+'); %Plot 100% values.
grid;
title('Feasible Mean-Variance Points');
xlabel('Portfolio Standard Deviation');
ylabel('Portfolio Mean Return');

% end of mv_feasible.m