#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 



int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 
    int tc = 0;
    cin >> tc;
    int k = 0;
    while(tc--){
        ++k;
        int l = 1, r = -1;
        int ans = 0, sum = 0;
        int n = 0;
        cin >> n;
        int arr[n + 1];
        int lst = 1;
        for(int i = 1, inp ; i <= n ; ++i){
            
            if(i != n)
                cin >> arr[i];
            else 
                arr[i] = -ooi;
            sum += arr[i];
            if(ans <= sum ){
                if(sum == ans){
                    if(r - l < i - lst + 1){
                        r = i + 1;
                        l = lst;
                    }
                }else{
                    r = i + 1;
                    l = lst;
                }
                ans = sum;
            }
            
            
            if(sum < 0){
                sum = 0;
                lst = i + 1;
            }
        }
        if(ans)
            cout << "The nicest part of route " << k << " is between stops " << l << " and " << r << endl;
        else
            cout << "Route " << k << " has no nice parts" << endl;
    }

    
    return 0; 
}
