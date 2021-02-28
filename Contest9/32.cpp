#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
//https://www.geeksforgeeks.org/find-number-of-islands/
//https://www.geeksforgeeks.org/islands-in-a-graph-using-bfs/
//https://www.geeksforgeeks.org/find-the-number-of-islands-set-2-using-disjoint-set/?ref=rp
//https://www.geeksforgeeks.org/find-the-number-of-distinct-islands-in-a-2d-matrix/?ref=rp
// Idea: 
// Di chuyen sang 8 o canh nhau roi danh dau va dem
int T,n,m,a[1005][1005],daxet[1005][1005];
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

int is_safe(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m&&daxet[x][y]==0&&a[x][y]==1)
		return 1;
	return 0;
}

void dfs(int x,int y)
{
	daxet[x][y] = 1;
	for(int i = 0 ; i < 8 ; i++)
		if(is_safe(x+dx[i],y+dy[i])==1)
			dfs(x+dx[i],y+dy[i]);
}

int count_island()
{
	int count = 0;
	memset(daxet,0,sizeof(daxet));
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(a[i][j]==1 && daxet[i][j] == 0)
			{
				dfs(i,j);
				count++;
			}
	return count;
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
				cin>>a[i][j];
		cout<<count_island()<<endl;
	}
}
