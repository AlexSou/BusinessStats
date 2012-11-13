function [ twoNorm ] = matCompare( noRows, seed )
%Input: Matrix number of rows, seed for random number.
%Output: two-norm difference of matrices.
% Produce the 2-norm difference between C Gauss Elimination and the Matlab one.
% Alejandro Soulier as4094

    try
       rng(seed);
       matA = rand(noRows);
       vecB = rand(noRows, 1);
       outfile = fopen('matrix_solve_in.txt','w');
       fprintf(outfile, '%d\n', noRows);
       fprintf(outfile, '%10.6f\n', matA);
       fprintf(outfile, '%10.6f\n', vecB);
       fclose(outfile);
       system('matrix_solve.exe'); %Run matrix C program, Windows systems only.
       infile = fopen('matrix_solve_out.txt','r');
       ansMat = fscanf(infile,'%10.6f', inf );
       fclose(infile);
       matX = linsolve(matA,matB);
       twoNorm = normest(ansMat) - normest(matX);
    catch err %Error in code.
        disp('Error')
    end
end

