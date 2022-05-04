#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	int n,k;
	scanf("%d%d",&n,&k);
	cin>>s;
	if(k==0)
	{
		puts("1");
		return ;
	}
	bool flag=true;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[(int)s.size()-i-1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
		puts("1");
	else
		puts("2");
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