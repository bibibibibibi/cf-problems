#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int a[MAXN];
void solve()
{
	int n;
	ll x,y;
	scanf("%d%lld%lld",&n,&x,&y);
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if((x^y^sum)&1)
		puts("Bob");
	else
		puts("Alice");
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