//#define rerun

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int isBipartite (vector <vector <int>> &adj, int visited[], int u){
    queue <int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int u = q.front();
        for (int i = 0 ; i < adj[u].size() ; i++ ){
            int v = adj[u][i];
            if(!visited[v]){
                q.push(v);
                if(visited[u] == 1) visited[v] = 2;
                else        visited[v] = 1;
            }
            if(visited[v] == visited[u] && u != v) {return 0;}
        }
        q.pop();
    }
    return 1;
}
bool disconnected(vector <vector <int>> &adj){
    int n = adj.size();
    int visted[n] = {0};
    for(int i = 0 ; i < n; i++){
        if (!visted[i]){
            if(isBipartite(adj, visted, i) == false)
            return false;
        }
    }
    return true;
}
int main(){
    y:
        int verts = 0, edgs = 0;
    while(cin >> verts && verts !=  0){
        cin >> edgs;
        vector <vector <int>> adj(verts);
        for (int i = 0 ; i < edgs ; i++ ){
            int input_1 = 0, input_2 = 0;
            scanf("%i%i", &input_1, &input_2);
                adj[input_1].push_back(input_2);
                adj[input_2].push_back(input_1);

        }
        if(disconnected(adj)){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    #ifdef rerun
        goto y;
    #endif // rerun
return 0;
}
