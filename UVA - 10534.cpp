#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 
vector <int> LIDS;
void Solve(vector <int> &vec, int sol[]){
    LIDS.clear();
    for(int i = 0 ; i < vec.size() ; ++i){
        int idx = lower_bound(LIDS.begin(), LIDS.end(), vec[i]) - LIDS.begin();
        if(idx == LIDS.size()){
            LIDS.push_back(vec[i]);
        }else{
            LIDS[idx] = vec[i];
        }
        sol[i] = idx;
    }
    return;
}

int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 

    int n = 0;
    while(cin >> n && n){
        vector <int> vec(n);
        for(int i = 0 ; i < n ; ++i){
            cin >> vec[i];
        }
        int LIS[n] = {};
        Solve(vec, LIS);
        reverse(vec.begin(), vec.end());
        int LDS[n] = {};
        Solve(vec, LDS);

        int ans = 1;
        for(int i = 0 ; i < n ; ++i){
            ans = max(ans, 2 * min(LIS[i], LDS[n - i - 1]) + 1);
        }
        cout << ans << endl;
    }


    
    return 0; 
}
