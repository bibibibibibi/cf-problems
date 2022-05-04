#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int x1,p1,x2,p2;
	scanf("%d%d",&x1,&p1);
	scanf("%d%d",&x2,&p2);
	while(x1<1000000)
	{
		x1*=10;
		p1--;
	}
	while(x2<1000000)
	{
		x2*=10;
		p2--;
	}
	if(p1>p2)
	{
		puts(">");
		return ;
	}
	if(p1<p2)
	{
		puts("<");
		return ;
	}
	if(p1==p2)
	{
		if(x1>x2)
			puts(">");
		else if(x1<x2)
			puts("<");
		else
			puts("=");
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