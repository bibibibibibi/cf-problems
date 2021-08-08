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
	int n;
	scanf("%d",&n);
	string ans;
	for(int i=1;i<=n;i++)
		ans+='a';
	ans[n/2]='b';
	if(n&1) ans[n-1]='c';
	printf("%s\n",ans.c_str());
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
