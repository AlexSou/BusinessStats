function [ randMat ] = nMatrix( noRows )
% 1b. Produced an N by N matrix.
    try
        randMat = zeros(noRows, noRows);
        randMat(1,1)=0.1;
        randMat(1,2)=0.9;
        randMat(noRows,noRows - 1) = 0.1;
        randMat(noRows, noRows)=0.9;
        for i = 2:noRows-1 %Add all matrix rows.
            randMat(i,i-1)=0.1;
            randMat(i,i+1)=0.9;
        end
    
    catch err
        disp('Error')
    end

end

