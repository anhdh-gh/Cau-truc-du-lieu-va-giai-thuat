#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pair pair<int,int>
using namespace std;

int a[1005][1005];

void cut_string(int i,string temp)
{
	temp += " ";
	int so = 0;
	for(int j = 0 ; j < temp.size() ; j++)
		if(temp[j] >= '0' && temp[j] <= '9')
			so = so*10+(temp[j]-'0');
		else 
		{
			if(so > i)
			{
				a[i][so] = 1;
				a[so][i] = 1;
			}
			so = 0;
		}
}

main()
{
 	faster()
	int n;
	cin>>n;
	cin.ignore();
	string temp;
	memset(a,0,sizeof(a));
	for(int i = 1 ; i <= n ; i++)
	{
		getline(cin,temp);
		cut_string(i,temp);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
			cout<<a[i][j]<<" ";		
		cout<<endl;
	}
}
