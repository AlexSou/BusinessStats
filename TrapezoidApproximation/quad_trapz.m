function  [Q,fcount] = quad_trapz(F,a,b,h,varargin)
% 2a. Based on Quad_Rectangle.


%   Arguments beyond the first four, Q = QUAD_RECTANGLE(F,a,b,tol,p1,p2,...),
%   are passed on to the integrand, F(x,p1,p2,..).
%
%   [Q,fcount] = QUAD_RECTANGLE(F,...) also counts the number of evaluations
%   of F(x).
%

format long; %Make more digits visible.

% Make F callable by feval
if ischar(F) & exist(F)~=2
   F = inline(F);
elseif isa(F,'sym')
   F = inline(char(F));
end

x_vec = [ a + h/2 : h : b - h/2];
Q = 0;
for x = x_vec
    Q = Q + feval(F,x,varargin{:});
end

Q = h*Q;
fcount = length(x_vec);

% end of function quad_rectangle.m