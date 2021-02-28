#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int T,V,E,x,y,daxet[1005],trai[1005],phai[1005];
vector<vector<int> >ke;

int bfs(int s)
{
	trai[s] = 1;
	queue<int>q;
	q.push(s);
	daxet[s] = 1;
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		for(int i = 0 ; i < ke[s].size() ; i++)
			if(daxet[ke[s][i]]==0)
			{
				daxet[ke[s][i]] = 1;
				q.push(ke[s][i]);
				if(trai[s]==1) phai[ke[s][i]] = 1;
				else trai[ke[s][i]] = 1;
			}
			else if((trai[s]==1&&trai[ke[s][i]]==1)||(phai[s]==1&&phai[ke[s][i]]==1)) return 0;
	}
}

// Kiem tra do thi hai phia
string process()
{
	memset(daxet,0,sizeof(daxet));
	memset(trai,0,sizeof(trai));
	memset(phai,0,sizeof(phai));
	for(int i = 1 ; i <= V ; i++)
		if(daxet[i]==0 && bfs(i)==0) return "NO";
	return "YES";
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		ke.clear();
		ke.resize(1005);
		cin>>V>>E;
		while(E--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		cout<<process()<<endl;
	}
}
