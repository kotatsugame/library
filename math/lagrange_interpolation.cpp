#include<vector>
template<typename T>
T lagrange_interpolation(const vector<T>&y,T x)
{
	int N=y.size();
	if(N==0)return T(0);
	vector<T>fac(N),invfac(N);
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	invfac[N-1]=1/fac[N-1];
	for(int i=N-1;i--;)invfac[i]=invfac[i+1]*(i+1);
	vector<T>L(N),R(N);
	L[0]=1;
	for(int i=1;i<N;i++)L[i]=L[i-1]*(x-(i-1));
	R[N-1]=1;
	for(int i=N-1;i--;)R[i]=R[i+1]*(x-(i+1));
	T ret=0;
	for(int i=0;i<N;i++)
	{
		T now=L[i]*R[i]*invfac[i]*invfac[N-i-1]*y[i];
		if(N-i&1)ret+=now;
		else ret-=now;
	}
	return ret;
}
