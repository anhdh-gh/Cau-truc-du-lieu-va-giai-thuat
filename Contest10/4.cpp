#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int danhdau[1005][1005];
pair<int,int>S,T;

int is_safe(int i,int j)
{
	if(i>=1 && j>=1 && i<=n && j<=m && a[i][j]!='*' && danhdau[i][j]==-1) return 1;
	return 0;
}

string process()
{
	queue<pair<int,int>>q;
	q.push(S);
	while(!q.empty())
	{
		S = q.front();
		q.pop();
		if(danhdau[S.first][S.second]>2) continue;
		if(S == T) return "YES";
		for(int i = 0 ; i < 4 ; i++)
		{
			int x = S.first+dx[i];
			int y = S.second+dy[i];
			while(is_safe(x,y)==1)
			{
				q.push({x,y});
				danhdau[x][y] = danhdau[S.first][S.second]+1;
				x = x + dx[i];
				y = y + dy[i];
			}
		}
	}
	return "NO";
}

main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
			{
				danhdau[i][j] = -1;
				cin>>a[i][j];
				if(a[i][j]=='S') 
				{
					a[i][j] = '*';
					S.first = i;
					S.second = j;
				}
				if(a[i][j]=='T')
				{
					T.first = i;
					T.second = j;
				}
			}
		cout<<process()<<endl;
	}	
}
