#define PROBLEM "https://yukicoder.me/problems/no/184"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"matrix.hpp"
using mint=modint<2>;
using Mat=Matrix<mint>;
int main()
{
	int N;
	cin>>N;
	Mat A(N,61);
	for(int i=0;i<N;i++)
	{
		long a;cin>>a;
		for(int j=0;j<61;j++)
		{
			A[i][j]=a%2;
			a/=2;
		}
	}
	cout<<(1LL<<A.elimination())<<endl;
}
