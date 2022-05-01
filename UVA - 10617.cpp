#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 

int n = 0;
string str;
ll mem[60][60];
ll Solve(int l, int r){
    if(l > r)
        return 0;
    if(l == r)
        return 1;

    ll &ret = mem[l][r];
    if(~ret)
        return ret;

    ll ch1 = 0;
    if(str[l] == str[r])
        ch1 += 1 + Solve(l + 1, r - 1); // empty pal
    ch1 += Solve(l + 1, r);
    ch1 += Solve(l, r - 1);
    ch1 -= Solve(l + 1, r - 1);
    
    return ret = ch1;
}

int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 

    int tc = 0;
    cin >> tc;
    while(tc--){
        memset(mem, -1, sizeof(mem));
        cin >> str;
        cout << Solve(0, str.size() - 1) << endl;
    }
    

    return 0; 
}
