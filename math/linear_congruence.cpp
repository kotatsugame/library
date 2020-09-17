//require extgcd
#include<vector>
#include"extgcd.cpp"
pair<long long,long long>linear_congruence(const vector<int>&A,const vector<int>&B,const vector<int>&M)
//find Ax=B mod M. NA=>(0,-1)
{
	long long x=0,m=1;
	for(int i=0;i<A.size();i++)
	{
		long long a=m*A[i],b=B[i]-x*A[i],u,v;
		long long d=extgcd(a,(long long)M[i],u,v);
		if(b%d!=0)return make_pair(0LL,-1LL);
		long long t=b/d*u%(M[i]/d);
		x+=m*t;
		m*=M[i]/d;
	}
	x%=m;
	if(x<0)x+=m;
	return make_pair(x,m);
}
