#include <bits/stdc++.h>

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define inf 0x3f3f3f3f
#define endl '\n'
#define EFS 1e-7 
bool DBug = 0;

typedef long long ll; 
 
using namespace std; 

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const int N = 3e4 + 4;
ll mem[11][N];
ll Solve (int idx, int rem){

    if(rem == 0){// Correct way
        return 1;
    }
    if(rem < 0 || idx == 11){
        return 0;
    }
    ll &ret = mem[idx][rem];

    if(~ret) 
        return ret;

    return ret = Solve(idx + 1, rem) + Solve(idx, rem - coins[idx]);
}

int main(){ 
    // DB = 1;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    // FIO; 
    {// Solution
        for(int i = 0 ; i < 11 ; ++i){
            mem[i][0] = 1;
        }
        for(int rem = 5 ; rem <= 30000 ; rem+= 5){

            for(int j = 0 ; j < 11 ; ++j){
                if(j)
                    mem[j][rem] = mem[j - 1][rem];
                if(rem - coins[j] >= 0){
                    mem[j][rem] += mem[j][rem - coins[j]];
                }
            }
        }
    }
    float num;
    while(cin >> num && num > 1e-3){
        cout << fixed << setprecision(2);
        
        ll x1 = 2 - max((ll)(floor((log(((ll)num)) / log(10)))), 0ll);
        cout << string(x1, ' ');
        ll out = mem[10][(int)(round(num*100))];
        ll x2 = 16 - max((ll)(floor((log(((ll)out)) / log(10)))), 0ll);
        cout << num << string(x2, ' ') << out << endl;
    }
    return 0; 
} 
