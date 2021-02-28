#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int n,i,j,x,y,u,v,daxet[1005][1005];
char a[105][105];

main()
{
	// Input
 	faster()
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin>>a[i][j];
	cin>>x>>y>>u>>v;
	//Output
	memset(daxet,-1,sizeof(daxet));
	daxet[x][y] = 0;
			// row,colum
	queue<pair<int,int> >q;
	q.push({x,y});
	while(!q.empty() && daxet[u][v] == -1)
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		// Co dinh hang, tinh tien cot sang ben phai
		for(int k = j+1 ; k < n ; k++)
			if(a[i][k]=='X') break;
			else if(daxet[i][k]==-1)
			{
				daxet[i][k] = daxet[i][j]+1;
				q.push({i,k});
			}
		// Co dinh hang, tinh tien cot sang ben trai
		for(int k = j-1 ; k >= 0 ; k--)
			if(a[i][k]=='X') break;
			else if(daxet[i][k]==-1)
			{
				daxet[i][k] = daxet[i][j]+1;
				q.push({i,k});
			}		
		// Co dinh cot, tinh tien hang len tren
		for(int k = i-1 ; k >= 0 ; k--)
			if(a[k][j]=='X') break;
			else if(daxet[k][j]==-1)
			{
				daxet[k][j] = daxet[i][j]+1;
				q.push({k,j});
			}
		// Co dinh cot, tinh tien hang xuong duoi
		for(int k = i+1 ; k < n ; k++)
			if(a[k][j]=='X') break;
			else if(daxet[k][j]==-1)
			{
				daxet[k][j] = daxet[i][j]+1;
				q.push({k,j});
			}		
	}
	cout<<daxet[u][v];
}
