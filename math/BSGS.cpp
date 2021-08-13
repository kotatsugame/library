#include<vector>
#include<algorithm>
int BSGS(long long X,long long Y,const int P0)
//k s.t. X^k=Y mod P or -1
//0^0=1
{
	X%=P0;
	Y%=P0;
	if(P0==1)return 0;
	if(X==0)return Y==1?0:Y==0?1:-1;
	int g=1;
	for(int i=P0;i>1;i>>=1)g=g*X%P0;
	//gcd
	for(int p=P0;p;)
	{
		int t=g%p;
		g=p;
		p=t;
	}
	int t=1,fst=0;
	while(t%g)
	{
		if(t==Y)return fst;
		t=t*X%P0;
		fst++;
	}
	if(Y%g)return -1;
	t/=g;
	Y/=g;
	const int P=P0/g;
	int sqP=0,Xm=1;
	while(sqP*sqP<P)
	{
		Xm=Xm*X%P;
		sqP++;
	}
	vector<pair<int,int> >tb(sqP);
	for(int i=0,e=Y;i<sqP;i++)
	{
		e=e*X%P;
		tb[i]=make_pair(e,-i-1);
	}
	sort(tb.begin(),tb.end());
	for(int s=0,e=t;s<P;)
	{
		e=(long)e*Xm%P;
		s+=sqP;
		vector<pair<int,int> >::iterator it=lower_bound(tb.begin(),tb.end(),make_pair(e,-sqP));
		if(it!=tb.end()&&it->first==e)return fst+s+it->second;
	}
	return -1;
}
