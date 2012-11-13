function [ ] = hw2ML()
%Input: None
%Output: Graph with differences between trapez. integration values and real
%answer.
% Alejandro Soulier as4094

try
    
    format long; %Allow all decimal points to be displayed.
    matTrap = importdata('Qtrap.txt');
    trapX = matTrap(1:10);
    trapY = matTrap(11:20);
    figure;
    plot(trapY,trapX); %Trap graph.
    title('Qtrap Integration Error');
    xlabel('Log (absolute error)');
    ylabel('CPU Time');
    matSimp = importdata('Qsimp.txt');
    simpX = matSimp(1:10);
    simpY = matSimp(11:20);
    figure;
    plot(simpY,simpX); %Simp graph.
    title('Qsimp Integration Error');
    xlabel('Log (absolute error)');
    ylabel('CPU Time');
    
catch err %Error in code.
    disp('Error')
end

end

%End of file.