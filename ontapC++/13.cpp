#include <iostream>
#include <map>
#include<vector>
#include<algorithm>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  // giup code nhanh hon vi khong can dong bo
using namespace std;

bool kt(long long a)
{
	while(a!=0)
	{
		long long m = a%10;
		if(m!=2 && m!=3 && m!=5 && m!=7) return false;
		a /= 10;
	}
	return true;
}

bool comp(pair<long long,pair<long long,long long> >a, pair<long long,pair<long long,long long> >b)
{
	return a.second.second < b.second.second;
}

void solve()
{
	long long a,t = 0;
	map<long long,pair <long long,long long> > count;
	// input
	while(cin>>a) 				 
	{							//Neu a la string thi khi nao gap eof(as: crlt + Z) se dung lai 
		t++;					// Neu a la int thi khi nao gap ki tu khac ( or khong co so nao nua ) no se dung lai
		if(kt(a)==true)         
		{
			count[a].first++;
			if(count[a].second == 0) count[a].second = t; 
		}
	}			
	// output
	vector<pair<long long,pair<long long,long long> > >b;
	map<long long,pair<long long,long long> > :: iterator it;
	for(it = count.begin() ; it != count.end() ; it++)
		b.push_back(make_pair(it->first,it->second));
	sort(b.begin(),b.end(),comp);
	for(long long i = 0 ; i < b.size() ; i++)
		cout<<b[i].first<<" "<<b[i].second.first<<endl;	
}

int main()
{
	faster();
	solve();
	return 0;
}
//		map<long long,pair<long long,long long> > :: iterator it;
//		for(it = count.begin() ; it != count.end() ; it++)
//			cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;	
//                key(phan tu)    value1(so lan)          value2(vi tri)
