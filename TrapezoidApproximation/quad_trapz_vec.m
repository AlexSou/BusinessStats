function  [Q,fcount] = quad_trapz_vec(F,a,b,h,varargin)

% Based on Quad_rectangle. 


%   Arguments beyond the first four, Q = QUAD_RECTANGLE_VEC(F,a,b,h,p1,p2,...),
%   are passed on to the integrand, F(x,p1,p2,..).
%
%   [Q,fcount] = QUAD_RECTANGLE_VEC(F,...) also counts the number of evaluations
%   of F(x).
%

% Make F callable by feval
if ischar(F) & exist(F)~=2
   F = inline(F);
elseif isa(F,'sym')
   F = inline(char(F));
end

x_vec = [ a + h/2 : h : b - h/2];
Q = feval(F,x_vec,varargin{:});
Q = h*sum(Q);
fcount = length(x_vec);

% end of function quad_rectangle_vec.m