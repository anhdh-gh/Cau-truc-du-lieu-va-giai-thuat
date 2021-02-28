#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int a,b,c,daxet[35][35][35],u,v,t;
char in[35][35][35];

int di[]={0,0,0,0,1,-1};
int dj[]={0,0,1,-1,0,0};
int dk[]={1,-1,0,0,0,0};

struct node{
	int cc;
	int cd;
	int cr;
};

int process()
{
	queue<node>q;
	cin>>a>>b>>c;
	for(int i = 0 ; i < a ; i++)
		for(int j = 0 ; j < b ; j++)
			for(int k = 0 ; k < c ; k++)
			{
				cin>>in[i][j][k];
				if(in[i][j][k]=='S') 
				{
					q.push({i,j,k});
					daxet[i][j][k] = 0;
				}
				else if(in[i][j][k] == '#')
					daxet[i][j][k] = -2;
				else // . or E
					daxet[i][j][k] = -1;
			}	
	while(!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if(in[tmp.cc][tmp.cd][tmp.cr] == 'E') 
			return daxet[tmp.cc][tmp.cd][tmp.cr];
		for(int i = 0 ; i < 6 ; i++)
		{
			u = tmp.cc + di[i]; 
			v = tmp.cd + dj[i]; 
			t = tmp.cr + dk[i];
			if(daxet[u][v][t] == -1 && u >= 0 && v >= 0 && t >= 0 && u < a && v < b && t < c)
			{
				daxet[u][v][t] = daxet[tmp.cc][tmp.cd][tmp.cr]+1;
				q.push({u,v,t});
			}
		}
	}	
	return -1;
}

main()
{
	faster()
	int T;
	cin>>T;
	while(T--)
		cout<<process()<<endl;		
}
