function [freeCells, celltosolve] = SolveCell(Sud) 
%Solve specific cell.
freeCells = cell(9,9);
for i = 1:9
    for j = 1:9
        if Sud(j,i) == 0 %Cell to solve.
            choices = [1,2,3,4,5,6,7,8,9];
            choices(nonzeros(Sud(Sector(j), Sector(i))))=0; %Sector check.
            % Col and row checks.
            choices(nonzeros(Sud(j,:)))=0;
            choices(nonzeros(Sud(:,i)))=0;
            freeCells{j,i} = nonzeros(choices);
        end
    end 
end
 
 celltosolve = find( (length(freeCells)==1) & Sud==0, 1); 
 %Return unsolved cells.
end

    %Alejandro Soulier  as4094