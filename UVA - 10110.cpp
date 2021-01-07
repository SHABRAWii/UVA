#include <bits/stdc++.h>

using namespace std;

void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    y:
    init();
    long long x = 0;
    while (cin >> x && x != 0){
        long long out = sqrt(x);
        out *= out;
        if (x == out)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    #ifdef rerun
//    goto y;
    #endif // rerun
return 0;
}
