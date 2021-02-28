#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// convert long long -> string
string l_s(long long a)
{
	ostringstream convert;
	convert<<a;
	string x = convert.str();
	return x;
}

bool kt(string a)
{
	sort(a.begin(),a.end());
	if(a[a.size()-1] > '5') return false;
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i] == a[i+1]) return false;	
	return true;
}

vector<long long>luu;
void init()
{
	long long b,temp;
	queue<long long>a;
	a.push(0);
	while(a.front() <= 100000)
	{
		b = a.front();a.pop();
		luu.push_back(b);
		for(long long i = 0 ; i <= 5 ; i++)
		{
			temp = b*10+i;
			if(temp!=0&&kt(l_s(temp))==true) a.push(b*10+i);
		}	
	}
}

long long process(long long l,long long r)
{
	long long i,j;
	for(i = 0 ; i < luu.size() ; i++)
		if(luu[i] >= l) break;
	for(j = luu.size()-1 ; j >= 0 ; j--)
		if(luu[j] <= r) break;		
	return j-i+1;
}

main()
{
	init();
 	faster()
	long long T,l,r;
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		cout<<process(l,r)<<endl;
	}
}
