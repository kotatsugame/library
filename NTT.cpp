//998244353,3
#include<vector>
template<int mod,int proot>
struct NTT{
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
	void dft(vector<int>&A,bool sign)
	{
		int N=A.size()>>1;
		if(N==0)return;
		vector<int>F(N),G(N);
		for(int i=0;i<N;i++)
		{
			F[i]=A[i<<1];
			G[i]=A[i<<1|1];
		}
		dft(F,sign);
		dft(G,sign);
		long long z=power(proot,sign?(long long)(mod-1)/N/2*(mod-2)%(mod-1):(mod-1)/N/2),p=1;
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
		int N=1;
		vector<int>ret(A.size()+B.size()-1);
		while(N<ret.size())N<<=1;
		A.resize(N);
		B.resize(N);
		dft(A,false);
		dft(B,false);
		for(int i=0;i<N;i++)A[i]=(long long)A[i]*B[i]%mod;
		dft(A,true);
		long long invN=power(N,mod-2);
		for(int i=0;i<ret.size();i++)ret[i]=invN*A[i]%mod;
		return ret;
	}
};
