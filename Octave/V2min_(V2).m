
function [V2min]= V2min_(V2)
V2=input("intoduzca los numeros de un vector:")
n=length(V2);
 V2min=V2(1);
i=1;
do
  if(V2(i)<V2min)
  V2min=V2(i);
endif
i=i+1;
until(i<n)
fprintf("V2min es %d",V2min);
endfunction
