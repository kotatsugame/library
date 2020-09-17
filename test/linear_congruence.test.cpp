#define PROBLEM "https://yukicoder.me/problems/no/186"
#include<iostream>
using namespace std;
#include"../math/linear_congruence.cpp"
int main()
{
	vector<int>r(3),m(3);
	for(int i=0;i<3;i++)cin>>r[i]>>m[i];
	pair<long,long>p=linear_congruence({1,1,1},r,m);
	if(p.second==-1)cout<<-1<<endl;
	else cout<<(p.first==0?p.second:p.first)<<endl;
}
