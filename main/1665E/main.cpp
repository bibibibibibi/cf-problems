#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct seg
{
	#define lson l,mid,rt<<1
	#define rson mid+1,r,rt<<1|1
	vector<int> tr[MAXN<<2];
	void push_up(int rt)
	{
		for(int i=0;i<min((int)tr[rt<<1].size(),31);i++)
			tr[rt].push_back(tr[rt<<1][i]);
		for(int i=0;i<min((int)tr[rt<<1|1].size(),31);i++)
			tr[rt].push_back(tr[rt<<1|1][i]);
		sort(tr[rt].begin(),tr[rt].end());
	}
	void init(int l,int r,int rt)
	{
		tr[rt].clear();
		if(l==r)
			return ;
		int mid=(l+r)>>1;
		init(lson);
		init(rson);
	}
	void build(int a[],int l,int r,int rt)
	{
		if(l==r)
		{
			tr[rt].push_back(a[l]);
			return ;
		}
		int mid=(l+r)>>1;
		build(a,lson);
		build(a,rson);
		push_up(rt);
	}
	void query(int L,int R,priority_queue<int> &Q,int l,int r,int rt)
	{
		if(L<=l&&r<=R)
		{
			for(int i=0;i<min((int)tr[rt].size(),31);i++)
			{
				int v=tr[rt][i];
				if(Q.size()<=31)
				{
					Q.push(v);
				}
				else if(Q.size()>31&&v<Q.top())
				{
					Q.pop();
					Q.push(v);
				}
			}
			return ;
		}
		int mid=(l+r)>>1;
		if(L<=mid)
			query(L,R,Q,lson);
		if(mid<R)
			query(L,R,Q,rson);
	}
}se;
int a[MAXN];
void solve()
{
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	se.init(1,n,1);
	se.build(a,1,n,1);
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		priority_queue<int> Q;
		se.query(l,r,Q,1,n,1);
		vector<int> vt;
		while(!Q.empty())
		{
			vt.push_back(Q.top());
			Q.pop();
		}
		int ans=2e9;
		for(int i=0;i<(int)vt.size();i++)
			for(int j=i+1;j<(int)vt.size();j++)
				ans=min(ans,vt[i]|vt[j]);
		printf("%d\n",ans);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}