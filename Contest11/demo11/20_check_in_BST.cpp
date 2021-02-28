#include<bits/stdc++.h>
using namespace std;

int is_in_BST(vector<int>in)
{
	for(int i = 0 ; i < in.size()-1 ; i++)
		if(in[i] >= in[i+1]) return 0;
	return 1; 
}

main()
{
	int T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>in;
		while(n--){cin>>x;in.push_back(x);}
		cout<<is_in_BST(in)<<endl;
	}
}
