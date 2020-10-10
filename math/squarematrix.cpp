#include<array>
template<typename T,unsigned int N>
struct Matrix{
	using arr=array<T,N>;
	using mat=array<arr,N>;
	mat dat;
	Matrix():dat(){}
	arr&operator[](unsigned int i){return dat[i];}
	const arr&operator[](unsigned int i)const{return dat[i];}
	static Matrix eye(){
		Matrix res;
		for(int i=0;i<N;i++)res[i][i]=1;
		return res;
	}
	Matrix operator+(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			res[i][j]=dat[i][j]+A[i][j];
		return res;
	}
	Matrix operator*(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)
			res[i][j]+=dat[i][k]*A[k][j];
		return res;
	}
	Matrix pow(long long n)const{
		Matrix a=*this,res=eye();
		for(;n;a=a*a,n>>=1)if(n&1)res=res*a;
		return res;
	}
};
