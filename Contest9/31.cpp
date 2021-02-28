#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// Kiem tra do thi vo huong co phai la cay khong
// - Lien thong
// - Co dung n-1 canh
// - Giua hai dinh bat ki chi ton tai duy nhat 1 duong di giua chung
// Moi dinh u chi co duy nhat 1 dinh parent truoc no
// => Neu ke(u)(u da xet) != parent(u) => Tao nen 1 chu trinh => Khong phai la cay
// => Neu ke(u) == parent(u) => Khong tao nen 1 chu trinh
int T,n,x,y,daxet[1005];
vector<vector<int> >ke;

int dfs(int s,int parent)
{
	daxet[s] = 1;
	for(int i = 0 ; i < ke[s].size() ; i++)
		if(daxet[ke[s][i]]==0) dfs(ke[s][i],s);
		else if(ke[s][i] != parent) return 1; // co tao nen chu trinh
	return 0;
}

string check_tree()
{
	memset(daxet,0,sizeof(daxet));
	// goi dfs tu dinh 1 xem co tao nen chu trinh va lien thong khong
	if(dfs(1,0)==1) return "NO"; // khong la tree
	// Kiem tra xem co lien thong khong
	for(int i = 1 ; i <= n ; i++)
		if(daxet[i]==0) return "NO";
	return "YES";
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>n;
		ke.clear();
		ke.resize(1005);
		for(int i = 1 ; i <= n-1 ; i++)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		cout<<check_tree()<<endl;
	}
}
