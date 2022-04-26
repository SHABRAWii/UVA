#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 

int Lower_Bound(deque <int> &deq, int S){
    int l = 0, r = deq.size() - 1;
    while(l <= r){
        int mid = l + (r - l + 1) / 2;
        if(deq[mid] >= S){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return r;
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
        int n = 0;
        cin >> n;
        pair <int, int> inp[n];
        for(int i = 0 ; i < n ; ++i){
            cin >> inp[i].first >> inp[i].second;
        }

        sort(inp, inp + n, [](pair <int, int> &st, pair <int, int> &nd ){
            if(st.first == nd.first)return st.second > nd.second;
            return st.first < nd.first;
        });
        int W[n];
        for(int i = 0 ; i < n ; ++i){
            W[i] = inp[i].second;
        }
        int vis[n] = {};
        deque <int> Sorted;
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
            int idx = Lower_Bound(Sorted, W[i]);

            if(idx == -1){
                Sorted.push_front(W[i]);
            }else{
                Sorted[idx] = W[i];
            }
        }
        ans = Sorted.size();
        cout << ans << endl;
    }

    return 0; 
}
