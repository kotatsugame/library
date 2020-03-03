type SortDataType=Longint;
function SortCmp(const a,b:SortDataType):Boolean;forward;
procedure SortImpl(var A:Array of SortDataType;L,R:Longint);
var
	tmp:SortDataType;
	mid,il,ir:Longint;
begin
	if R-L=2 then begin
		if SortCmp(A[L+1],A[L])then begin
			tmp:=A[L];
			A[L]:=A[L+1];
			A[L+1]:=tmp;
		end;
	end else if R-L>2 then begin
		mid:=(L+R)div 2;
		if SortCmp(A[mid],A[L])then begin
			tmp:=A[mid];
			A[mid]:=A[L];
			A[L]:=tmp;
		end;
		if SortCmp(A[R-1],A[mid])then begin
			tmp:=A[R-1];
			A[R-1]:=A[mid];
			A[mid]:=tmp;
			if SortCmp(A[mid],A[L])then begin
				tmp:=A[mid];
				A[mid]:=A[L];
				A[L]:=tmp;
			end;
		end;
		il:=L;
		ir:=R-1;
		while il<=ir do begin
			while SortCmp(A[il],A[mid])do inc(il);
			while SortCmp(A[mid],A[ir])do dec(ir);
			if il<ir then begin
				tmp:=A[il];
				A[il]:=A[ir];
				A[ir]:=tmp;
				if mid=il then mid:=ir else if mid=ir then mid:=il;
				inc(il);
				dec(ir);
			end else if il=ir then begin
				inc(il);
				dec(ir);
			end;
		end;
		SortImpl(A,L,il);
		SortImpl(A,il,R);
	end;
end;
procedure Sort(var A:Array of SortDataType;size:Longint);
begin
	SortImpl(A,0,size);
end;
function SortCmp(const a,b:SortDataType):Boolean;
begin
	SortCmp:=a<b;
end;
