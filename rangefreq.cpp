#include<vector>
#include<algorithm>
template<typename T>
struct rangefreq{
	int n;
	vector<vector<T> >dat;
	rangefreq(const vector<T>&v={})
	{
		n=1;
		while(n<v.size())n<<=1;
		dat.assign(2*n-1,{});
		for(int i=0;i<v.size();i++)dat[i+n-1].push_back(v[i]);
		for(int i=n-2;i>=0;i--)
		{
			dat[i].resize(dat[i*2+1].size()+dat[i*2+2].size());
			merge(dat[i*2+1].begin(),dat[i*2+1].end(),
				dat[i*2+2].begin(),dat[i*2+2].end(),
				dat[i].begin()
			);
		}
	}
	int query(int a,int b,T x,int k=0,int l=0,int r=-1)//[a,b) count(*<x)
	{
		if(r<0)r=n;
		if(b<=l||r<=a)return 0;
		else if(a<=l&&r<=b)return lower_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
		else return query(a,b,x,k*2+1,l,(l+r)/2)+query(a,b,x,k*2+2,(l+r)/2,r);
	}
};
