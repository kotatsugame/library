#include<vector>
template<typename T,T(*op)(T,T)>
struct segtree_2D{
	int H,W;
	const T e;
	vector<vector<T> >dat;
	segtree_2D(int H_,int W_,T e_):e(e_)
	{
		H=W=1;
		while(H<H_)H<<=1;
		while(W<W_)W<<=1;
		dat.assign(2*H-1,vector<T>(2*W-1,e));
	}
	void copy(const vector<vector<T> >&v)
	{
		for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<v[i].size();j++)dat[i+H-1][j+W-1]=v[i][j];
			for(int j=W-2;j>=0;j--)dat[i+H-1][j]=op(dat[i+H-1][j*2+1],dat[i+H-1][j*2+2]);
		}
		for(int i=H-2;i>=0;i--)
		{
			for(int j=0;j<2*W-1;j++)dat[i][j]=op(dat[i*2+1][j],dat[i*2+2][j]);
		}
	}
	T get(int i,int j)const{return dat[i+H-1][j+W-1];}
	void set(int i,int j,T a)
	{
		i+=H-1;
		j+=W-1;
		dat[i][j]=a;
		{
			int nj=j;
			while(nj>0)
			{
				nj=(nj-1)/2;
				dat[i][nj]=op(dat[i][nj*2+1],dat[i][nj*2+2]);
			}
		}
		while(i>0)
		{
			i=(i-1)/2;
			int nj=j;
			dat[i][nj]=op(dat[i*2+1][nj],dat[i*2+2][nj]);
			while(nj>0)
			{
				nj=(nj-1)/2;
				dat[i][nj]=op(dat[i*2+1][nj],dat[i*2+2][nj]);
			}
		}
	}
	T prod(int hl,int wl,int hr,int wr)//[hl,hr)x[wl,wr)
	{
		if(hl<0)hl=0;if(hl>H)hl=H;
		if(hr<0)hr=0;if(hr>H)hr=H;
		if(wl<0)wl=0;if(wl>W)wl=W;
		if(wr<0)wr=0;if(wr>W)wr=W;
		hl+=H-1;hr+=H-1;
		wl+=W-1;wr+=W-1;
		T ret=e;
		for(;hl<hr;hl>>=1,hr>>=1)
		{
			if(!(hl&1))
			{
				int L=wl,R=wr;
				for(;L<R;L>>=1,R>>=1)
				{
					if(!(L&1))ret=op(ret,dat[hl][L]);
					if(!(R&1))ret=op(ret,dat[hl][--R]);
				}
			}
			if(!(hr&1))
			{
				hr--;
				int L=wl,R=wr;
				for(;L<R;L>>=1,R>>=1)
				{
					if(!(L&1))ret=op(ret,dat[hr][L]);
					if(!(R&1))ret=op(ret,dat[hr][--R]);
				}
			}
		}
		return ret;
	}
};
