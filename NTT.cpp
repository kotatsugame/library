//998244353,3
//469762049,3
//167772161,3
#include<vector>
template<int mod,int proot>
struct NTT{
	vector<long long>pp,invpp;//memoize proot^(mod-1>>i) and inv
	long long power(long long a,int b)
	{
		long long ret=1;
		while(b)
		{
			if(b&1)ret=ret*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return ret;
	}
	void dft(vector<int>&A,bool sign,int id)
	{
		if(id==0)return;
		int N=1<<id-1;
		vector<int>F(N),G(N);
		for(int i=0;i<N;i++)
		{
			F[i]=A[i<<1];
			G[i]=A[i<<1|1];
		}
		dft(F,sign,id-1);
		dft(G,sign,id-1);
		long long z=(sign?invpp:pp)[id],p=1;
		for(int i=0;i<N;i++)
		{
			A[i]=(F[i]+p*G[i])%mod;
			A[i+N]=(F[i]-p*G[i])%mod;
			if(A[i+N]<0)A[i+N]+=mod;
			(p*=z)%=mod;
		}
	}
	vector<int>multiply(vector<int>A,vector<int>B)
	{
		if(A.empty()||B.empty())
		{
			return(vector<int>){};
		}
		int N=1,sz=0;
		vector<int>ret(A.size()+B.size()-1);
		while(N<ret.size())N<<=1,sz+=1;
		pp.resize(sz+1);
		invpp.resize(sz+1);
		pp[sz]=power(proot,mod-1>>sz);
		invpp[sz]=power(pp[sz],mod-2);
		for(int i=sz-1;i>0;i-=1)
		{
			pp[i]=pp[i+1]*pp[i+1]%mod;
			invpp[i]=invpp[i+1]*invpp[i+1]%mod;
		}
		A.resize(N);
		B.resize(N);
		dft(A,false,sz);
		dft(B,false,sz);
		for(int i=0;i<N;i++)A[i]=(long long)A[i]*B[i]%mod;
		dft(A,true,sz);
		long long invN=power(N,mod-2);
		for(int i=0;i<ret.size();i++)ret[i]=invN*A[i]%mod;
		return ret;
	}
};
