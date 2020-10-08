//construct LCP O(N) require SA
#include"../include/SA.hpp"
struct LCP{
	vector<int>lcp;
	LCP(const SA&sa)
	{
		int n=sa.size()-1;
		lcp.assign(n,0);
		vector<int>rank(n+1);
		for(int i=0;i<=n;i++)rank[sa[i]]=i;
		int h=0;
		lcp[0]=0;
		for(int i=0;i<n;i++)
		{
			int j=sa[rank[i]-1];
			h-=h>0;
			for(;i+h<n&&j+h<n&&sa.s[i+h]==sa.s[j+h];h++);
			lcp[rank[i]-1]=h;
		}
	}
	int operator[](int i)const{return lcp[i];}
	int size()const{return lcp.size();}
};
