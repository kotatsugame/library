//0-indexed
#include<vector>
#include<cassert>
template<typename T>
struct BIT{
	int N;
	vector<T>bit;
	BIT(int N_=0):N(N_),bit(N_){}
	T sum(int i)
	{
		assert(0<=i&&i<=N);
		T ans=0;
		for(;i>0;i-=i&-i)ans+=bit[i-1];
		return ans;
	}
	void add(int i,T a)
	{
		assert(0<=i&&i<N);
		i++;
		for(;i<=N;i+=i&-i)bit[i-1]+=a;
	}
	int lower_bound(T k)//k<=sum(ret)
	{
		if(k<=0)return 0;
		int ret=0,i=1;
		while((i<<1)<=N)i<<=1;
		for(;i;i>>=1)
		{
			if(ret+i<=N&&bit[ret+i-1]<k)
			{
				ret+=i;
				k-=bit[ret-1];
			}
		}
		return ret+1;
		//ret+1 == N+1 <=> sum<k
	}
};
