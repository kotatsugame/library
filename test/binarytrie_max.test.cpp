#define PROBLEM "https://old.yosupo.jp/problem/set_xor_min"
#include<iostream>
#include<set>
using namespace std;
#include"binarytrie.hpp"
int main()
{
	binarytrie<30>P;
	set<int>S;
	int Q;cin>>Q;
	int XOR=(1<<30)-1;
	for(;Q--;)
	{
		int t,x;cin>>t>>x;
		if(t==0)
		{
			if(S.find(x)==S.end())
			{
				P.insert(x);
				S.insert(x);
			}
		}
		else if(t==1)
		{
			if(S.find(x)!=S.end())
			{
				P.erase(x);
				S.erase(x);
			}
		}
		else
		{
			cout<<P.max(x^XOR)^XOR<<endl;
		}
	}
}
