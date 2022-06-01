#include <bits/stdc++.h>

using namespace std; 

#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define oo __LONG_LONG_MAX__
#define ooi INT32_MAX
#define endl '\n'
#define ll long long 
bool DB = 0;

#define EPS 1e-9
#define PI acos(-1)
#define DegToRad(theta) (double)(theta * PI / 180.0)
#define areParallel(line1, line2) (fabs(line1.a - line2.a) < EPS && fabs(line1.b - line2.b) < EPS)
#define areSame(line1, line2) (areParallel(line1, line2) && fabs(line1.c - line2.c) < EPS)
#define scale(_vector, _scale) vec(_vector.x * _scale, _vector.y * _scale)
#define translate(_point, _vector) point(_point.x + _vector.x, _point.y + _vector.y)
#define dot(a, b) (double)(a.x * b.x + a.y * b.y)
#define cross(a, b) (double)(a.x * b.y - a.y * b.x)
#define norm_sq(_vector) (double)(_vector.x * _vector.x + _vector.y * _vector.y)
#define dist(_point1, _point2) (double)(hypot(_point1.x - _point2.x, _point1.y - _point2.y))
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
    void scan(){
        cin >> x >> y;
    }
}O{0, 0};
// Lines
struct line{
    double a, b, c; // ax + by + c = 0
};

struct vec{
    double x, y;
    vec(){x = y = 0.0;}
    vec(double _x, double _y): x(_x), y(_y) {};
};
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

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}
double distToLine(point p, point a, point b, point &c){
    // c = a + u * ab
    // u = ap * cos(theta) / |ab|
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
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
point rotate(point p, double theta){
    double rad = DegToRad(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), 
                 p.x * sin(rad) + p.y * cos(rad));
}

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
double traingleArea(point a, point b, point c){
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ac = dist(a, c);
    double s = (ab + bc + ac) / 2.0; // s = circumference
    return sqrt(s * (s - ab) * (s - bc) * (s - ac));
}
double parallelogramArea(point a, point b, point c){
    double Area = dist(a, b) * dist(b, c) * sin(acos(dot(toVec(b, a), toVec(b, c)) / (dist(a, b) * dist(b, c))));
    return Area;
    if(b == c)
        return 0;
    line ab, bc;
    pointsToLine(a, b, ab);
    pointsToLine(b, c, bc);
    point inTersect;
    if(areIntersect(ab, bc, inTersect) && !(areSame(ab, bc))){
        
        double AB = dist(a, b);
        double BC = dist(b, c);
        double theta = angle(a, b, c);
        double h = BC * sin(theta);
        return AB * h;
    }
    return 0;
}
struct refrence{
    point O;
    double angle; // angle with +X coordinate
    refrence(){O.x = O.y = angle = 0.0;}
    refrence(point _O, double _angle): O(_O), angle(_angle) {};
    void newPoint(point &p){
        p.x -= O.x;
        p.y -= O.y;
        p = rotate(p, -angle);
    }
    void oldPoint(point &p){
        p = rotate(p, angle);
        p.x += O.x;
        p.y += O.y;
    }
    
};

double slopeAngle(vec _vector, bool DegOrRad) {
    // cout << (((asin(cross(_vector, toVec(O, {1, 0})) / sqrt(norm_sq(_vector)))) > 0) ? 2*PI : 0) << endl;
    line l1;
    pointsToLine(O, translate(O, _vector), l1);
    return atan(-l1.a/l1.b) * 180 / PI;
    if(_vector.x == 0) return 90;
    return atan(_vector.y / _vector.x) * 180 / PI;
    // return  (double)((acos(dot(_vector, toVec(O, {1, 0})) / sqrt(norm_sq(_vector)))) * (((asin(cross(_vector, toVec(O, {1, 0})))) > 0) ? -1 : 1) + (((asin(cross(_vector, toVec(O, {1, 0})))) > 0) ? 2*PI : 0))* (180.0 / PI * !DegOrRad + DegOrRad);
}
double polyArea(vector <point> &_vector){
    double area = 0.0;
  
    int j = _vector.size() - 1;
    for (int i = 0; i < _vector.size(); i++)
    {
        area += (_vector[j].x + _vector[i].x) * (_vector[j].y - _vector[i].y);
        j = i;  // j is previous vertex to i
    }
    return abs(area / 2.0);
}

int main(){ 
    DB = 0;
    #ifdef VS_FreeOpen 
        freopen("input.in", "r", stdin); 
        freopen("output.in", "w", stdout); 
    #endif 
    FIO; 
    int tc = 2;
    // cin >> tc;
    cout << fixed << setprecision(4);
    while(1){
        point M;
        M.scan();
        if(cin.eof())
            break;
        int n = 0;
        cin >> n;
        point arr[n + 1];
        for(int i = 0 ; i <= n ; ++i){
            arr[i].scan();
        }
        point c;
        double dist = ooi;
        for(int i = 1 ; i <= n ; ++i){
            line l1;
            point d;
            double tmp = distToLineSegment(M, arr[i - 1], arr[i], d);
            if(tmp < dist){
                c = d;
                dist = tmp;
            }
        }
        cout << c.x << "\n" << c.y << endl;

    
    }

    return 0; 
}
/*

*/

