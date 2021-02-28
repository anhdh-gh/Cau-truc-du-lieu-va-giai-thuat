#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int T,V,E,m,x,y,mau[1005],danhdau;
vector<vector<int> >ke;

int check_mau(int s,int i)
{
	for(int j = 0 ; j < ke[s].size() ; j++)
		if(mau[ke[s][j]]==i) return 0;
	return 1;
}

void to_mau(int s)
{
	if(danhdau == 1) return;
	for(int i = 1 ; i <= m ; i++)
		if(check_mau(s,i)==1) 
		{
			mau[s] = i;
			if(s == V) danhdau = 1;
			else to_mau(s+1);
		}
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>V>>E>>m;
		ke.clear();
		ke.resize(1005);		
		while(E--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		memset(mau,0,sizeof(mau));
		danhdau = 0;
		to_mau(1);
		if(danhdau == 1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

// Lam theo khong de quy => Sai
//#include<bits/stdc++.h>
//#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
//using namespace std;
//
//int T,V,E,m,x,y,mau[1005];
//vector<vector<int> >ke;
//
//int check_mau(int s,int k)
//{
//	for(int i = 0 ; i < ke[s].size() ; i++)
//		if(mau[ke[s][i]]==k) return 0;
//	return 1;
//}
//
//string to_mau()
//{
//	memset(mau,0,sizeof(mau));
//	for(int i = 1 ; i <= V ; i++)
//	{
//		int j;
//		for(j = 1 ; j <= m ; j++)
//			if(check_mau(i,j)==1) 
//			{
//				mau[i] = j;
//				break;
//			}
//		if(j > m) return "NO";
//	}
//	return "YES";
//}
//
//main()
//{
// 	faster()
//	cin>>T;
//	while(T--)
//	{
//		cin>>V>>E>>m;
//		ke.clear();
//		ke.resize(1111);		
//		while(E--)
//		{
//			cin>>x>>y;
//			ke[x].push_back(y);
//			ke[y].push_back(x);
//		}
//		cout<<to_mau()<<endl;
//	}
//}
