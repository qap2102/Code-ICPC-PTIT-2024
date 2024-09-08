#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
const double EPS = 1e-9;
struct Point{
    double x,y;
};
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
pair<Point, double> circleFromTwoPoints(const Point& p1, const Point& p2) {
    Point center = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2}; // tọa độ tâm O
    double radius = distance(p1, p2) / 2; // bán kính
    return {center, radius};
}
pair<Point, double> circleFromThreePoints(const Point& p1, const Point& p2, const Point& p3) {
    double A = p2.x - p1.x;
    double B = p2.y - p1.y;
    double C = p3.x - p1.x;
    double D = p3.y - p1.y;
 
    double E = A * (p1.x + p2.x) + B * (p1.y + p2.y);
    double F = C * (p1.x + p3.x) + D * (p1.y + p3.y);
 
    double G = 2 * (A * (p3.y - p2.y) - B * (p3.x - p2.x));
 
    if (fabs(G) < EPS) return {{0, 0}, numeric_limits<double>::infinity()};
 
    double center_x = (D * E - B * F) / G;
    double center_y = (A * F - C * E) / G;
    Point center = {center_x, center_y};
    double radius = distance(center, p1);
    return {center, radius};
}
bool isValid(Point center, double radius, Point point) {
    return distance(center, point) <= radius + EPS;
}
 
bool allPoints(Point center, double radius, const vector<Point>& points) {
    for(auto p : points) {
        if(!isValid(center, radius, p)) return false;
    }
    return true;
}
 
double find(vector<Point>& points) {
    int n = points.size();
    double res = numeric_limits<double>::infinity();
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; j++) {
            auto [center, radius] = circleFromTwoPoints(points[i], points[j]);
            if(allPoints(center, radius, points))
                res = min(res, radius);
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                auto [center, radius] = circleFromThreePoints(points[i], points[j], points[k]);
                if(radius < numeric_limits<double>::infinity() && allPoints(center, radius, points))
                    res = min(res, radius);
            }
        }
    }
 
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    double res = find(v);
    cout << fixed << setprecision(6) << res << endl;
}
 
signed main() {
    faster;
    solve();
    return 0;
}
