#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
//https://www.geeksforgeeks.org/minimum-steps-required-to-reach-the-end-of-a-matrix-set-2/
int m,n,a[1005][1005],daxet[1005][1005],i,j;
void nhap()
{
	cin>>m>>n;
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < n ; j++)
			cin>>a[i][j];
}

long long process()
{
	// Queue - BFS;
	//          row,colum
	queue<pair<int,int> >q;
	q.push({0,0});	
	// Mang danh dau tat ca nhung o da xet va cap nhat ket qua
	memset(daxet,-1,sizeof(daxet));
	daxet[0][0] = 0;
	while(!q.empty() && daxet[m-1][n-1] == -1)
	{
		i =  q.front().first;
		j = q.front().second;
		q.pop();
		if(daxet[i][j+a[i][j]] == -1 && j+a[i][j] < n)
		{
			daxet[i][j+a[i][j]] = daxet[i][j]+1;
			q.push({i,j+a[i][j]});
		}
		if(daxet[i+a[i][j]][j] == -1 && i+a[i][j] < m)
		{
			daxet[i+a[i][j]][j] = daxet[i][j]+1;
			q.push({i+a[i][j],j});
		}
	}
	return daxet[m-1][n-1];
}

main()
{
 	faster()
	int T;
	cin>>T;
	while(T--)
	{
		nhap();
		cout<<process()<<endl;
	}
}
