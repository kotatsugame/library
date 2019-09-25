//construct SA by doubling O(N(log N)^2)
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
struct SA{
	string s;
	vector<int>sa,rank;
	SA(const string&s_):s(s_)
	{
		int n=s.size();
		sa.resize(n+1);
		rank.resize(n+1);
		for(int i=0;i<=n;i++)
		{
			sa[i]=i;
			rank[i]=i<n?s[i]:-1;
		}
		for(int k=1;k<=n;k<<=1)
		{
			vector<int>tmp(rank);
			function<bool(int,int)>f=[&tmp,&k,&n](int i,int j){
				return tmp[i]!=tmp[j]?tmp[i]<tmp[j]:
					(i+k<=n?tmp[i+k]:-1)<(j+k<=n?tmp[j+k]:-1);
			};
			sort(sa.begin(),sa.end(),f);
			rank[sa[0]]=0;
			for(int i=1;i<=n;i++)
			{
				rank[sa[i]]=rank[sa[i-1]]+f(sa[i-1],sa[i]);
			}
		}
	}
	int operator[](int i){return sa[i];}
	int lower_bound(const string&t)
	{
		int L=-1,R=sa.size();
		while(R-L>1)
		{
			int M=L+R>>1;
			if(s.compare(sa[M],t.size(),t)>=0)R=M;
			else L=M;
		}
		return R;
	}
	int upper_bound(const string&t)
	{
		int L=-1,R=sa.size();
		while(R-L>1)
		{
			int M=L+R>>1;
			if(s.compare(sa[M],t.size(),t)<=0)L=M;
			else R=M;
		}
		return R;
	}
	bool contain(const string&t)
	{
		int id=lower_bound(t);
		return id<sa.size()&&s.compare(sa[id],t.size(),t)==0;
	}
	int size(){return sa.size();}
};
