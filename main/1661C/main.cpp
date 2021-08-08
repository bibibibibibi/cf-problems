#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int a[MAXN];
void solve()
{
	int n;
	ll sum[2]={},cnt[2]={},mx[2]={};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]%2]+=a[i];
		cnt[a[i]%2]++;
		mx[a[i]%2]=max(mx[a[i]%2],(ll)a[i]);
	}
	ll ans=1e18;
	ll tar,tmp,odd,even,det;
	// odd
	tar=max(mx[0]+1,mx[1]);
	even=(tar*cnt[1]-sum[1])/2+(tar*cnt[0]-(sum[0]+cnt[0]))/2;
	odd=cnt[0];
	det=max(0LL,(even-odd)/3);
	odd+=det<<1;
	even-=det;
	ans=min(ans,max((odd<<1)-1,even<<1));
	odd+=2;
	even-=1;
	ans=min(ans,max((odd<<1)-1,even<<1));
	// even
	tar=max(mx[0],mx[1]+1);
	even=(tar*cnt[0]-sum[0])/2+(tar*cnt[1]-(sum[1]+cnt[1]))/2;
	odd=cnt[1];
	det=max(0LL,(even-odd)/3);
	odd+=det<<1;
	even-=det;
	ans=min(ans,max((odd<<1)-1,even<<1));
	odd+=2;
	even-=1;
	ans=min(ans,max((odd<<1)-1,even<<1));
	printf("%lld\n",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
}