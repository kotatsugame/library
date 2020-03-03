type UnionFind=record n:Longint;pr:Array of Longint;end;
procedure init(var uf:UnionFind;N:Longint);
var i:Longint;
begin
	uf.n:=N;
	setlength(uf.pr,N+1);
	for i:=1 to N do uf.pr[i]:=-1;
end;
function find(var uf:UnionFind;a:Longint):Longint;
begin
	if uf.pr[a]<0 then find:=a else begin
		uf.pr[a]:=find(uf,uf.pr[a]);
		find:=uf.pr[a];
	end;
end;
function same(var uf:UnionFind;a,b:Longint):Boolean;
begin
	same:=find(uf,a)=find(uf,b);
end;
function unite(var uf:UnionFind;a,b:Longint):Boolean;
begin
	a:=find(uf,a);
	b:=find(uf,b);
	if a=b then unite:=false else begin
		if uf.pr[a]>uf.pr[b] then begin
			inc(uf.pr[b],uf.pr[a]);
			uf.pr[a]:=b;
		end else begin
			inc(uf.pr[a],uf.pr[b]);
			uf.pr[b]:=a;
		end;
		unite:=true;
	end;
end;
function size(var uf:UnionFind;a:Longint):Longint;
begin
	size:=-uf.pr[find(uf,a)];
end;
