#include<complex>
#include<vector>
void dft(vector<complex<double> >&A,int sign)
{
	int N=A.size()>>1;
	if(N==0)return;
	vector<complex<double> >F(N),G(N);
	for(int i=0;i<N;i++)
	{
		F[i]=A[i<<1];
		G[i]=A[i<<1|1];
	}
	dft(F,sign);
	dft(G,sign);
	complex<double>z(cos(M_PI/N),sin(M_PI/N)*sign),p=1;
	for(int i=0;i<N;i++)
	{
		A[i]=F[i]+p*G[i];
		A[i+N]=F[i]-p*G[i];
		p*=z;
	}
}
vector<long long>multiply(const vector<int>&A,const vector<int>&B)
{
	if(A.empty()&&B.empty())
	{
		return(vector<long long>){};
	}
	int N=1;
	vector<long long>ret(A.size()+B.size()-1);
	while(N<ret.size())N<<=1;
	vector<complex<double> >F(N),G(N);
	for(int i=0;i<A.size();i++)F[i]=A[i];
	for(int i=0;i<B.size();i++)G[i]=B[i];
	dft(F,1);
	dft(G,1);
	for(int i=0;i<N;i++)F[i]*=G[i];
	dft(F,-1);
	for(int i=0;i<ret.size();i++)ret[i]=llround((F[i]/=N).real());
	return ret;
}
