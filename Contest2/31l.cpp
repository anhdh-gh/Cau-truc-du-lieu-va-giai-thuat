#include<bits/stdc++.h>
using namespace std;

long long k,n,m;
string s[1000];
vector<string>res;
char a[5][5];
bool ok[5][5],check;
long long X[]={-1,-1,-1,0,0,1,1,1};
long long Y[]={-1,0,1,-1,1,-1,0,1};

void init()
{
	cin>>k>>m>>n;
	for(long long i = 0 ; i < k ; i++)
		cin>>s[i];
	for(long long i = 1 ; i <= m ; i++)
		for(long long j = 1 ; j <= n ; j++)
			cin>>a[i][j];
	res.clear();
}

void TRY(long long i,long long j,string tmp)
{
	for(long long l = 0 ; l < k ; l++)
		if(s[l]==tmp) res.push_back(tmp);
	for(long long l = 0 ; l < 8 ; l++)
	{
		long long x = i+ X[l];
		long long y = j+ Y[l];
		if(x >= 1 && y >= 1 && x <= m && y <= n && !ok[x][y])
		{
			ok[x][y] = true;
			TRY(x,y,tmp+a[x][y]);
			ok[x][y] = false;
		}
	}
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		init();
		for(long long i = 1 ; i <= n ; i++)
			for(long long j = 1 ; j <= n ; j++)
			{
				memset(ok,false,sizeof(ok));
				string s="";
				ok[i][j]=true;
				TRY(i,j,s+a[i][j]);
			}
		if(res.size()==0) cout<<-1;
		else 
			for(long long i = 0 ; i < res.size() ; i++)
				cout<<res[i]<<" ";
		cout<<endl;
	}
}

