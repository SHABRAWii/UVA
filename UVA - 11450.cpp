// UVA :: 11450 - Wedding shopping
#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 

int n = 0;
const int N = 1e4 + 4;
int arr[21][21];
int mem[21][201];
int M, G;
int Solve(int money, int g){
    if(money < 0)
        return -ooi;
    if(g == G)
        return M - money;
    int &ret = mem[g][money];
    if(~ret)
        return ret;
    int ch1 = -ooi;
    for(int i = 1 ; i <= arr[g][0] ; ++i){
        ch1 = max(ch1, Solve(money - arr[g][i], g + 1));
    }
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
        memset(mem, 0, sizeof(mem));
        cin >> M >> G;
        for(int i = 0 ; i < G ; ++i){
            cin >> arr[i][0];
            for(int g = 1 ; g <= arr[i][0] ; ++g){
                cin >> arr[i][g];
            }
        }
        for(int g = 1 ; g <= arr[0][0] ; ++g)
            if(M - arr[0][g] >= 0)
                mem[0][M - arr[0][g]] = 1;
        for(int g = 1 ; g < G ; ++g){
            for(int elm = 1 ; elm <= arr[g][0] ; ++elm){
                for(int money = 0 ; money < 201 ; ++money){
                    if(mem[g - 1][money]){
                        if(money - arr[g][elm] >= 0){
                            mem[g][money - arr[g][elm]] = 1;
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(int i = 0 ; i < 201 ; ++i){
            if(mem[G - 1][i]){
                ans = i;
                break;
            }
        }
        if(ans >= 0){
            cout << M - ans << endl;
        }else{
            cout << "no solution" << endl;
        }
    }
    
    return 0; 
}
