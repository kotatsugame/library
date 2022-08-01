#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
using namespace std;
#include"integer_point.hpp"
int main()
{
	int N;
	cin>>N;
	vector<Point>P(N);
	for(int i=0;i<N;i++)cin>>P[i];
	sort(P.begin(),P.end(),argless);
	for(int i=0;i<N;i++)cout<<P[i]<<endl;
}
