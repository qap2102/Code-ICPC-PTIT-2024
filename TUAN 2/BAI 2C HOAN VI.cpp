#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> operation1(const vector<int>& p, int N) {
    vector<int> new_p = p;
    for (int i = 0; i < 2 * N; i += 2) {
        swap(new_p[i], new_p[i + 1]);
    }
    return new_p;
}

vector<int> operation2(const vector<int>& p, int N) {
    vector<int> new_p = p;
    for (int i = 0; i < N; ++i) {
        swap(new_p[i], new_p[i + N]);
    }
    return new_p;
}

bool is_sorted(const vector<int>& p) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != i + 1) return false;
    }
    return true;
}

int min_operations_to_sort(vector<int>& p, int N) {
    if (is_sorted(p)) return 0;

    set<vector<int>> visited;
    queue<pair<vector<int>, int>> q;
    q.push({p, 0});
    visited.insert(p);

    while (!q.empty()) {
        vector<int> current = q.front().first;
        int steps = q.front().second;
        q.pop();

        vector<int> next1 = operation1(current, N);
        vector<int> next2 = operation2(current, N);

        if (is_sorted(next1)) return steps + 1;
        if (is_sorted(next2)) return steps + 1;

        if (visited.find(next1) == visited.end()) {
            q.push({next1, steps + 1});
            visited.insert(next1);
        }

        if (visited.find(next2) == visited.end()) {
            q.push({next2, steps + 1});
            visited.insert(next2);
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> P[i];
    }
    cout << min_operations_to_sort(P, N) << endl;
    return 0;
}
