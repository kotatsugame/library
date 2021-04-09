#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"combination.hpp"
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<combination<modint<(int)1e9+7> >().H(k,n)<<endl;
}
