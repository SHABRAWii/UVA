#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
#define ll long long 

bool DB = 0;
string str;
ll mem[1000][1000];
ll Solve(int i = 0, int j = str.size() - 1){
	if(i >= j)
		return 0;

	ll &ret = mem[i][j];
	if(~ret)
		return ret;
	ll ch1 = min({Solve(i + 1, j) + 1, Solve(i, j - 1) + 1, Solve(i + 1, j - 1) + (str[i] != str[j])}); 

	return ret = ch1;
}

int main(){ 
	#ifdef VS_FreeOpen 
		freopen("input.in", "r", stdin); 
		freopen("output.in", "w", stdout); 
		DB = 0;
	#endif 
	FIO; 

	int tc = 1, ctc = 0;
	cin >> tc;
	while(tc-- && ++ctc){
		memset(mem, -1, sizeof(mem));
		cin >> str;
		cout << "Case " << ctc << ": " << Solve() << endl;
		
	}

	return 0;
}
/*

*/
