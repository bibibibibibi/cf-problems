#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
map<ll,int> cnt;
ll a[MAXN];
bool dfs(ll now)
{
	if(cnt.find(now)!=cnt.end()&&cnt[now]>0)
	{
		cnt[now]--;
		return true;
	}
	if(now==1)
		return false;
	bool ret=dfs(now>>1);
	if(!ret) return false;
	return dfs(now-(now>>1));
}

void solve()
{
	int n;
	ll sum=0;
	scanf("%d",&n);
	cnt.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
		cnt[a[i]]++;
	}
	puts(dfs(sum)?"YES":"NO");
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