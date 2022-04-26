#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 
const int N = 10e4 + 4;
int n = 0;
int arr[N] = {};
int mem[N][100];
int Solve(int coin1, int coin2, int idx){
    if(idx == n)
        return abs(coin1 - coin2);
    int &ret = mem[coin1-coin2 + 50000][idx];
    if(~ret)
        return ret;
// first take
    int ch1 = Solve(coin1 + arr[idx], coin2, idx + 1);
// second take
    int ch2 = Solve(coin1, coin2 + arr[idx], idx + 1);
    
    return ret = min(ch1, ch2);
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
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
            cin >> arr[i];
        }
        cout << Solve(0, 0, 0) << endl;
    }

    return 0; 
}
