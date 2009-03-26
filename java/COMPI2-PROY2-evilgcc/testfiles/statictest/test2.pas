program kreig;
uses crt;
type
	arr1 = array [1..8,1..5] of integer;
var
	l: integer;

function A(mat : array[1..8,1..5] of integer) : integer ;
var
	i, j, k : integer;
begin	
	while i < k do
	begin
		j := i + 1;
		while j < l do
		begin
			mat[j,i] := mat[i,j] * j;
			mat[i,j] := j*i;
			j := j+1;
		end;
		i := i+1;
	end;
	A(mat);
end;

begin
	A(arr1);	
end.

