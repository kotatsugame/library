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
	T det()const
	{
		assert(N==M);
		Matrix A=*this;
		T ret=1;
		for(int j=0;j<N;j++)
		{
			int id=-1;
			for(int i=j;i<N;i++)
			{
				if(A[i][j]!=0)
				{
					id=i;
					break;
				}
			}
			if(id==-1)return T(0);
			if(id!=j)
			{
				swap(A[j],A[id]);
				ret=-ret;
			}
			ret*=A[j][j];
			for(int k=j+1;k<N;k++)A[j][k]/=A[j][j];
			for(int i=j+1;i<N;i++)
			{
				const T a=A[i][j];
				for(int k=j+1;k<N;k++)A[i][k]-=A[j][k]*a;
			}
		}
		return ret;
	}
	int elimination()
	{
		int ret=0;
		for(int j=0;j<M;j++)
		{
			int id=-1;
			for(int i=ret;i<N;i++)
			{
				if(dat[i][j]!=0)
				{
					id=i;
					break;
				}
			}
			if(id==-1)continue;
			if(id!=ret)swap(dat[ret],dat[id]);
			{
				const T a=dat[ret][j];
				for(int k=j;k<M;k++)dat[ret][k]/=a;
			}
			for(int i=0;i<N;i++)
			{
				if(i==ret)continue;
				const T a=dat[i][j];
				for(int k=j;k<M;k++)dat[i][k]-=dat[ret][k]*a;
			}
			ret++;
		}
		return ret;
	}
};
