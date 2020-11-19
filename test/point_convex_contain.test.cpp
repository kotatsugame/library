#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412"
using namespace std;
#include"point.hpp"
int main()
{
	int N;cin>>N;
	Polygon P(N);
	for(int i=0;i<N;i++)cin>>P[i];
	int Q;cin>>Q;
	for(;Q--;)
	{
		Point p;cin>>p;
		p.x*=1-1e-4;
		p.y*=1-1e-4;
		int t=convex_contain(P,p);
		cout<<(t==ON?-1:t==IN?1:0)<<endl;
	}
}
