#include<bits/stdc++.h>
using namespace std;
//idea: 
// lap tu 0 -> cuoi cua chuoi bieu thuc hau to
// Neu s[i] la +-*/: s[i] = s[i] + s[i-2] + s[i-1]
// Xoa hai phan tu s[i-1] va s[i-2]
// i -= 2
// Tiep tuc lap cho den khi chi con 1 phan tu
// Return bieu thuc hau to

bool check_tt(string x) //Kiem tra xem co phai la + - * / khong
{
	if(x == "+" || x == "-" || x == "*" || x == "/") return true;
	return false;
}

string process(string a)
{
	vector<string>res(a.size());
	for(long long i = 0 ; i < a.size() ; i++) //convert char -> string
		res[i] = a[i];
	for(long long i = 0 ; i < res.size() ; i++)
		if(check_tt(res[i])==true)
		{
			res[i] = res[i]+res[i-2]+res[i-1];	
			// Xoa phan tu thu i-1 va i-2
			res.erase(res.begin()+i-1);
			res.erase(res.begin()+i-2);
			i -= 2;
		}		
	return res[0];
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<process(a)<<endl;
	}
}
