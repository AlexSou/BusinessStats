function [ y ] = g_test ( x, d_vec )
% 2c. Add elements in a vector.

try
    for l=1:length(x)
        currX = x(l);
        currY = 0;
        for i=1:length(d_vec)
            currY = currY + d_vec(i)*(currX^(i-1));         
        end
        y(l) = currY;     
        
    end
    
catch err
    disp('Error')
end

end

% The output of the example function is  9     9    -7   -39.