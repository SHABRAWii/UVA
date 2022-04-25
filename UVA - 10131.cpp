#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 

const int N = 1e3 + 4;
vector <int> W, S;
int n;
int vis[N];
int mem[N][N];
int Solve(int idx, int lst){
    if(idx == n)
        return 0;
    if(idx == lst) return Solve(idx + 1, lst);
    int &ret = mem[idx][lst];
    if(~ret)
        return ret;
// Take
    int ch1 = 0;
    if(lst == n || (!vis[idx] && W[idx] > W[lst] && S[idx] < S[lst])){
        vis[idx] = 1;
        ch1 = 1 + Solve(0, idx);
        vis[idx] = 0;
    }else if(vis[idx]){
        ch1 = Solve(idx + 1, lst);
    }
// leave
    int ch2 = Solve(idx + 1, lst);
    return ret = max(ch1, ch2);
}
vector <int> outs;
void Build_Outs(int idx, int lst){
    // cout << idx << " :: " << lst << endl;
    if(idx == n)
        return;
    if(idx == lst){
        Build_Outs(idx + 1, lst);
        return;
    }
    int ans = Solve(idx, lst);
// Take
    int ch1 = 0;
    if(lst == n || (!vis[idx] && W[idx] > W[lst] && S[idx] < S[lst])){
        vis[idx] = 1;
        ch1 = 1 + Solve(0, idx);
        if(ch1 == ans){
            outs.push_back(idx);
            Build_Outs(0, idx);
            return;
        }
        vis[idx] = 0;
    }
    Build_Outs(idx + 1, lst);
    return;
}
int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 
    int w, s;
    while(cin >> w && w != EOF){
        cin >> s;
        W.push_back(w);
        S.push_back(s);
    }
    memset(mem, -1, sizeof(mem));
    n = W.size();
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        ans = max(ans, Solve(i, n));
    }
    cout << ans << endl;
    for(int i = 0 ; i < n ; ++i){
        if(ans == Solve(i, n)){
            // cout << i << " aaaaaaa " << endl;
            Build_Outs(i, n);
            break;
        }
    }

    for(auto it : outs)
        cout << it + 1 << "\n";
    // cout << endl;
    // for(auto it : outs)
    //     cout << W[it] << " " << S[it] << endl;
    
    
    return 0; 
}
