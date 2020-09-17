long long floor_sum(long long N,long long M,long long A,long long B)
//Sum[floor((A*i+B)/M),{i,0,N-1}]
{
	long long ans=0;
	if(A>=M)
	{
		ans+=N*(N-1)/2*(A/M);
		A%=M;
	}
	if(B>=M)
	{
		ans+=N*(B/M);
		B%=M;
	}
	long long Ym=(A*N+B)/M,Xm=Ym*M-B;
	if(Ym==0)return ans;
	ans+=(N-(Xm+A-1)/A)*Ym;
	ans+=floor_sum(Ym,A,M,(A-Xm%A)%A);
	return ans;
}
