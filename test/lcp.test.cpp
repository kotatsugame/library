#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include<iostream>
using namespace std;
#include"../string/SA_IS.cpp"
#include"../string/LCP.cpp"
int main()
{
	string s;cin>>s;
	SA P(s);
	LCP Q(s);
	long ans=0;
	for(int i=0;i<Q.size();i++)ans+=i+1-Q[i];
	cout<<ans<<endl;
}
