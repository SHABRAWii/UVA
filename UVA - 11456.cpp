#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 

void construct(vector <int> &vec, vector <int> &sol){
    int n = vec.size();
    vector <int> Sorted;
    for(int i = 0 ; i < n ; ++i){
        int idx = lower_bound(Sorted.begin(), Sorted.end(), vec[i]) - Sorted.begin();
        if(idx == Sorted.size()){
            Sorted.push_back(vec[i]);
        }else{
            Sorted[idx] = vec[i];
        }
        sol[i] = idx + 1;
    }
}
// void construct_st(vector <int> &vec, vector <int> &sol){// Value of LIS at end point and of LDS at start point
//     int n = vec.size();
//     int mem[n][n];
//     for(int i = 0 ; i < n ; ++i)
//         sol[i] = 1;
//     for(int r = 0 ; r < n ; ++r){
//         int inc = sol[r] + 1;
//         for(int c = 0 ; c < n ; ++c){
//             if(vec[c] < vec[r] && c > r)
//                 sol[c] = max(sol[c], inc);
//         }
//     }
// }
void construct_st(const vector<int>& numbers, vector<int>& length){
    int N = numbers.size();
    for (int i = 0; i < N; ++i)
        length[i] = 1;
    length.resize(N, 1);
    
    for (int i = numbers.size() - 1; i >= 0; --i){
        int inc = length[i] + 1;
        for (int j = 0; j < i; ++j){
            if (numbers[j] < numbers[i] )
                length[j] = max(length[j], inc);
        }
    }
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
        vector <int> vec(n);
        for(int i = 0 ; i < n ; ++i){
            cin >> vec[i];
        }
        vector <int> LIS(n), LDS(n);
        reverse(vec.begin(), vec.end());
        construct(vec, LDS);
        int ans = 0;


        vector <int> LIS2(n);
        reverse(vec.begin(), vec.end());
        construct_st(vec, LIS2);
        for(int i = 0 ; i < n ; ++i){
            ans = max(ans, LIS2[i] + LDS[n - 1 - i] - 1);
        }
        cout << ans << endl;
    }

    return 0; 
}
