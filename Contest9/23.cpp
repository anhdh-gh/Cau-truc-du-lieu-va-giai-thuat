#include<bits/stdc++.h>
using namespace std;
// Chu trinh: Quay lai dinh da xet se tao thanh chu trinh (!= dinh truoc no)
//Use DFS. Neu ma no ke voi dinh da xet 
// Ma khong phai la dinh truoc no
// => Tao thanh 1 chu trinh
// 1- 2, 2-1 khong phai la 1 chu trinh
int T,v,e,x,y,daxet[1005],truoc[1005];
vector<vector<int> >ke;

//int dfs(int s)
//{
//	daxet[s] = 1;
//	for(int i = 0 ; i < ke[s].size() ; i++)
//	{
//		x = ke[s][i];
//		if(daxet[x]==0)
//		{
//			truoc[x] = s;
//			dfs(x);
//		}		
//		else if(truoc[s]!=x) return 1;
//	}
//	return 0;
//}

int dfs(int s)
{
	daxet[s] = 1;
	truoc[s] = 0;
	stack<int>st;
	st.push(s);
	while(!st.empty())
	{
		s = st.top();
		st.pop();
		for(int i = 0 ; i < ke[s].size() ; i++)
		{
			x = ke[s][i];
			if(daxet[x]==0)
			{
				st.push(x);
				daxet[x] = 1;
				truoc[x] = s;
			}
			else if(truoc[s]!=x) return 1;
		}
	}
	return 0;
}

int tim_chu_trinh()
{
	// Phai xet tat ca cac dinh truong hop co nhieu thanh phan lien thong
	for(int i = 1 ; i <= v ; i++)
	{
		memset(daxet,0,sizeof(daxet));
		memset(truoc,0,sizeof(truoc));
		if(dfs(i)==1) return 1;
	}
	return 0;
}

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
			ke[y].push_back(x);
		}
		if(tim_chu_trinh()==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}
