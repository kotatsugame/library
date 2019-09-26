#include<vector>
long long invmod(long long a,long long m)
{
	long long s=a%m,t=m,sx=1,sy=0,tx=0,ty=1;
	while(s%t!=0)
	{
		long long f=s/t;
		long long u=s-t*f,ux=sx-tx*f,uy=sy-ty*f;
		s=t,sx=tx,sy=ty;
		t=u,tx=ux,ty=uy;
	}
	if(tx<0)tx+=m;
	return tx;
}
long long garner(const vector<long long>&x,const vector<long long>&m,const int mod=0)//*=x mod m
{
	if(x.empty())return 0LL;
	vector<long long>v(x.size());
	v[0]=x[0];
	for(int i=1;i<x.size();i++)
	{
		long long X=(x[i]-x[0])%m[i];
		long long M=1;
		for(int j=0;j<i-1;j++)
		{
			(M*=m[j])%=m[i];
			(X-=v[j+1]*M)%=m[i];
		}
		(M*=m[i-1])%=m[i];
		if(X<0)X+=m[i];
		v[i]=X*invmod(M,m[i])%m[i];
	}
	long long ret=v[0],p=1;
	if(mod==0)
	{
		for(int i=1;i<x.size();i++)
		{
			p*=m[i-1];
			ret+=p*v[i];
		}
	}
	else
	{
		ret%=mod;
		for(int i=1;i<x.size();i++)
		{
			(p*=m[i-1])%=mod;
			(ret+=p*v[i])%=mod;
		}
	}
	return ret;
}
#include<algorithm>
long long garner_helper(vector<int>A,vector<int>B,const int mod=0,bool zero=true)//allow zero?
//make B disjoint. NA => -1
{
	vector<int>primes;
	for(int i=0;i<A.size();i++)
	{
		int b=B[i];
		for(int j=2;j*j<=b;j++)
		{
			if(b%j==0)
			{
				primes.push_back(j);
				while(b%j==0)b/=j;
			}
		}
		if(b>1)primes.push_back(b);
	}
	sort(primes.begin(),primes.end());
	primes.erase(unique(primes.begin(),primes.end()),primes.end());
	vector<long long>a,b;
	bool flag=!zero;
	long long ret=1;
	for(int p:primes)
	{
		int ma=1,res;
		vector<pair<int,int> >x;
		for(int i=0;i<A.size();i++)
		{
			if(B[i]%p==0)
			{
				int t=1;
				while(B[i]%p==0)
				{
					B[i]/=p;
					t*=p;
				}
				x.push_back(make_pair(t,A[i]%t));
				if(ma<t)ma=t,res=x.back().second;
				A[i]%=B[i];
			}
		}
		for(pair<int,int>q:x)
		{
			if(res%q.first!=q.second)return-1;
		}
		a.push_back(res);
		b.push_back(ma);
		flag&=res==0;
		if(flag)
		{
			ret*=ma;
			if(mod!=0)ret%=mod;
		}
	}
	if(!flag)ret=garner(a,b,mod);
	return ret;
}
