#define PROBLEM "https://yukicoder.me/problems/no/1105"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"matrix.hpp"
using mint=modint<(int)1e9+7>;
using Mat=Matrix<mint>;
int main()
{
	long N;cin>>N;
	Mat A=Mat::eye(3);
	A[0][1]=A[1][2]=A[2][0]=-1;
	A=A.pow(N-1);
	Mat b(3,1);
	for(int i=0;i<3;i++)cin>>b[i][0];
	A=A*b;
	for(int i=0;i<3;i++)cout<<A[i][0]<<(i==2?"\n":" ");
}
