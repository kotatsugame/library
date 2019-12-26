function sort(A,l,r,tmp,mid,il,ir)#[l,r)
{
	if(r-l==2)
	{
		if(sort_cmp(A[l+1],A[l]))
		{
			tmp=A[l];
			A[l]=A[l+1];
			A[l+1]=tmp;
		}
	}
	else if(r-l>2)
	{
		mid=int((l+r)/2);
		if(sort_cmp(A[mid],A[l]))
		{
			tmp=A[mid];
			A[mid]=A[l];
			A[l]=tmp;
		}
		if(sort_cmp(A[r-1],A[mid]))
		{
			tmp=A[r-1];
			A[r-1]=A[mid];
			A[mid]=tmp;
			if(sort_cmp(A[mid],A[l]))
			{
				tmp=A[mid];
				A[mid]=A[l];
				A[l]=tmp;
			}
		}
		il=l;
		ir=r-1;
		while(il<=ir)
		{
			while(sort_cmp(A[il],A[mid]))il++;
			while(sort_cmp(A[mid],A[ir]))ir--;
			if(il<ir)
			{
				tmp=A[il];
				A[il]=A[ir];
				A[ir]=tmp;
				if(mid==il)mid=ir;
				else if(mid==ir)mid=il;
				il++;
				ir--;
			}
			else if(il==ir)
			{
				il++;
				ir--;
			}
		}
		sort(A,l,il);
		sort(A,il,r);
	}
}
function sort_cmp(a,b)#bool(a<b)
{
	return a<b;
}
