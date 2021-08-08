#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1)
	{
		if(k==1)
		{
			puts("YES");
			puts("1");
			return ;
		}
		else
		{
			puts("NO");
			return ;
		}
	}
	if((n*k)&1)
	{
		if(k==1)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d\n",i);
			return ;
		}
		else
		{
			puts("NO");
			return ;
		}
	}
	if(((n*k)/2)%k!=0)
	{
		puts("NO");
		return ;
	}
	int odd=1,even=2;
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i&1)
			{
				printf("%d ",odd);
				odd+=2;
			}
			else
			{
				printf("%d ",even);
				even+=2;
			}
		}
		puts("");
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
}