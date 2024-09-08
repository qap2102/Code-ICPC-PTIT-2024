#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct Pt {
    double x, y;
};

double dis(Pt a, Pt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Pt get(Pt A,Pt B,Pt C) {
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    double Ux = ((A.x * A.x + A.y * A.y) * (B.y - C.y) + (B.x * B.x + B.y * B.y) * (C.y - A.y) + (C.x * C.x + C.y * C.y) * (A.y - B.y)) / D;
    double Uy = ((A.x * A.x + A.y * A.y) * (C.x - B.x) + (B.x * B.x + B.y * B.y) * (A.x - C.x) + (C.x * C.x + C.y * C.y) * (B.x - A.x)) / D;
    return {Ux, Uy};
}

pair<Pt, double> solve(vector<Pt> p) {
    Pt c = p[0];
    double r = 0;

    for (int i = 0; i < p.size(); ++i) {
        if (dis(c, p[i]) > r) {
            c = p[i];
            r = 0;
            for (int j = 0; j < i; ++j) {
                if (dis(c, p[j]) > r) {
                    c.x = (p[i].x + p[j].x) / 2;
                    c.y = (p[i].y + p[j].y) / 2;
                    r = dis(c, p[j]);
                    for (int k = 0; k < j; ++k) {
                        if (dis(c, p[k]) > r) {
                            c = get(p[i], p[j], p[k]);
                            r = dis(c, p[k]);
                        }
                    }
                }
            }
        }
    }

    return {c, r};
}

int main() {
    int N;
    cin >> N;
    vector<Pt> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    auto result = solve(p);
    cout << fixed << setprecision(6) << result.second << endl;

    return 0;
}
