#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
#define EPS 1e-9
#define PI acos(-1)
#define DegToRad(theta) theta * PI / 180
#define areParallel(line1, line2) (fabs(line1.a - line2.a) < EPS && fabs(line1.b - line2.b) < EPS)
#define areSame(line1, line2) (areParallel(line1, line2) && fabs(line1.c - line2.c) < EPS)
#define scale(_vector, _scale) vec(_vector.x * _scale, _vector.y * _scale)
#define translate(_point, _vector) point(_point.x + _vector.x, _point.y + _vector.y)
#define dot(a, b) (double)(a.x * b.x + a.y * b.y)
#define cross(a, b) (double)(a.x * b.y - a.y + b.x)
#define norm_sq(_vector) (double)(_vector.x * _vector.x + _vector.y * _vector.y)
#define dist(_point1, _point2) hypot(_point1.x - _point2.x, _point1.y - _point2.y)
#define CCW(p, q, r) (bool)(cross(toVec(p, q), toVec(p, r)) > 0)
#define collinear(p, q, r) (bool)(fabs(cross(toVec(p, q), toVec(p, r))) < EPS)

bool DB = 0;
 
#define ll long long 
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

int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 
    int tc = 1;
    cin >> tc;
    while(tc--){
        point p,q;
        point a, b, c, d;
        cin >> p.x >> p.y >> q.x >> q.y;
        { // He can enter any opposite points in rectangle
            cin >> a.x >> a.y >> c.x >> c.y;
            if(c.y > a.y && c.x > a.x){
                b = c;
                d = a;
                a.y = b.y;
                c.y = d.y;
            }else if(c.y > a.y && c.x < a.x){
                swap(a, c);
            }else if(c.y < a.y && c.x < a.x){
                swap(a, c);
                b = c;
                d = a;
                a.y = b.y;
                c.y = d.y;
            }
        }

        if((p.x > a.x || fabs(p.x - a.x) < EPS) && (p.y < a.y || fabs(p.y - a.y) < EPS) && (p.x < c.x || fabs(p.x - c.x) < EPS) && (p.y > c.y || fabs(p.y - c.y) < EPS)){
            cout << 'T' << endl;
            continue;
        }
        if((q.x > a.x || fabs(q.x - a.x) < EPS) && (q.y < a.y || fabs(q.y - a.y) < EPS) && (q.x < c.x || fabs(q.x - c.x) < EPS) && (q.y > c.y || fabs(q.y - c.y) < EPS)){
            cout << 'T' << endl;
            continue;
        }
        b.x = c.x;
        b.y = a.y;
        d.x = a.x;
        d.y = c.y;
        line l1, ab, bc, cd, da;
        pointsToLine(p, q, l1);
        pointsToLine(a, b, ab);
        pointsToLine(b, c, bc);
        pointsToLine(c, c, cd);
        pointsToLine(d, a, da);
        
        point I;
        if(areIntersect(l1, ab, I)){
            if(betweenPoints(p, I, q) && betweenPoints(a, I, b)){
                cout << 'T' << endl;
                continue;
            }
        }
        if(areIntersect(l1, bc, I)){
            if(betweenPoints(p, I, q) && betweenPoints(b, I, c)){
                cout << 'T' << endl;
                continue;
            }
        }
        if(areIntersect(l1, cd, I)){
            if(betweenPoints(p, I, q) && betweenPoints(c, I, d)){
                cout << 'T' << endl;
                continue;
            }
        }
        if(areIntersect(l1, da, I)){
            if(betweenPoints(p, I, q) && betweenPoints(d, I, a)){
                cout << 'T' << endl;
                continue;
            }
        }
        cout << 'F' << endl;
    }
    

    return 0; 
}
