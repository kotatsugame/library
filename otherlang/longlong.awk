BEGIN{
	INT_WORD_SIZE=5;
	INT_BASE=10^INT_WORD_SIZE;
	INT_LENGTH=4;
}
function isneg(A){return +A[INT_LENGTH]}
function iszero(A,i)
{
	for(i=0;i<INT_LENGTH;++i)
	{
		if(A[i]!=0)return 0;
	}
	return 1;
}
function add(A,B,i)
{
	for(i=0;i<=INT_LENGTH;++i)
	{
		A[i]+=B[i];
		if(A[i]>=INT_BASE){
			A[i]-=INT_BASE;
			A[i+1]+=1;
		}
	}
	A[INT_LENGTH]%=2;
}
function neg(A,i)
{
	for(i=0;i<INT_LENGTH;++i)
	{
		A[i]=INT_BASE-A[i]-(i!=0);
	}
	A[INT_LENGTH]=1-A[INT_LENGTH];
}
function cmp(A,B,i)#A<B?-1:A>B?1:0
{
	if(isneg(A))
	{
		if(isneg(B))
		{
			for(i=INT_LENGTH-1;i>=0;--i)
			{
				if(A[i]!=B[i])return A[i]<B[i]?1:-1;
			}
			return 0;
		}
		else return -1;
	}
	else
	{
		if(isneg(B))return 1;
		else
		{
			for(i=INT_LENGTH-1;i>=0;--i)
			{
				if(A[i]!=B[i])return A[i]<B[i]?-1:1;
			}
		}
	}
}
function mul(A,B_orig,RET,B,negflag,i,j)
{
	copy(B_orig,B);
	if(isneg(A))
	{
		negflag+=1;
		neg(A);
	}
	if(isneg(B))
	{
		negflag+=1;
		neg(B);
	}
	negflag%=2;
	for(i=0;i<INT_LENGTH;++i)
	{
		for(j=0;i+j<INT_LENGTH;++j)
		{
			RET[i+j]+=A[i]*B[j];
		}
	}
	for(i=0;i<INT_LENGTH-1;++i)
	{
		RET[i+1]+=int(RET[i]/INT_BASE);
		RET[i]%=INT_BASE;
	}
	RET[INT_LENGTH-1]%=INT_BASE;
	if(negflag)neg(RET);
	copy(RET,A);
}
function div(A,B_orig,B,negflag,dividend,divisor,diff)#C-style
{
	copy(B_orig,B);
	if(isneg(A))
	{
		negflag+=1;
		neg(A);
	}
	if(isneg(B))
	{
		negflag+=1;
		neg(B);
	}
	copy(A,dividend);
	copy(B,divisor);
	input(sprintf("%.f",to_str(dividend)/to_str(divisor)),A);
	mul(divisor,A);
	neg(divisor);
	add(dividend,divisor);
	copy(B,divisor);
	diff=0;
	while(isneg(dividend))
	{
		diff-=1;
		add(dividend,divisor);
	}
	neg(divisor);
	while(cmp(dividend,B)!=-1)
	{
		diff+=1;
		add(dividend,divisor);
	}
	input(diff,dividend);
	add(A,dividend);
	if(negflag%2==1)neg(A);
}
function mod(A,B,tmp,modulo)
{
	copy(A,tmp);
	copy(B,modulo);
	if(isneg(modulo))neg(modulo);
	div(tmp,modulo);
	mul(tmp,modulo);
	neg(tmp);
	add(A,tmp);
	while(isneg(A))add(A,modulo);
}
function copy(A,B,i)
{
	for(i=0;i<=INT_LENGTH;++i)B[i]=A[i];
}
function input(x,A,i,negflag)
{
	if(x=="-0")x="0";
	negflag=sub(/^-/,"",x);
	x=sprintf("%"(INT_LENGTH*INT_WORD_SIZE)"s",x);
	for(i=0;i<INT_LENGTH;++i)
	{
		A[i]=+substr(x,(INT_LENGTH-i-1)*INT_WORD_SIZE+1,INT_WORD_SIZE);
	}
	A[INT_LENGTH]=0;
	if(negflag)neg(A);
}
function to_str(A_orig,A,negflag,flag,i,str)
{
	copy(A_orig,A);
	if(isneg(A))
	{
		negflag=1;
		neg(A);
	}
	for(i=INT_LENGTH-1;i>=0;--i)
	{
		if(flag)
		{
			str=str sprintf("%0" INT_WORD_SIZE "d",A[i]);
		}
		else if(A[i]>0)
		{
			str=sprintf("%d",A[i]);
			flag=1;
		}
	}
	if(!str)str="0";
	return (negflag?"-":"")str;
}
function disp(A){print to_str(A)}
