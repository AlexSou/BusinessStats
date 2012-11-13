function [ a_vec ] = vectorSign ( a_vec )
% 1a. This function parses a vector, outputting 1 if the value
% is positive or -1 if negative. 
    try %Try code.
        for i = 1:length(a_vec)
            if a_vec(i) > 0 % Positive
                a_vec(i) = 1;
            elseif a_vec(i) < 0
                a_vec(i) = -1; % Negative
            end
        end
           
    catch err % Error detected.
        disp('Error')
    end

end










