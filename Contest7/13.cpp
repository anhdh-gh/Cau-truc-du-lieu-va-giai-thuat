#include<bits/stdc++.h>
using namespace std;
//idea: 
// lap tu cuoi -> 0 cua chuoi bieu thuc tien to
// Neu s[i] la +-*/: s[i] = s[i+1] + s[i+2] + s[i] 
// Xoa di 2 phan tu s[i+1] va s[i+2]
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
	for(long long i = res.size()-1 ; i >= 0 ; i--)
		if(check_tt(res[i])==true)
		{
			res[i] = res[i+1]+res[i+2]+res[i];	
			// Xoa phan tu thu i va i+1
			res.erase(res.begin()+i+1,res.begin()+i+2+1);
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
