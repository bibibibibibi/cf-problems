#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MOD=998244353;
int dp[MAXN][MAXN],C[MAXN][MAXN];

int main()
{
	for(int i=0;i<MAXN;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	int n,x;
	scanf("%d%d",&n,&x);
	dp[n][0]=1;
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<x;j++)
		{
			for(int k=j;k<=x;k++)
		}
	}
}