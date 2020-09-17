//require NTT
#include"NTT.cpp"
vector<int>multiply(vector<int>A,vector<int>B,const int mod)
{
	for(int&a:A)
	{
		a%=mod;
		if(a<0)a+=mod;
	}
	for(int&b:B)
	{
		b%=mod;
		if(b<0)b+=mod;
	}
	vector<int>C1=NTT<998244353,3>().multiply(A,B);
	vector<int>C2=NTT<469762049,3>().multiply(A,B);
	vector<int>C3=NTT<167772161,3>().multiply(A,B);
	vector<int>C(C1.size());
	for(int i=0;i<C.size();i++)
	{
		long long v1=C1[i];
		long long v2=(C2[i]-v1)*208783132%469762049;
		if(v2<0)v2+=469762049;
		long long v3=(C3[i]-v1-v2*998244353)%167772161*29562547%167772161;
		if(v3<0)v3+=167772161;
		C[i]=(v1+(v2+v3*469762049)%mod*998244353)%mod;
	}
	return C;
}

