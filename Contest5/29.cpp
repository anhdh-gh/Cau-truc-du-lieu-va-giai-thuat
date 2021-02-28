#include <bits/stdc++.h>

using namespace std;
int n;
int F[50];

int dp(string s)
{
	memset(F,0,sizeof(F));
	int n=s.length();
	if(s[0]=='0')	return 0;
	
	F[0]=1; F[1]=1;
	for(int i=2; i<=n; i++)
	{
		if(s[i-1] != '0')	F[i]=F[i-1];
		
		if(s[i-2] == '1' || (s[i-2]=='2' && s[i-1] <'7'))
			F[i]=F[i]+F[i-2];	//=F[i-1[ +F[i-2]
	}
	return F[n];
}

int main()
{
	int t; string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<dp(s)<<endl;
	}
}
