#include<vector>
#include<string>
vector<int>manacher(const string&s)
{
	vector<int>ret(s.size());
	int i=0,j=0;
	while(i<s.size())
	{
		while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j])j++;
		ret[i]=j;
		int k=1;
		while(i-k>=0&&i+k<s.size()&&k+ret[i-k]<j)ret[i+k]=ret[i-k],k++;
		i+=k;j-=k;
	}
	return ret;
}
