#include<bits/stdc++.h>
using namespace std;
// Co huong Khac voi do thi vo huong: 1->2,2->1 tao thanh 1 chu trinh
//=> Khong can quan tam den dinh truoc no la dinh gi
int T,v,e,x,y,daxet[1005];
vector<vector<int> >ke;

int dfs(int u)
{
	stack<int>st;
	st.push(u);
	daxet[u] = 1;
	while(!st.empty())
	{
		x = st.top();
		st.pop();
		for(int i = 0 ; i < ke[x].size() ; i++)
		{
			y = ke[x][i];
			if(daxet[y]==0)
			{
				daxet[y] = 1;
				st.push(x);
				st.push(y);
				break;	
			}	
			else if(y==u) return 1;
		}	
	}
	return 0;
}

int tim_chu_trinh()
{
	for(int i = 1 ; i <= v ; i++)
	{
		memset(daxet,0,sizeof(daxet));
		if(dfs(i)==1) return 1;
	}
	return 0;
}

//int ok;
//int dfs(int u,int t)
//{
//	if(ok==1) return 1;
//	daxet[u] = 1;
//	for(int i = 0 ; i < ke[u].size() ; i++)
//	{
//		if(ok==1) return 1;
//		y = ke[u][i];
//		if(daxet[y]==0) dfs(y,t);
//		else if(y==t) {ok = 1;return 1;}
//	}	
//	return 0;
//}
//
//int tim_chu_trinh()
//{
//	for(int i = 1 ; i <= v ; i++)
//	{
//		ok = 0;
//		memset(daxet,0,sizeof(daxet));
//		if(dfs(i,i)==1) return 1;
//	}
//	return 0;
//}

main()
{
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		ke.clear();
		ke.resize(1005);
		while(e--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
		}
		if(tim_chu_trinh()==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}
