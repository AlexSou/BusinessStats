function [  ] = trinomial_call( int n)

% Alejandro Soulier as4094

try
    
    infile = fopen('trinomial_results_1.txt','r');
    stockPr = fscanf(infile,'%10.6f', n );
    binPr = fscanf(infile,'%10.6f', n );
    bsPr = fscanf(infile,'%10.6f', n );
    fclose(infile);
    twoNorm = normest(binPr) - normest(bsPr);
    plot(twoNorm);
catch err %Error in code.
    disp('Error')
end
end