#include<bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	m++;
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		int a=(n>>i)&1;
		int b=(m>>i)&1;
		if(a>b) break;
		else if(a==b) continue;
		else ans|=(1<<i);
	}
	printf("%d\n",ans);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
