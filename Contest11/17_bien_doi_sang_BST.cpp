#include<bits/stdc++.h>
using namespace std;

main()
{
	int T,n,u,v;
	char x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>a;
		while(n--)
		{
			cin>>u>>v>>x;
			if(find(a.begin(),a.end(),u)==a.end()) 
				a.push_back(u);
			if(find(a.begin(),a.end(),v)==a.end()) 
				a.push_back(v);			
		}
		stable_sort(a.begin(),a.end());
		for(int i = 0 ; i < a.size() ; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
