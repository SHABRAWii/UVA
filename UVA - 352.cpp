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
const int N = 2e5 + 5, M = 2*N;
int head[N], nxt[M], to[M];
int n, ne;
int vis[N], vid;
void init(){
    memset(head, -1, (n + 1) * sizeof(head[0]));
    ++vid;
    ne = 0;
}
void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
void addBiEdgee(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}
void BFS(int u){
    queue <int> q;
    q.emplace(u);
    vis[u] = vid;
    int level = 0;
    while(!q.empty()){
        ++level;
        int sz = q.size();
        while(sz--){
            int v = q.front();
            q.pop();
            for(int e = head[v] ; ~e ; e = nxt[e]){
                int vv = to[e];
                if(vis[vv] != vid){
                    vis[vv] = vid;
                    q.emplace(vv);
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
    int tc = 1, cc = 0;
    // cin >> tc;
    while(1){
        ++cc;
        int row = 0;
        cin >> row;
        if(cin.eof())
            break;
        n = row * row;
        init();
        int arr[row][row] = {};
        for(int i = 0 ; i < row ; ++i){
            for(int j = 0 ; j < row ; ++j){
                char inp;
                cin >> inp;
                arr[i][j] = inp - '0';
            }
        }
        for(int i = 0 ; i < row ; ++i){
            for(int j = 0 ; j < row ; ++j){
                if(i + 1 < row && arr[i][j] && arr[i + 1][j])
                    addBiEdgee(i * row + j, (i + 1) * row + j);
                if(j + 1 < row && arr[i][j] && arr[i][j + 1])
                    addBiEdgee(i * row + j, i * row + j + 1);
                if(i + 1 < row && j + 1 < row && arr[i][j] && arr[i + 1][j + 1])
                    addBiEdgee(i * row + j, (i + 1) * row + j + 1);
                if(i + 1 < row && j - 1 >= 0 && arr[i][j] && arr[i + 1][j - 1])
                    addBiEdgee(i * row + j, (i + 1) * row + j - 1);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < row ; ++i){
            for(int j = 0 ; j < row ; ++j){
                if(arr[i][j] && vis[i * row + j] != vid){
                    ++ans;
                    BFS(i * row + j);
                }
            }
        }
        cout << "Image number " << cc << " contains " << ans << " war eagles." << endl;
        
        DB_TC();
    }

    return 0;
}
/*

*/
