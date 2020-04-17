//Disjoint Sparse Table
#include<vector>
#include<functional>
template<typename T>
struct DST{
	function<T(T,T)>calcfn;
	int n;
	vector<vector<T> >dat;
	DST(const vector<T>&v={},
		function<T(T,T)>calcfn_=[](T a,T b){return a<b?a:b;}
	):calcfn(calcfn_)
	{
		n=v.size();
		dat.push_back(v);
		for(int i=2;i<n;i<<=1)
		{
			dat.push_back(vector<T>(n));
			for(int j=i;j<n;j+=i<<1)
			{
				dat.back()[j-1]=dat[0][j-1];
				for(int k=2;k<=i;k++)
				{
					dat.back()[j-k]=calcfn(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=calcfn(dat.back()[j+k-2],dat[0][j+k-1]);
				}
			}
		}
	}
	T query(int l,int r)const//[l,r)
	{
		if(l<0)l=0;
		if(r>n)r=n;
		r--;
		if(l==r)return dat[0][l];
		int k=31-__builtin_clz(l^r);
		return calcfn(dat[k][l],dat[k][r]);
	}
};
