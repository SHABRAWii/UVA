#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 
const int N = 1e6 + 4;
int X = 0, Y = 0;
bool isB[N] = {};
ll mem[N];
int sol = 1;
bool onc = 0;
ll Solve(int x, int y){
    // cout << x << " to " << y << endl;
    if(x == X - 1 && y == Y - 1){
        if(!onc){
            onc = 1;
        }
        return 0;
    }
    else if(x == X || y == Y)
        return ooi;

    ll &ret = mem[x * Y + y];
    if(~ret)
        return ret;
// Go right

    ll ch1 = ooi;
    if(y + 1 < Y && !isB[x * Y + y + 1])
        ch1 = 1 + Solve(x, y + 1);
// Go Left
    ll ch2 = ooi;
    if(x + 1 < X && !isB[(x+1) * Y + y])
        ch2 =  1 + Solve(x + 1, y);
    
    return ret = min(ch1, ch2);
}
void Build_outs(int x, int y){
    if(x == X - 1 && y == Y - 1)
        return;
    else if(x == X || y == Y)
        return;


// Go right

    ll ch1 = ooi;
    if(y + 1 < Y && !isB[x * Y + y + 1])
        ch1 = 1 + Solve(x, y + 1);
// Go Left
    ll ch2 = ooi;
    if(x + 1 < X && !isB[(x+1) * Y + y])
        ch2 =  1 + Solve(x + 1, y);
    int ans = Solve(x, y);
    if(ch1 == ans && ch2 == ans)
        ++sol;
    if(ch1 == ans)
        Build_outs(x, y + 1);
    if(ch2 == ans)
        Build_outs(x + 1, y);
    
        
    return;
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
        sol = 1;
        onc = 0;
        cin >> X >> Y;
        cin.ignore();
        // cout << ":: " << X << " " << Y << endl;
        // memset(mem, -1, (X * sizeof(mem[0])) + (Y * sizeof(mem[0])) );
        memset(mem, -1, (X * Y) * sizeof(mem[0]) );
        memset(isB, 0,  (X * Y) * sizeof(isB[0]) );
        for(int i = 0 ; i < X ; ++i){
            string inp;
            getline(cin, inp);
            stringstream str(inp);
            int x = 0;
            str >> x;
            int y = 0;
            while(str >> y){
                isB[(x - 1) * Y + (y - 1)] = 1;
            }
        }
        // cout << isB[3] << " vol " << endl;
        // cout << isB[14] << " :: " << endl;
        // cout << " :: " << Solve(0, 0) << endl;
        Solve(0, 0);
        Build_outs(0, 0);
        if(!onc){
            cout << 0 << endl;
        }else
            cout << sol << endl;

        if(tc != 0)
            cout << endl;
        
            
        
    }

    return 0; 
}
