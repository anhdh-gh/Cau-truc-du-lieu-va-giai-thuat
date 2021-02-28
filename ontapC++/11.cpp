#include<iostream>
#include<algorithm>
using namespace std;

string chuanhoa(string a)
{
	// xoa dau cach dau
	while(a[0]==' ') a.erase(a.begin());
	// xoa dau cah cuoi
	while(a[a.size()-1]==' ') a.erase(a.begin()+a.size()-1);
	// xao dau cach giua
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i]==' ' && a[i]==a[i+1]) a.erase(a.begin()+i--);
	// chuyen ve chu thuong ( chu hoa: toupper )
	transform(a.begin(),a.end(),a.begin(),::tolower);
	// chuyen cac chu cai dau ve chu hoa
	if(a[0] >= 'a' && a[a.size()-1] <= 'z') a[0] -= 32;
	for(long long i = 1 ; i < a.size() ; i++)
		if(a[i-1]==' ' && a[i] >= 'a' && a[i] <= 'z')
			a[i] -=32;
	// tach ho
	long long i;
	string c = ", ";
	for(i = 0 ; a[i]!=' ' ;i++)
		c.push_back(a[i]);
	a.erase(a.begin(),a.begin()+i+1); // xoa ho
	transform(c.begin(),c.end(),c.begin(),::toupper);
	a += c; // them ho vao cuoi
	return a;
}

int main()
{
	long long T;
	cin>>T;
	string a;
	cin.ignore();
	while(T--)
	{
		getline(cin,a);
		cout<<chuanhoa(a)<<endl;
	}
	return 0;
}
