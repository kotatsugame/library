#include<utility>
long long floor_sum(long long N,long long M,long long A,long long B)
//Sum[floor((A*i+B)/M),{i,0,N-1}]
{
	long long ans=0;
	if(B>=M)
	{
		ans+=N*(B/M);
		B%=M;
	}
	while(true)
	{
		ans+=N*(N-1)/2*(A/M);
		A%=M;
		long long Ym=(A*N+B)/M,Xm=Ym*M-B;
		if(Ym==0)return ans;
		long long TX=(Xm+A-1)/A;
		ans+=(N-TX)*Ym;
		N=Ym;
		B=TX*A-Xm;
		swap(A,M);
	}
}
