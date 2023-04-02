#pragma once
//construct SA by SA-IS O(N)
#include<string>
#include<vector>
struct SA{
	string s;
	vector<int>sa;
	SA(const string&s_):s(s_)
	{
		//forall i, 1 <= s[i] < maxval
		sa=build(vector<int>(s.begin(),s.end()),256);
	}
	vector<int>induced_sort(const vector<int>&S,const vector<int>&id,const vector<bool>&SL,vector<int>last)
	{
		vector<int>first(last);
		vector<int>ret(id.size());
		ret[0]=id[0];
		for(int i=0;i<id.size();i++)
		{
			if(id[i]>=1&&!SL[id[i]-1])
			{
				ret[first[S[id[i]-1]-1]++]=id[i]-1;
			}
			else if(ret[i]>=1&&!SL[ret[i]-1])
			{
				ret[first[S[ret[i]-1]-1]++]=ret[i]-1;
			}
		}
		for(int i=id.size();i--;)
		{
			if(ret[i]>=1&&SL[ret[i]-1])
			{
				ret[--last[S[ret[i]-1]]]=ret[i]-1;
			}
		}
		return ret;
	}
	vector<int>build(vector<int>S,int maxval)
	{
		if(S.size()<=1)
		{
			return S.empty()?(vector<int>){0}:(vector<int>){1,0};
		}
		S.push_back(0);
		vector<int>cnt(maxval,0);
		vector<bool>SL(S.size());//S=>true,L=>false
		for(int i=S.size();i--;)
		{
			cnt[S[i]]+=1;
			SL[i]=i+1==S.size()||S[i]<S[i+1]||S[i]==S[i+1]&&SL[i+1];
		}
		for(int i=1;i<maxval;i++)cnt[i]+=cnt[i-1];
		vector<int>last(cnt);
		vector<int>id(S.size());
		vector<int>is_LMS(S.size());
		int LMScnt=0;
		for(int i=1;i<S.size();i++)
		{
			if(!SL[i-1]&&SL[i])
			{
				is_LMS[i]=1;
				id[--cnt[S[i]]]=i;
				LMScnt+=1;
			}
		}
		id=induced_sort(S,id,SL,last);
		int LMSsub=1;
		int pre=-1;
		is_LMS[id[0]]=LMSsub++;
		for(int i=1;i<id.size();i++)
		{
			if(is_LMS[id[i]])
			{
				if(pre>=0&&S[pre]==S[id[i]])
				{
					int k;
					for(k=1;S[pre+k]==S[id[i]+k]&&!is_LMS[pre+k]&&!is_LMS[id[i]+k];k++);
					LMSsub-=S[pre+k]==S[id[i]+k]&&is_LMS[pre+k]&&is_LMS[id[i]+k];
				}
				pre=id[i];
				is_LMS[id[i]]=LMSsub++;
			}
		}
		vector<int>newstr(LMScnt);
		vector<int>rev(LMScnt);
		int counter=0;
		for(int i=0;i<S.size();i++)
		{
			if(is_LMS[i])
			{
				newstr[counter]=is_LMS[i];
				rev[counter]=i;
				counter+=1;
			}
		}
		vector<int>sortedLMS=build(newstr,LMSsub);
		id.assign(S.size(),0);
		for(int i=1;i<sortedLMS.size();i++)
		{
			int I=rev[sortedLMS[i]];
			id[cnt[S[I]]++]=I;
		}
		return induced_sort(S,id,SL,last);
	}
	int operator[](int i)const{return sa[i];}
	int lower_bound(const string&t)const
	{
		int L=-1,R=sa.size();
		while(R-L>1)
		{
			int M=L+R>>1;
			if(s.compare(sa[M],t.size(),t)>=0)R=M;
			else L=M;
		}
		return R;
	}
	int upper_bound(const string&t)const
	{
		int L=-1,R=sa.size();
		while(R-L>1)
		{
			int M=L+R>>1;
			if(s.compare(sa[M],t.size(),t)<=0)L=M;
			else R=M;
		}
		return R;
	}
	bool contain(const string&t)const
	{
		int id=lower_bound(t);
		return id<sa.size()&&s.compare(sa[id],t.size(),t)==0;
	}
	int size()const{return sa.size();}
};
