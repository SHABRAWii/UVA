#include <iostream>
#include <cmath>

using namespace std;
int main(){
//    y:
//    freopen("CodeForces.txt", "r", stdin);
    int tc = 0;
    cin >> tc;
    while (tc--){
        int F = 0, B = 0;
        cin >> F >> B;
        int res = 0;
        for (int i = 0 ; i < B ; i++){
            int sB = 0, choco = 0;
            cin >> sB >> choco;
            for (int j = 1 ; j < sB ; j++){
                int ssB = 0;
                cin >> ssB;
                choco = (choco * ssB) % F;
            }
            res += (choco % F);
            res %= F;
        }
        cout << res << endl;

    }
//    goto y;
return 0;
}
