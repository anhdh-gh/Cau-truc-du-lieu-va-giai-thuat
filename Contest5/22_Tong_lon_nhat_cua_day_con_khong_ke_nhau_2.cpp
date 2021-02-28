//WAAAAAAAAAAAAAAAAA
#include<bits/stdc++.h>
using namespace std;
int a[100005],  n;
long long c[100005];

int dp(int a[], int n)
{
	memset(c,0,sizeof(c));
	//th co so
	c[1]=a[1];
	c[2]=max(a[1],a[2]);
	//
	for(int i=3;i<=n;i++)
	{
		//		chon a[i]	//khong chon a[i]
		c[i]=max(c[i-2]+a[i], c[i-1]);
	}
	return c[n];
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i];
		cout<<dp(a,n)<<endl;
	}
	
}
