// UVA :: 12532 - Interval Product
// Link :: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3977&mosmsg=Submission+received+with+ID+26395454

//#define rerun
#include <iostream>
#include <algorithm>
#include <climits>
#include <string.h>

#define init() cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);
#define inf 0x3f3f3f3f
#define EFS 1e-7
#define bin 0b111111111111111111111111111111

using namespace std;
using ll = long long;

int n = 0;
const int N = 100000;
int A[N] = {};
int Tree[4 * N] = {};

void Build(int idx, int l, int r){
    if(l == r){
        Tree[idx] = (A[l] > 0) ? 1 : (A[l] < 0) ? -1 : 0;
        return;
    }
    int mid = (l + r)/2;

    Build(idx * 2 + 1, l, mid);
    Build(idx * 2 + 2, mid + 1, r);
    Tree[idx] = Tree[idx * 2 + 1] * Tree[idx * 2 + 2];
}
void Upd(int idx, int l, int r, int p, int v){
    if ( l > p || r < p) return;
    if ( l == r){
        Tree[idx] = (v > 0) ? 1 : (v < 0) ? -1 : 0;
        return;
    }
    int mid = (l + r) / 2;
    Upd(idx * 2 + 1, l, mid, p, v);
    Upd(idx * 2 + 2, mid + 1, r, p, v);
    Tree[idx] = Tree[idx * 2 + 1] * Tree[idx * 2 + 2];

}
int Qu (int idx, int l, int r, int st, int en){
    if(l > en || r < st ) return 1;
    if(l >= st && r <= en) {
        return Tree[idx];
    }
    int mid = (l + r) / 2;

    return Qu(idx * 2 + 1, l, mid, st, en)
            * Qu(idx * 2 + 2, mid +1, r, st, en);
}


int main(){
    y:
    init();

    int k = 0;
    while(cin >> n >> k){
        for(int i = 0 ; i < n ; ++i){
            cin >> A[i];
        }
        Build(0, 0, n-1);
        string out = "";
        char c = ' ';
        int p = 0, v = 0;
        for(int i = 0 ; i < k ; ++i){
            cin >> c >> p >> v;
            if(c == 'C'){
                Upd(0, 0, n-1, --p, v);
            }else{
                int r = Qu(0, 0, n-1, --p, --v);
                out += (r > 0) ? '+' : (r < 0) ? '-' : '0';
            }
        }
        cout << out << endl;
    }

    #ifdef rerun
    goto y;
    #endif // rerun
return 0;
}
