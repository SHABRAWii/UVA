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

int main(){ 
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
        DB = 0;
    #endif 
    FIO; 

    int tc = 1;
    // cin >> tc;
    while(1){
        int n = 0;
        cin >> n;
        if(!n)
            break;
        ll ans = 0;
        set <ll> st;
        for(int i = 1 ; i <= sqrt(n) ; ++i){
            if(i * i == n){
                st.emplace(i);
                break;
            }
            if(n % i == 0){
                st.emplace(i);
                st.emplace(n / i);
            }
        }
        set <ll>::iterator it, it2;
        for(auto it = st.begin() ; it != st.end() ; ++it){
            it2 = it;
            for( ; it2 != st.end() ; ++it2){
                ll com = (*it) * (*it2) / __gcd((*it), (*it2));
                // cout << *it << " " << *it2 << " ==> " << com << endl;
                if(com == n)
                    ++ans;
            }
        }
        cout << n << " " << ans << endl;
        
        
        DB_TC();
    }

    return 0;
}
/*

*/
