#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
bool DB = 0;
 
#define ll long long 


#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
#define EPS 1e-9
#define PI acos(-1)
#define dist(_point1, _point2) hypot(hypot(_point1.x - _point2.x, _point1.y - _point2.y), _point1.z - _point2.z)


// bool DB = 0;
 
#define ll long long 
// Points

struct point{
    double x, y, z;
    point(){x = y = z = 0.0;}
    point(double _x, double _y, double _z): x(_x), y(_y), z(_z) {};
    bool operator < (point other) const {
        if(fabs(x - other.x) > EPS){
            return x < other.x;
        }
        if(fabs(y - other.y) > EPS){
            return y < other.y;
        }
        return z < other.z;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS && fabs(z - other.z) < EPS); // EPS 1e-9
    }
};






int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 

  
    int tc = 1;
    // cin >> tc;
    while(tc--){
        vector <point> points;
        point inp;
        while(cin >> inp.x >> inp.y >> inp.z && !(inp.x < EPS && inp.y < EPS && inp.z < EPS)){
            points.push_back(inp);
        }
        int n = points.size();
        vector <double> dists;
        for(int i = 0 ; i < n ; ++i){
            double xDis = 20000;
            for(int j = 0 ; j < n ; ++j){
                if(i == j)
                    continue;
                xDis = min(xDis, dist(points[i], points[j]));
            }
            dists.push_back(xDis);
        }
        dists.push_back(11);
        sort(dists.begin(), dists.end());

        int Ans = 0, cur = 1;
        for(int i = 0 ; i < dists.size() && cur <= 10 ; ++i){
            if(dists[i] < cur){
                ++Ans;
            }else{
                if(!Ans){
                    cout << "   " << 0;
                }else
                    cout << string(4 - (1 + floor((log(Ans) / log(10)))), ' ') << Ans;
                Ans = 0;
                ++cur;
                --i;
            }
        }
        cout << endl;

    }
    

    return 0; 
}
