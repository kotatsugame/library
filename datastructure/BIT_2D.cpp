//0-indexed
#include<vector>
#include<cassert>
template<typename T>
struct BIT_2D{
	int H,W;
	vector<vector<T> >bit;
	BIT_2D(int H_=0,int W_=0):H(H_),W(W_),bit(H,vector<T>(W)){}
	T sum(int i,int j)
	{
		assert(0<=i&&i<=H);
		assert(0<=j&&j<=W);
		T ans=0;
		for(;i>0;i-=i&-i)
			for(int nj=j;nj>0;nj-=nj&-nj)ans+=bit[i-1][nj-1];
		return ans;
	}
	void add(int i,int j,T a)
	{
		assert(0<=i&&i<H);
		assert(0<=j&&j<W);
		i++;j++;
		for(;i<=H;i+=i&-i)
			for(int nj=j;nj<=W;nj+=nj&-nj)bit[i-1][nj-1]+=a;
	}
};
