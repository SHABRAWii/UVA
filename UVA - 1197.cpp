#include <iostream>
#include <climits>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <numeric>


#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define inf 0x3f3f3f3f
#define endl '\n'
#define EFS 1e-7

typedef long long ll;

using namespace std;

const int N = 3e4 + 4;
int n;
struct DSU{
    int par[N], sz[N], cnt;
    void init(int n){
        iota(par, par + n, 0);
        fill(sz, sz + n, 1);
        cnt = n;
    }
    int find(int x){
        if(x == par[x]) return x;
        
        return par[x] = find(par[x]);
    }
    bool merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return 0;
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        --cnt;
        return 1;
    }
}dsu;

int main(){
   #ifdef VS_freOpen
       freopen("input.in", "r", stdin);
   #endif
    FIO;
  
    int m = 0, lp = 0;
    while(cin >> n >> m && (n || m)){
        dsu.init(n);
        int sus[n] = {}, inS = 1;
        
        int u = 0, v = 0;
        int  k = 0;
        for(int i = 0 ; i < m ; ++i){
            cin >> k;
            for(int j = 0 ; j < k ; ++j){
                if(!j){
                    cin >> u;
                }else{
                    cin >> v;
                    dsu.merge(u, v);
                }
            }
        }
        cout << dsu.sz[dsu.find(0)] << endl;   
    }
    


    #ifdef rerun
        goto y;
    #endif // rerun

   return 0;
}
/*
*/
