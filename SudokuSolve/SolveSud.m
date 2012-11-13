function Sud = SolveSud(Sud) 
%Input 9 by 9 matrix with sudoku to solve. 0s are empty cells.
%Return solved Sudoku.
[solvedcells, celltosolve] = SolveCell(Sud); %Solve specific cell.
while ~isempty(celltosolve) %Cells still not with fixed solutions.
    Sud(celltosolve) = SolvedCells(celltosolve);
    [solvedcells, celltosolve] = SolveCell(Sud);
end
emptycell = find(Sud(:) == 0,1); % 0 is an unsolved cell.
if ~isempty(emptycell);
  hold=Sud; %Temp store.
  for i = solvedcells(emptycell);
      Sud=hold;
      Sud(emptycell)=i;
      Sud=SolveSud(Sud);
      x = find(Sud(:)==0,1);
      if isempty(Sud) %Sudoku solved.
          return;
      end
  end
end

%Alejandro Soulier  as4094

    