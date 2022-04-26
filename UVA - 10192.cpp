#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 
const int N = 100;
string FT, MT;
int mem[N][N];
int Solve(int f, int m){
    if(f == FT.size() || m == MT.size())
        return 0;

    int &ret = mem[f][m];
    if(~ret)
        return ret;
// if equal take
    int ch1 = 0;
    if(FT[f] == MT[m])
        ch1 = 1 + Solve(f + 1, m + 1);
// Try another
    int ch2 = Solve(f + 1, m);
    ch2 = max(ch2, Solve(f, m + 1));

    return ret = max(ch1, ch2);
}
int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 
    int i = 0;
    while(getline(cin, FT) && FT != "#"){
        getline(cin, MT);
        ++i;
        memset(mem, -1, sizeof(mem));
        cout << "Case #"<< i << ": you can visit at most " << Solve(0, 0) << " cities." << endl;
    }

    return 0; 
}
