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

int Solve(ll coco, ll people){
    ll loops = people;
    while(coco){
        if(loops){
            --loops;
            --coco;
            if(coco % people)
                return 0;
            coco -= coco / people;
        }else{
            if(coco % people)
                return 0;
            coco = 0;
        }
    }
    return people;
}

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
        ll n;
        cin >> n;
        if(n < 0)
            break;
        ll ans = -1;
        for(int i = 5 ; i > 1 ; --i){
            if(Solve(n, i)){
                ans = i;
                break;
            }
        }
        if(n < 3) ans = -1;
        if(~ans)
            cout << n << " coconuts, "<< ans << " people and 1 monkey" << endl;
        else 
            cout << n << " coconuts, no solution" << endl;
        
        DB_TC();
    }

    return 0;
}
/*

*/
