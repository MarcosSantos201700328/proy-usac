program kreig;
uses crt;
type
	arr1 = array [1..5,1..10] of integer;
var
	ga, gb, gc : integer;
	gd : real;
	ge : char;


function patito1(a :integer ; b:integer; c: real) : integer ;
type
	arr2 = array [1..10,1..5] of integer;
var
	d, e : integer;
	pa : char;
	pb : integer;
	pc : string;
	str1 : integer;
begin
	if (a > b or b < c) and (c < a or d < e) then
	begin
		pb := 0;
		while pb < 5 do 
		begin
			pa := 'a';
			if (pa = 5) then
				arr2[pb,5] := arr1[pb,arr1[5,5]];
		end;	
		case pa of
			1:
			pc:= 'a';		
			2:					
			pc:= 'b';
			otherwise:
			pc:= 'c';
		end;
	end;
end;

procedure patito2(as1 : integer);
begin
	gd := as1;
end;

begin
	ga := patito1(gb, gc, gd);
	patito2(gb);
	writeln(ga,gb,gc,'a ');
	readln(ge);
	
end.

