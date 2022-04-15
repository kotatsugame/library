#include<vector>
template<typename T>
struct combination{
	vector<T>fac,ifac;
	combination(size_t N=0):fac(1,1),ifac(1,1)
	{
		make_table(N);
	}
	void make_table(size_t N)
	{
		if(fac.size()>N)return;
		size_t now=fac.size();
		N=max(N,now*2);
		fac.resize(N+1);
		ifac.resize(N+1);
		for(size_t i=now;i<=N;i++)fac[i]=fac[i-1]*i;
		ifac[N]=1/fac[N];
		for(size_t i=N;i-->now;)ifac[i]=ifac[i+1]*(i+1);
	}
	T factorial(size_t n)
	{
		make_table(n);
		return fac[n];
	}
	T invfac(size_t n)
	{
		make_table(n);
		return ifac[n];
	}
	T P(size_t n,size_t k)
	{
		if(n<k)return 0;
		make_table(n);
		return fac[n]*ifac[n-k];
	}
	T C(size_t n,size_t k)
	{
		if(n<k)return 0;
		make_table(n);
		return fac[n]*ifac[n-k]*ifac[k];
	}
	T H(size_t n,size_t k)
	{
		if(n==0)return k==0?1:0;
		return C(n-1+k,k);
	}
};
