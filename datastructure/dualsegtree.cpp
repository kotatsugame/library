#include<vector>
#include<functional>
template<typename T>
struct dualsegtree{
	using F=function<T(T,T)>;
	const F lazycalcfn,updatefn;
	int n;
	T lazydefvalue;
	vector<T>dat,lazy;
	vector<bool>lazyflag;
	dualsegtree(int n_=0,T defvalue=0,
		const F lazycalcfn_=[](T a,T b){return a+b;},
		const F updatefn_=[](T a,T b){return a+b;},
		T lazydefvalue_=0
	):lazydefvalue(lazydefvalue_),
		lazycalcfn(lazycalcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(n,defvalue);
		lazy.assign(n-1,lazydefvalue);
		lazyflag.assign(n-1,false);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i]=v[i];
		lazy.assign(n-1,lazydefvalue);
		lazyflag.assign(n-1,false);
	}
	void update(int a,int b,T x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			if(k<n-1)
			{
				lazy[k]=lazycalcfn(lazy[k],x);
				lazyflag[k]=true;
			}
			else dat[k-n+1]=updatefn(dat[k-n+1],x);
		}
		else
		{
			if(lazyflag[k])
			{
				update(0,n,lazy[k],k*2+1,l,(l+r)/2);
				update(0,n,lazy[k],k*2+2,(l+r)/2,r);
				lazy[k]=lazydefvalue;
				lazyflag[k]=false;
			}
			update(a,b,x,k*2+1,l,(l+r)/2);
			update(a,b,x,k*2+2,(l+r)/2,r);
		}
	}
	T query(int i)
	{
		T ret=dat[i];
		i+=n-1;
		while(i>0)
		{
			i=(i-1)/2;
			if(lazyflag[i])ret=updatefn(ret,lazy[i]);
		}
		return ret;
	}
};
