#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include<iostream>
using namespace std;
#include"string/Zalgo.cpp"
int main()
{
	string s;cin>>s;
	vector<int>A=Zalgo(s);
	for(int i=0;i<s.size();i++)cout<<A[i]<<(i+1==s.size()?"\n":" ");
}
