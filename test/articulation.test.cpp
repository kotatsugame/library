#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1622"
#include<iostream>
#include<queue>
using namespace std;
#include"TECC.hpp"
int H,W;
string s[50];
bool vis[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
	int cnt=0;
	while(cin>>H>>W,H)
	{
		for(int i=0;i<H;i++)
		{
			cin>>s[i];
			for(int j=0;j<W;j++)vis[i][j]=false;
		}
		TECC P(H*W);
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(s[i][j]=='.')
		{
			if(i+1<H&&s[i+1][j]=='.')
			{
				P.add_edge(i*W+j,i*W+W+j);
			}
			if(j+1<W&&s[i][j+1]=='.')
			{
				P.add_edge(i*W+j,i*W+j+1);
			}
		}
		P.build();
		bool out=false;
		if(!(P[0]==P[W-1]&&P[0]==P[(H-1)*W]&&P[0]==P[(H-1)*W+W-1]))
		{
			out=true;
		}
		bridge Q(H*W);
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(P[0]==P[i*W+j])
		{
			if(i+1<H&&P[0]==P[(i+1)*W+j])
			{
				Q.add_edge(i*W+j,i*W+W+j);
			}
			if(j+1<W&&P[0]==P[i*W+j+1])
			{
				Q.add_edge(i*W+j,i*W+j+1);
			}
		}
		Q.build();
		queue<pair<int,int> >bfs;
		bfs.push(make_pair(0,0));
		vis[0][0]=true;
		while(!bfs.empty())
		{
			int x=bfs.front().first,y=bfs.front().second;
			bfs.pop();
			for(int r=0;r<4;r++)
			{
				int tx=x+dx[r],ty=y+dy[r];
				if(tx<0||ty<0||tx>=H||ty>=W||P[0]!=P[tx*W+ty]||Q[tx*W+ty]||vis[tx][ty])continue;
				vis[tx][ty]=true;
				bfs.push(make_pair(tx,ty));
			}
		}
		if(!vis[0][W-1]||!vis[H-1][0]||!vis[H-1][W-1])out=true;
		cout<<(out?"NO":"YES")<<endl;
	}
}
