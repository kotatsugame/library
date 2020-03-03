type BITDataType=Longint;
type BinaryIndexedTree=record n:Longint;bit:Array of BITDataType;end;
procedure init(var bit:BinaryIndexedTree;N:Longint);
var i:Longint;
begin
	bit.n:=N;
	setlength(bit.bit,N+1);
	for i:=1 to N do bit.bit[i]:=0;
end;
function sum(var bit:BinaryIndexedTree;i:Longint):BITDataType;
var ans:BITDataType;
begin
	ans:=0;
	while i>0 do begin
		inc(ans,bit.bit[i]);
		dec(i,i and-i);
	end;
	sum:=ans;
end;
procedure add(var bit:BinaryIndexedTree;i:Longint;a:BITDataType);
begin
	while i<=bit.n do begin
		inc(bit.bit[i],a);
		inc(i,i and-i);
	end;
end;
