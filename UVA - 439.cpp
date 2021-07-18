//#define rerun
#include <iostream>
#include <string.h>
#include <queue>

#define FIO() cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);
#define inf 0x3f3f3f3f
#define EFS 1e-7
#define bin 0b111111111111111111111111111111

using namespace std;
using ll = long long;

const int N = 2e5+ 10 , M = 2*N;
int head[N], to[M], nxt[M], vis[N] = {}, vid = 1;
int n = 0, ne = 0;
int dis[64] = {};
void init(){
    memset(head, -1, n*sizeof(head[0]));
    ne = 0;
}
void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
void addBiEdge(int u, int v){
    if(u < 0 || v < 0 || u > 63 || v > 63) return;
    addEdge(u, v);
    addEdge(v, u);
}
void BFS(int f){

    queue <int> q;
    q.push(f);
    int u = 0, v = 0;
    dis[f] = 0;
    while(!q.empty()){
        u = q.front();
        for(int e = head[u] ; e != -1 ; e = nxt[e]){
            v = to[e];
            if(!~dis[v]){
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
        q.pop();
    }
}

int main(){
    y:
    FIO();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    n = 64;
    init();
    for(int i = 0, r = 1 ; i < 8 ; ++i, ++r ){
        for(int j = i*8, c = 1 ; j < i*8+8 ; ++j, ++c ){
            if(r > 2 && c < 8)
                addBiEdge(j, j+1-2*8);
            if(r < 8 && c < 7)
                addBiEdge(j, j+2+8);
            if(r < 8 && c > 2)
                addBiEdge(j, j-2+8);
            if(r < 7 && c < 8)
               addBiEdge(j, j+1+2*8);
        }
    }
    string a, b;
    int f = 0, t = 0;
    while(cin >> a && a != "\n"){
        memset(dis, -1, 64 * sizeof(dis[0]));
        cin >> b;
        f = (a[0] - 'a')*8 + (a[1] - '1');
        t = (b[0] - 'a')*8 + (b[1] - '1');
        BFS(f);
//        for(int i = 0 ; i < 8 ; ++i ){
//            for(int j = 0 ; j < 8 ; ++j ){
//                cout << dis[j+8*i] << " ";
//            }
//            cout << "\n";
//        }
        cout << "To get from " << a << " to " << b << " takes " << dis[t] << " knight moves." << "\n";
    }

    #ifdef rerun
    goto y;
    #endif // rerun
return 0;
}
