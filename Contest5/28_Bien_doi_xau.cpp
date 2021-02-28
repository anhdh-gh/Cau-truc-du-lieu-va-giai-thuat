#include<bits/stdc++.h>

using namespace std;

int F[1005][1005];

int dp(string str1, string str2)
{
	int m=str1.length();	//hang
	int n=str2.length();	//cot
	//co so
		//hang 0
	for(int i=0;i<=n;i++)	F[0][i]=i;
		//cot 0
	for(int i=1;i<=m;i++)	F[i][0]=i;
	
	//truy hoi
	for(int i=1;i<=m;i++)
	{
		for(int j=1; j<=n;j++)
		{
			//coi vi tri xau tu 1->n
			if(str1[i-1]==str2[j-1])	F[i][j]=F[i-1][j-1];
			else F[i][j]=min(min(F[i][j-1], F[i-1][j-1]), F[i-1][j]) + 1;
		}
	}
	return F[m][n];
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		string str1, str2;		//bien str1 thanh str2
		cin>>str1>>str2;
		cout<<dp(str1, str2)<<endl;
	}
}
