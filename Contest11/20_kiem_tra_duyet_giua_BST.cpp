#include<bits/stdc++.h>
using namespace std;

//Idea: Ket qua duyet sau cua BST luon la 1 array tang dan tu nho den lon
int check(vector<int>a)
{
	for(int i = 0 ; i < a.size()-1 ; i++)
		if(a[i] >= a[i+1]) return 0;
	return 1;
}

main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>a(n);
		for(int i = 0 ; i < n ; i++)
			cin>>a[i];
		cout<<check(a)<<endl;
	}
}
