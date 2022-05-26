#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
#define ll long long 
#define bound(vect) vect.begin(), vect.end()

bool DB = 0;

#define EPS 1e-9
#define PI acos(-1)
#define DegToRad(theta) theta * PI / 180
#define areParallel(line1, line2) (fabs(line1.a - line2.a) < EPS && fabs(line1.b - line2.b) < EPS)
#define areSame(line1, line2) (areParallel(line1, line2) && fabs(line1.c - line2.c) < EPS)
#define scale(_vector, _scale) vec(_vector.x * _scale, _vector.y * _scale)
#define translate(_point, _vector) point(_point.x + _vector.x, _point.y + _vector.y)
#define dot(a, b) a.x * b.x + a.y + b.y
#define cross(a, b) a.x * b.y - a.y * b.x
#define norm_sq(_vector) _vector.x * _vector.x + _vector.y * _vector.y
#define dist(_point1, _point2) hypot(_point1.x - _point2.x, _point1.y - _point2.y)
#define CCW(o, a, b) (bool)(cross(toVec(o, a), toVec(o, b)) >= 0)
#define collinear(p, q, r) (bool)(fabs(cross(toVec(p, q), toVec(p, r))) < EPS)

 
// Points
struct point_i{
    int x, y;
    point_i(){x = y = 0;}
    point_i(int _x, int _y): x(_x), y(_y) {};
};
struct point{
    double x, y;
    point(){x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {};
    bool operator < (point other) const {
        if(fabs(x - other.x) > EPS){
            return x < other.x;
        }
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS ); // EPS 1e-9
    }
};

point rotate(point p, double theta){
    double rad = DegToRad(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), 
                 p.x * sin(rad) + p.y * cos(rad));
}

// Lines
struct line{
    double a, b, c; // ax + by + c = 0
};
void pointsToLine(point p1, point p2, line &l){
    if(fabs(p1.x - p2.x) < EPS){
        l.a = 1, l.b = 0, l.c = -p1.x;
    }else{
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)( p1.y + l.a * p1.x);
    }
    return;
}
bool areIntersect(line l1, line l2, point &p){
    if(areParallel(l1, l2)) return 0;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b); // by solving 2 Equations
    if(fabs(l1.b) > EPS) // Test Vertical lines for line one then b = 0 so get it from line 2
        p.y = -( l1.a * p.x + l1.c );
    else
        p.y = -( l2.a * p.x + l2.c );
    return 1;
}
struct vec{
    double x, y;
    vec(){x = y = 0.0;}
    vec(double _x, double _y): x(_x), y(_y) {};
};
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}
bool betweenPoints(point a, point inMid, point b){
    if(fabs(a.x - inMid.x) < EPS && fabs(a.y - inMid.y) < EPS)
        return 1;
    if(fabs(b.x - inMid.x) < EPS && fabs(b.y - inMid.y) < EPS)
        return 1;
    vec ab = toVec(a, b);
    // if(ab.x < EPS && ab.y < EPS){
        
    // }
    vec ba = scale(ab, -1);
    vec aM = toVec(a, inMid);
    vec bM = toVec(b, inMid);
    double u = dot(ab, aM) / (sqrt( norm_sq(ab) * norm_sq(aM)));
    double v = dot(ba, bM) / (sqrt( norm_sq(ba) * norm_sq(bM)));
    return (fabs(u - 1) < EPS && fabs(v - 1) < EPS);
}
double distToLine(point p, point a, point b, point &c){
    // c = a + u * ab
    // u = ap * cos(theta) / |ab|
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(a, c);
}
double distToLineSegment(point p, point a, point b, point &c){
    // c = a + u * ab
    // u = ap * cos(theta) / |ab|
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0){ // closer to a
        c = a;
        return dist(p, a);
    }else if(u > 1.0){ // closer to b
        c = b;
        return dist(p, b);
    }
    // must be between a and b
    return distToLine(p, a, b, c);
}
double angle(point a, point o, point b){
    vec ao = toVec(a, o), ob = toVec(o, b);
    return acos(dot(ao, ob) / (sqrt(norm_sq(ao)) * sqrt(norm_sq(ob))));
}
struct LineSegment{
    point p, q;
    LineSegment(){p.x = p.y = q.x = q.y = 0.0;}
    LineSegment(point a, point b){
        if(a.x > b.x)
            q = a, p = b;
        else
            p = a, q = b;
    }
    bool operator < (LineSegment other) const { // if the lowest point in segment 1 > lowest 
        return min(p.y, q.y) > min(other.p.y, other.q.y);// point in segment 2 then pass throw 1 first
    }//                                             there are no intersections
    point getLower(){
        if(p.y < q.y)
            return p;
        return q;
    }
    point getHigher(){
        if(p.y < q.y)
            return q;
        return p;

    }
};
double getX(LineSegment _lineSg, double _y){
    line l1, l2;
    pointsToLine(_lineSg.p, _lineSg.q, l1);
    pointsToLine(point(0, _y), point(_lineSg.q.x, _y), l2);
    point c;
    areIntersect(l1, l2, c);
    return c.x;
}

int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 

    int tc = 1;
    cin >> tc;
    cout << fixed << setprecision(2);
    while(tc--){
        int n = 0;
        cin >> n;
        LineSegment LS[n - 1];
        vector <point> points;
        for(int i = 0 ; i < n ; ++i){
            point a;
            cin >> a.x >> a.y;
            points.push_back({a.x, a.y});
        }
        sort(bound(points));
        for(int i = n - 1 ; i >= 0 ; i-= 2){
            LS[i - 1] = LineSegment(points[i - 1], points[i]);
        }
        double ans = hypot(LS[n - 2].q.x - LS[n - 2].p.x, LS[n - 2].q.y - LS[n - 2].p.y);
        double limit = LS[n - 2].p.y;
        for(int i = n - 3 ; i >= 0 ; --i){
            if(LS[i].p.y > limit){
                double x = LS[i].p.x - getX(LS[i], limit);
                double y = LS[i].p.y - limit;
                ans += hypot(x, y);
                limit = LS[i].p.y;
            }
        }
        cout << ans << endl;

    }

    return 0;
}
/*

*/
