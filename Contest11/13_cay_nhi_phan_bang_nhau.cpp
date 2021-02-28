#include<bits/stdc++.h>
#define iic pair<int,pair<int,char>>
#define u first
#define v second.first
#define x second.second
using namespace std;

int check(vector<iic>tree1,vector<iic>tree2)
{
	if(tree1.size() != tree2.size()) return 0;
	for(int i = 0 ; i < tree1.size() ; i++)
		if(find(tree2.begin(),tree2.end(),tree1[i])==tree2.end())
			return 0;
	return 1;		
}

main()
{
	int T,n1,n2,U,V;
	char X;
	cin>>T;
	while(T--)
	{
		vector<iic>tree1,tree2;
		cin>>n1;
		while(n1--)
		{
			cin>>U>>V>>X;
			tree1.push_back({U,{V,X}});
		}
		cin>>n2;
		while(n2--)
		{
			cin>>U>>V>>X;
			tree2.push_back({U,{V,X}});
		}		
		cout<<check(tree1,tree2)<<endl;
	}
}
