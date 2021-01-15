#define PROBLEM "https://yukicoder.me/problems/no/1073"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"squarematrix.hpp"
using mint=modint<(int)1e9+7>;
using Mat=Matrix<mint,6>;
int main()
{
	long N;cin>>N;
	Mat A;
	for(int i=0;i<6;i++)A[0][i]=mint(6).inv();
	for(int i=0;i<5;i++)A[i+1][i]=1;
	A=A.pow(N);
	cout<<A[0][0]<<endl;
}
