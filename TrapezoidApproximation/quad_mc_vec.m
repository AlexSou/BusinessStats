function [ Q, std_err ] = quad_mc_vec( F, a,b,n, rseed, varargin )
% 3a. QUAD_MC_VEC. 

% Make F callable by feval
if ischar(F) & exist(F)~=2
    F = inline(F);
elseif isa(F,'sym')
    F = inline(char(F));
end

rng(rseed); %Introduce seed. 
randomN = rand(n,1); % 100 random numbers in a vector.
x_vec = (a + (b-a)* randomN);
fx = feval(F,x_vec,varargin{:});
Q = ((b-a)/n)*sum(fx);

sq = sqrt( (1/(n-1)) * sum( ((b-a)*fx - Q).^2 ) );
std_err = sq/sqrt(n);


end


% The standard error for f(x) is 2.484110088256807e-04.
% The real difference compared to real value 0.772095785482 is
% 2.889681851108161e-04.