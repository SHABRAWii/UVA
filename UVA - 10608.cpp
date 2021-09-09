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
int n, mxS = 0;

struct DSU{
    int par[N], sz[N], cnt, sets[N], pos[N];
    void init(int n){
        iota(par, par + n, 0);
        iota(sets, sets + n, 0);
        iota(pos, pos + n, 0);
        fill(sz, sz + n, 1);
        cnt = n;
        mxS = 1;
    }
    int find(int x){
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    bool merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return 0;
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        mxS = max(mxS, sz[u]);
        par[v] = u;
        int p = pos[v];
        pos[sets[p] = sets[--cnt]] = p;
        return 1;
    }

}dsu;

int main(){
   #ifdef VS_freOpen
       freopen("input.in", "r", stdin);
   #endif
    FIO;
  
    int tc = 0;
    cin >> tc;
    while(tc--){
        int m = 0;
        cin >> n >> m;
        dsu.init(n);
        int u = 0, v = 0;
        for(int i = 0 ; i < m ; ++i){
            cin >> u >> v;
            dsu.merge(u, v);
        }
        cout << mxS << endl;
    }


    
    


    #ifdef rerun
        goto y;
    #endif // rerun

   return 0;
}
/*
*/
