/*
mo ta thuat toan:
duyet tu dau den cuoi day
gia su [=1   ]=0
tang count khi gap 1 va giam khi gap 0
neu count < 0 thi phai doi cho 0 voi 1-gan-nhat-tiep-theo
vi doi phep ke nen so buoc doi = vi_tri_1 - vi_tri_0
reset count=1
s:   1 0 0 0 0 0 0 1
pos: 0 1 2 3 4 5 6 7
s:   1 0 (0) 0 0 0 0 (1)
pos: 0 1  2  3 4 5 6  7
=>can 7-2 buoc doi
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string s;
void solve()
{
	vector<int> pos_1;	//luu vi tri [
	int count = 0;	//bien dem so nguac
	int p_1 = 0;		//pos_1[p_1] = vi tri [ tiep theo 
	int res = 0;		//ket qua

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '[') {
			pos_1.push_back(i);
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[') {
			count++;
			p_1++;
		}
		else {		//=']'
			count--;
		}

		if (count < 0)
		{
			res += pos_1[p_1] - i;
			swap(s[i], s[pos_1[p_1]]);
			p_1++;
			count = 1;
		}
	}
	cout << res << endl;
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> s;
		solve();
	}
}
