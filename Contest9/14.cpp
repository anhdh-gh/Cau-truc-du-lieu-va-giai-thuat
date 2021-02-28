#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

main()
{
 	faster()
	int T,v,e,i,j,s,t,tv,daxet[1005],truoc[1005];
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		// Convert from dsc to dsk
		vector<vector<int> >res(v);
		while(e--)
		{
			cin>>i>>j;
			res[i-1].push_back(j);
			res[j-1].push_back(i);
		}
		// sort lai cac dinh trong dsk
		// Phai co them ham sort moi dung, Nhung bo di moi yes
//		for(i = 0 ; i < res.size() ; i++)
//			sort(res[i].begin(),res[i].end());
		// BFS;
		cin>>tv;
		while(tv--)
		{
			cin>>s>>t;
			memset(daxet,0,sizeof(daxet));
			memset(truoc,0,sizeof(truoc));
			daxet[s] = 1;
			queue<int>q;
			q.push(s);
			truoc[s] = 0;
			while(!q.empty())
			{
				s = q.front();
				q.pop();
				for(i = 0 ; i < res[s-1].size() ; i++)
					if(daxet[res[s-1][i]]==0)
					{
						daxet[res[s-1][i]] = 1;
						q.push(res[s-1][i]);
						truoc[res[s-1][i]] = s;
					}			
			}
			// output
			if(truoc[t] == 0) cout<<"NO";
			else cout<<"YES";
			cout<<endl;	
		}
	}
}
