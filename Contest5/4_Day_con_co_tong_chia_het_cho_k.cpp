#include<bits/stdc++.h>

using namespace std;

int F[1005][1005];	//chon ptu A[] 1->i, day con dai nhat trong bang j
int A[1005],k,n;
int dp()
{
	//co so
	memset(F,-k-1,sizeof(F));
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=k-1;j++)
//		{
//			cout<<F[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	F[0][0]=0;
	//truy hoi
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k-1;j++)
		{
			F[i][j]=max(F[i-1][j], F[i-1][(j-A[i]+k)%k] + 1);
		}
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=k-1;j++)
//		{
//			cout<<F[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return F[n][0];
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		//khoi tao
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>A[i];
			A[i]%=k;
		}	
//		for(int i=1;i<=n;i++)	cout<<A[i]<<' ';
//		cout<<endl;
		//
		cout<<dp()<<endl;
	}
}
