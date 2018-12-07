#include<array>
#include<vector>
#include<functional>
template<int char_size>
struct trie{
	struct node{
		array<int,char_size>next;
		int id;
		node():id(-1){next.fill(-1);}
	};
	vector<node>v;
	function<int(int)>f;
	trie(function<int(int)>_f):f(_f){v.push_back(node());}
	bool add(const string&s,int idx)
	{
		int p=0;
		for(int i=0;i<s.size();i++)
		{
			int j=f(s[i]);
			if(v[p].next[j]<0)
			{
				v[p].next[j]=v.size();
				v.push_back(node());
			}
			p=v[p].next[j];
		}
		if(v[p].id>=0)return false;
		v[p].id=idx;
		return true;
	}
	bool find(const string&s)
	{
		int p=0;
		for(int i=0;i<s.size();i++)
		{
			int j=f(s[i]);
			if(v[p].next[j]<0)return false;
			p=v[p].next[j];
		}
		return true;
	}
};
