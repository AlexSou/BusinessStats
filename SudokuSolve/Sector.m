function sec = Sector(no) % Output: sector which number no belongs to.
if(no==1|no==2|no==3) % First quadrant.
    sec = [1,2,3];
elseif(no==4|no==5|no==6)
    sec = [4,5,6];
else 
       sec = [7,8,9];

end

%Alejandro Soulier  as4094