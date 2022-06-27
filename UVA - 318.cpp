#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
#define ll long long 
#define Debug(_var1) if(DB) cout << "=> " << _var1 << endl;
#define Debug2(_var1, _var2) if(DB) cout << "=> " << _var1 << "   " << _var2 << endl;
#define Debug3(_var1, _var2, _var3) if(DB) cout << "=> " << _var1 << "   " << _var2 << "   " << _var3 << endl;
#define DB_TC() if(DB)cout << "=> _____________ <=\n"; 

bool DB = 0;
const int N = 1e5 + 5, M = 2*N;
int head[N], nxt[M], to[M], Time[M], ans[N];
int n, ne;
int vis[N], vid;
void init(){
    memset(head, -1, (n + 1) * sizeof(head[0]));
    memset(ans, -1, (n + 1) * sizeof(ans[0]));
    ++vid;
    ne = 0;
}
void addEdge(int f, int t, int _time){
    to[ne] = t;
    nxt[ne] = head[f];
    Time[ne] = _time;
    head[f] = ne++;
}
void addBiEdgee(int u, int v, int _time){
    addEdge(u, v, _time);
    addEdge(v, u, _time);
}
pair<int, int> fall[2];
void BFS(int u){
    priority_queue <pair<int, int>> pq;
    pq.emplace(make_pair(0, u));
    vis[u] = vid;
    ans[u] = 0;
    int level = 0;
    int p = 0;
    while(!pq.empty()){
        ++level;
        int sz = pq.size();
        while(sz--){
            int v, tim;
            tie(tim, v) = pq.top();
            tim = -tim;
            pq.pop();
            if(tim != ans[v])
                continue;
            for(int e = head[v] ; ~e ; e = nxt[e]){
                int vv = to[e];
                if(!~ans[vv] || ans[v] + Time[e] < ans[vv]){
                    ans[vv] = ans[v] + Time[e];
                    pq.emplace(make_pair(-ans[vv], vv));
                }
            }
        }
    }
    return;
}
int main(){ 
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
        DB = 0;
    #endif 
    FIO; 

    int tc = 1, tcc = 0;
    // cin >> tc;
    cout << fixed << setprecision(1);
    while(1){
        ++tcc;
        cin >> n;
        init();
        int m = 0;
        cin >> m;
        if(!n && !m)
            break;
        for(int i = 0 ; i < m ; ++i){
            int u, v, _time;
            cin >> u >> v >> _time;
            addBiEdgee(--u, --v, _time);
        }
        BFS(0);
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b){
           return ans[a] < ans[b]; 
        });
        pair <float, pair <int, int>> ret = make_pair(ans[idx[n - 1]], make_pair(idx[n - 1], -1));
        for(int i = 0 ; i < n ; ++i)
            for(int e = head[i] ; ~e ; e = nxt[e]){
                int v = to[e];
                int tim = Time[e];
                if(abs(ans[v] - ans[i]) < tim){
                    float calc = ans[i] + (tim - abs(ans[i] - ans[v])) / 2.0 ;
                    if(calc > ret.first){
                        ret.first = calc;
                        ret.second = make_pair(i, v);
                    }
                }
            }
        cout << "System #" << tcc << endl;
        if(!~ret.second.second){
            cout << "The last domino falls after " << ret.first << " seconds, at key domino " << ret.second.first + 1 << "." << endl;
        }else
            cout << "The last domino falls after " << ret.first << " seconds, between key dominoes " << min(ret.second.first + 1, ret.second.second + 1) << " and " << max(ret.second.first + 1 , ret.second.second + 1) << "." << endl;
        cout << endl;
        DB_TC();
    }

    return 0;
}
/*

*/
