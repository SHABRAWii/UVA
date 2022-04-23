#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 



int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 
    int n = 0;
    cin >> n;
    ll com[n + 1][n + 1] = {};
    for(int r = 1 ; r <= n ; ++r){
        for(int c = 1 ; c <= n ; ++c){
            int inp = 0;
            cin >> inp;
            com[r][c] = inp;
            com[r][c] += com[r - 1][c];
            com[r][c] += com[r][c - 1];
            com[r][c] -= com[r - 1][c - 1];
        }
    }
    
    ll maxSum = -oo;
    for(int r0 = 1 ; r0 <= n ; ++r0)
        for(int c0 = 1 ; c0 <= n ; ++c0)
            for(int r1 = r0 ; r1 <= n ; ++r1)
                for(int c1 = c0 ; c1 <= n ; ++c1){
                    maxSum = max(maxSum, (ll)(com[r1][c1] - com[r0 - 1][c1] - com[r1][c0 - 1] + com[r0 - 1][c0 - 1]));
                }
    cout << maxSum << endl;


    
    return 0; 
}
