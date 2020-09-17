#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include<iostream>
using namespace std;
#include"../string/SA_doubling.cpp"
int main()
{
	string s;
	SA P(s);
	for(int i=1;i<P.size();i++)cout<<P[i]<<(i+1==P.size()?"\n":" ");
}
