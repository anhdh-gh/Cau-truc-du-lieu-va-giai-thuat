#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int T,V,E,x,y,daxet[1005];
vector<vector<int> >ke;

int Hamilton(int s,int dem)
{
	if(dem == V) return 1;
	for(int i = 0 ; i < ke[s].size() ; i++)
		if(daxet[ke[s][i]] == 0) 
		{
			daxet[ke[s][i]] = 1;
			if(Hamilton(ke[s][i],dem+1)) return 1;
			daxet[ke[s][i]] = 0;
		}
	return 0;
}

int hmt()
{
	for(int i = 1 ; i <= V ; i++)
	{
		memset(daxet,0,sizeof(daxet));
		daxet[i] = 1;
		if(Hamilton(i,1)==1) return 1;
	}
	return 0;
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>V>>E;
		ke.clear();
		ke.resize(1005);
		while(E--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		cout<<hmt()<<endl;
	}
}
