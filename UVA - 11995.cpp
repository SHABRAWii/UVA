#include <iostream>
#include <stack>
#include <queue>
#include <stack>

#define inf 0x3f3f3f3f
#define EFS 1e-7
 /*

    // TODO (ucf#1#):
*/
using namespace std;

void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
int main(){
    y:
    init();
//    freopen("output.txt", "w", stdout);
    int tc = 0;
    while(cin >> tc){
        stack <int> st;
        queue <int> q;
        priority_queue <int> pq;
        int x = 1, y = 2, z = 4;
        int stat = 0;
        while(tc--){
            cin >> stat;
            int in = 0;
            cin >> in;
            if(!(stat-1)){

                if(x){
                    st.emplace(in);
                }
                if(y){
                    q.emplace(in);
                }
                if(z){
                    pq.emplace(in);
                }
            }else{
                if(st.empty())x = 0;
                if(q.empty()) y = 0;
                if(pq.empty())z = 0;
                if(x ){
                    if(in != st.top()) x = 0;
                    st.pop();
                }
                if(y){
                    if(in != q.front()) y = 0;
                    q.pop();
                }
                if(z){
                    if(in != pq.top()) z = 0;
                    pq.pop();
                }
            }
        }
        int fi = x + y + z;
        switch(fi){
            case (1):{
                cout << "stack" << endl;
                break;
            }
            case (2):{
                cout << "queue" << endl;
                break;
            }
            case (4):{
                cout << "priority queue" << endl;
                break;
            }
            case (0):{
                cout << "impossible" << endl;
                break;
            }
            default :{
                cout << "not sure" << endl;
                break;
            }
        }
    }

    #ifdef rerun
    goto y;
    #endif // rerun
return 0;
}
