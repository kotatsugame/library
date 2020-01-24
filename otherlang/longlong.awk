BEGIN{
	INT_WORD_SIZE=5;
	INT_BASE=10^INT_WORD_SIZE;
	INT_LENGTH=4;
}
function isneg(A){return +A[INT_LENGTH]}
function iszero(A,i)
{
	for(i=0;i<=INT_LENGTH;++i)
	{
		if(A[i]!=0)return 0;
	}
	return 1;
}
function add(A,B_orig,B,i)
{
	copy(B_orig,B);
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
	if(!iszero(A))
	{
		for(i=0;i<INT_LENGTH;++i)
		{
			A[i]=INT_BASE-A[i]-(i!=0);
		}
		A[INT_LENGTH]=1-A[INT_LENGTH];
	}
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
function mul(A,B_orig,B,negflag,i,j)
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
	for(i=INT_LENGTH-1;i>=0;--i)
	{
		for(j=INT_LENGTH-i-1;j>0;--j)
		{
			A[i+j]+=A[i]*B[j];
		}
		A[i]*=B[0];
	}
	for(i=0;i<INT_LENGTH-1;++i)
	{
		A[i+1]+=int(A[i]/INT_BASE);
		A[i]%=INT_BASE;
	}
	A[INT_LENGTH-1]%=INT_BASE;
	if(negflag==1)neg(A);
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
	input_num(sprintf("%.f",to_str(dividend)/to_str(divisor)),A);
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
	add_num(A,diff);
	if(negflag==1)neg(A);
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
	if(!flag)str="0";
	return (negflag?"-":"")str;
}
function disp(A){print to_str(A)}
function add_num(A,x)
{
	if(x>0)add_num_impl(A,x);
	else if(x<0)sub_num_impl(A,-x);
}
function add_num_impl(A,x,i)
{
	i=0;
	while(i<INT_LENGTH)
	{
		A[i]+=x%INT_BASE;
		x=int(x/INT_BASE);
		if(A[i]>=INT_BASE)
		{
			A[i]-=INT_BASE;
			A[i+1]+=1;
		}
		++i;
	}
	A[INT_LENGTH]%=2;
}
function sub_num_impl(A,x,i)
{
	i=0;
	while(i<INT_LENGTH)
	{
		A[i]+=INT_BASE-x%INT_BASE-(i!=0);
		x=int(x/INT_BASE);
		if(A[i]>=INT_BASE)
		{
			A[i]-=INT_BASE;
			A[i+1]+=1;
		}
		++i;
	}
	A[INT_LENGTH]=(A[INT_LENGTH]+1)%2;
}
function mul_num(A,x,i,negflag)
{
	if(isneg(A))
	{
		negflag+=1;
		neg(A);
	}
	if(x<0)
	{
		negflag+=1;
		x=-x;
	}
	for(i=INT_LENGTH-1;i>=0;--i)
	{
		A[i]*=x;
	}
	for(i=0;i<INT_LENGTH-1;++i)
	{
		A[i+1]+=int(A[i]/INT_BASE);
		A[i]%=INT_BASE;
	}
	A[INT_LENGTH-1]%=INT_BASE;
	if(negflag==1)neg(A);
}
function div_num(A,x,negflag,dividend,divisor,diff)
{
	if(isneg(A))
	{
		negflag+=1;
		neg(A);
	}
	if(x<0)
	{
		negflag+=1;
		x=-x;
	}
	copy(A,dividend);
	input_num(sprintf("%.f",to_str(dividend)/x),A);
	copy(A,divisor);
	mul_num(divisor,x);
	neg(divisor);
	add(dividend,divisor);
	diff=0;
	while(isneg(dividend))
	{
		diff-=1;
		add_num(dividend,x);
	}
	input_num(x,divisor);
	while(cmp(dividend,divisor)!=-1)
	{
		diff+=1;
		add_num(dividend,-x);
	}
	add_num(A,diff);
	if(negflag==1)neg(A);
}
function mod_num(A,x,negflag,t,i,ret)
{
	if(isneg(A))
	{
		negflag=1;
		neg(A);
	}
	t=1;
	for(i=0;i<INT_LENGTH;++i)
	{
		ret+=t*A[i];
		t=t*INT_BASE%x;
	}
	ret%=x;
	if(negflag&&ret>0)ret=x-ret;
	input_num(ret,A);
}
function input_num(x,A,negflag,i)
{
	if(x=="-0")x="0";
	if(x<0)
	{
		negflag=1;
		x=-x;
	}
	for(i=0;i<INT_LENGTH;++i)
	{
		A[i]=x%INT_BASE;
		x=int(x/INT_BASE);
	}
	A[INT_LENGTH]=0;
	if(negflag)neg(A);
}
function power(a,b,x,ret,A)#return value(a**b%x)
{
	a%=x;
	if(a^b<1e15)return a^b%x;
	input_num(1%x,ret);
	input_num(a,A);
	while(b>0)
	{
		if(b%2==1)
		{
			mul(ret,A);
			mod_num(ret,x);
			b--;
		}
		mul(A,A);
		mod_num(A,x);
		b/=2;
	}
	return to_str(ret);
}
