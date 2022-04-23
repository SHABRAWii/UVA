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
    
    int R = 0, C = 0;
    while(cin >> R && R){
        cin >> C;
        ll com[R + 1][C + 1] = {};
        for(int r = 1 ; r <= R ; ++r){
            for(int c = 1 ; c <= C ; ++c){
                char inp = 0;
                cin >> inp;
                com[r][c] = inp - '0';
                com[r][c] += com[r - 1][c];
                com[r][c] += com[r][c - 1];
                com[r][c] -= com[r - 1][c - 1];
            }
        }
        
        
        ll ans = 0, siz = 0;
        for(int r0 = 1 ; r0 <= R ; ++r0)
            for(int c0 = 1 ; c0 <= C ; ++c0)
                for(int r1 = r0 ; r1 <= R ; ++r1)
                    for(int c1 = c0 ; c1 <= C ; ++c1){
                        siz = (ll)(com[r1][c1] - com[r0 - 1][c1] - com[r1][c0 - 1] + com[r0 - 1][c0 - 1]);
                        // cout << r0 << " " << c0 << " : " << r1 << " " << c1 << "  == " << siz << endl;
                        if(siz == (ll)(r1 - r0 + 1) * (c1 - c0 + 1))
                            ++ans;
                    }
        cout << ans << endl;
    }


    
    return 0; 
}
