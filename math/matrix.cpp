#include<vector>
#include<cassert>
template<typename T>
struct Matrix{
	vector<vector<T> >dat;
	int N,M;//N x M matrix
	Matrix(){}
	Matrix(int N_):Matrix(N_,N_){}
	Matrix(int N_,int M_):N(N_),M(M_),dat(N_,vector<T>(M_)){}
	vector<T>&operator[](int i){return dat[i];}
	const vector<T>&operator[](int i)const{return dat[i];}
	static Matrix eye(int N)
	{
		Matrix res(N);
		for(int i=0;i<N;i++)res[i][i]=1;
		return res;
	}
	Matrix operator+(const Matrix&A)const
	{
		assert(N==A.N&&M==A.M);
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]+A[i][j];
		return res;
	}
	Matrix operator-(const Matrix&A)const
	{
		assert(N==A.N&&M==A.M);
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]-A[i][j];
		return res;
	}
	Matrix operator*(const Matrix&A)const
	{
		assert(M==A.N);
		Matrix res(N,A.M);
		for(int i=0;i<N;i++)for(int j=0;j<A.M;j++)for(int k=0;k<M;k++)
			res[i][j]+=dat[i][k]*A[k][j];
		return res;
	}
	Matrix pow(long long n)const
	{
		assert(N==M);
		Matrix a=*this,res=eye(N);
		for(;n;a=a*a,n>>=1)if(n&1)res=res*a;
		return res;
	}
	template<typename U>
	Matrix operator+(const U&A)const
	{
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]+A;
		return res;
	}
	template<typename U>
	Matrix operator-(const U&A)const
	{
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]-A;
		return res;
	}
	template<typename U>
	Matrix operator*(const U&A)const
	{
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]*A;
		return res;
	}
	T det()const{
		assert(N==M);
		Matrix A=*this;
		T ret=1;
		for(int i=0;i<N;i++)
		{
			int id=-1;
			for(int j=i;j<N;j++)
			{
				if(A[j][i]!=0)
				{
					id=j;
					break;
				}
			}
			if(id==-1)return T(0);
			if(id!=i)
			{
				swap(A[i],A[id]);
				ret*=-1;
			}
			ret*=A[i][i];
			for(int j=i+1;j<N;j++)A[i][j]/=A[i][i];
			for(int j=i+1;j<N;j++)
			{
				const T a=A[j][i];
				for(int k=i+1;k<N;k++)A[j][k]-=A[i][k]*a;
			}
		}
		return ret;
	}
};
