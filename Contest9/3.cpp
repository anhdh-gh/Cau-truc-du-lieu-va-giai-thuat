#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

main()
{
 	faster()
	int n,x;
	cin>>n;
	vector<vector<int> >res(n);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
		{
			cin>>x;		
			if(x==1) res[i].push_back(j+1);	
		}	
	for(int i = 0 ; i < res.size() ; i++)
	{
		for(int j = 0 ; j < res[i].size() ; j++)
			cout<<res[i][j]<<" ";
		cout<<endl;	
	}	
}
