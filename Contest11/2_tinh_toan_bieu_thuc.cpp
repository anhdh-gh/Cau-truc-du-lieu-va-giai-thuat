#include<bits/stdc++.h>
using namespace std;

// Use array
// Vi day la cay nhi phan day du (moi node co 2 node con va muc cua lá = nhau)
// Node i se co 2 node con o vi tri: (2*i+1) va (2*i+2)
// Node lá: la cac toan hang => Luon o cuoi cung
// Node trung gian: La cac toan tu
// Nhin vao cay va input => Se hieu thuat toan
int tinh(int a,int b,string tt)
{
	if(tt=="+") return a+b;
	if(tt=="-") return a-b;
	if(tt=="*") return a*b;
	if(tt=="/") return a/b;
}

string process(vector<string>a)
{
	// Tim vi tri toan tu cuoi cung
	int i = a.size()-1; 
	while(a[i]!="+"&&a[i]!="-"&&a[i]!="*"&&a[i]!="/") i--;
	// Tinh toan
	while(i>=0) a[i--] = to_string(tinh(stoi(a[2*i+1]),stoi(a[2*i+2]),a[i]));
	return a[0];
}

main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<string>a(n);
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		cout<<process(a)<<endl;
	}
}
