function [ sortedIndex ] = sortIndex( inputIndex )
% 1c. Sort the indices of a vector.
    try
        [sortedNo,sortedIndx1] = sort(inputIndex);
        [sortedNo2,sortedIndex] = sort(sortedIndx1);
           
    catch err
        disp('Error')
    end

end

