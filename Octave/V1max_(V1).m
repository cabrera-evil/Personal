%eejrcicio 1
function [V1max]= V1max_(V1)
  V1=input("intoduzca los numeros de vector 1: ");
  n=length(V1);
  V1max=V1(1);
  i=1;
  do
    if(V1(i)>V1max),
      V1max = V1(i);
    endif
    i=i+1;
  until(i>n);
  fprintf("V1max es %d",V1max) ;

endfunction
