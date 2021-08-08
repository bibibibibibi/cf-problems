#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
struct seg
{
	#define lson l,mid,rt<<1
	#define rson mid+1,r,rt<<1|1
	ll tr[MAXN<<2],lz[MAXN<<2];
	void push_down(int rt)
	{
		if(lz[rt])
		{
			tr[rt<<1]+=lz[rt];
			tr[rt<<1|1]+=lz[rt];
			lz[rt<<1]+=lz[rt];
			lz[rt<<1|1]+=lz[rt];
			lz[rt]=0;
		}
	}
	void push_up(int rt)
	{
		tr[rt]=max(tr[rt<<1],tr[rt<<1|1]);
	}
	void init(int l,int r,int rt)
	{
		tr[rt]=0;
		if(l==r)
			return ;
		int mid=(l+r)>>1;
		init(lson);
		init(rson);
	}
	void update(int L,int R,ll v,int l,int r,int rt)
	{
		if(L<=l&&r<=R)
		{
			lz[rt]+=v;
			tr[rt]+=v;
			return ;
		}
		int mid=(l+r)>>1;
		push_down(rt);
		if(L<=mid)
			update(L,R,v,lson);
		if(mid<R)
			update(L,R,v,rson);
		push_up(rt);
	}
	ll query(int pos,int l,int r,int rt)
	{
		if(l==r)
			return tr[rt];
		int mid=(l+r)>>1;
		push_down(rt);
		if(pos<=mid)
			return query(pos,lson);
		if(mid<pos)
			return query(pos,rson);
	}
}se;
struct node
{
	int l,r,col;
	node(int _l=0,int _r=0,int _col=0):l(_l),r(_r),col(_col){}
	bool operator < (const node &o) const
	{
		if(r==o.r)
			return l<o.l;
		return r<o.r;
	}
	bool operator == (const node &o) const
	{
		return (l==o.l)&&(r==o.r);
	}
};
set<node> seg;
ll lazy[MAXN];
int n,q;
void split(int l,int r,int c)
{
	node L=*seg.lower_bound(node(0,l,0));
	node R=*seg.lower_bound(node(0,r,0));
	if(L==R)
	{
		if(L.l!=l)
			seg.insert(node(L.l,l-1,L.col));
		if(R.r!=r)
			seg.insert(node(r+1,R.r,R.col));
		seg.insert(node(l,r,c));
		se.update(l,r,lazy[L.col]-lazy[c],1,n,1);
		seg.erase(L);
	}
	else
	{
		if(L.l!=l)
			seg.insert(node(L.l,l-1,L.col));
		seg.insert(node(l,L.r,c));
		se.update(l,L.r,lazy[L.col]-lazy[c],1,n,1);
		if(R.r!=r)
			seg.insert(node(r+1,R.r,R.col));
		seg.insert(node(R.l,r,c));
		se.update(R.l,r,lazy[R.col]-lazy[c],1,n,1);
		seg.erase(L);
		seg.erase(R);
	}
}
void merge(int l,int r,int c)
{
	auto it=seg.lower_bound(node(0,l,0));
	while(it!=seg.end()&&it->r<=r)
	{
		se.update(it->l,it->r,lazy[it->col]-lazy[c],1,n,1);
		it=seg.erase(it);
	}
	seg.insert(node(l,r,c));
}
int main()
{
	scanf("%d%d",&n,&q);
	se.init(1,n,1);
	seg.insert(node(1,n,1));
	while(q--)
	{
		char op[10];
		scanf("%s",op);
		if(op[0]=='A')
		{
			int c,x;
			scanf("%d%d",&c,&x);
			lazy[c]+=x;
		}
		if(op[0]=='C')
		{
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			split(l,r,c);
			merge(l,r,c);
		}
		if(op[0]=='Q')
		{
			int pos;
			scanf("%d",&pos);
			int c=seg.lower_bound(node(0,pos,0))->col;
			printf("%lld\n",se.query(pos,1,n,1)+lazy[c]);
		}
	}
}