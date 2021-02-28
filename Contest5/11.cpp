#include<bits/stdc++.h>
using namespace std;
// Xu ly so lon
void dongbo(string &a,string &b)
{
	if(a.size() > b.size()) swap(a,b);
	long long n = b.size()-a.size();
	while(n--) a = "0" + a;
	reverse(a.begin(),a.end()); // dao nguoc 
	reverse(b.begin(),b.end());
}

string sum(string a,string b)
{
	string res;
	dongbo(a,b);
	long long temp,nho = 0,n = a.size();
	for(long long i = 0 ; i < n; i++)
	{
		temp = (a[i]-'0')+(b[i]-'0')+nho;
		if(temp >= 10) {temp -= 10;nho = 1;}else nho = 0;
		res.push_back(temp+'0');
	}
	if(nho != 0) res.push_back('1');	
	reverse(res.begin(),res.end());
	return res;
}

string nhan(string a,string b)
{
	string res = "0";
	reverse(a.begin(),a.end()); 
	reverse(b.begin(),b.end());	
	for(long long i = 0 ;i < b.size() ; i++)
	{
		string s;
		long long temp,nho = 0;
		for(long long k = 1 ; k <= i ; k++) s += "0"; // Lui vao 1 o
		for(long long j = 0 ; j < a.size() ; j++)
		{
			temp = (b[i]-'0')*(a[j]-'0')+nho;
			if(temp >= 10)
			{
				char x[2];
				itoa(temp,x,10); // itoa(bien nguyen,mang luu,co so);
				nho = x[0]-'0';
				temp = x[1]-'0';
			}
			else nho = 0;
			s.push_back(temp+'0');
		}
		if(nho!=0) s.push_back(nho+'0');
		reverse(s.begin(),s.end());
		res = sum(res,s);
	}
	return res;
}

// c[i]: So catalan number thu i
string process(long long n)
{
	vector<string>c(n+1,"0");
	c[0] = "1";
	for(long long i = 1 ; i <= n ; i++)
		for(long long j = 0 ; j < i ; j++)
			c[i] = sum(c[i],nhan(c[j],c[i-j-1]));		
	return c[n];
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<process(n)<<endl;
	}
}
