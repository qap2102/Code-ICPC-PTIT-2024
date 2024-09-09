#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int max_len = 0;
    int left = 0;
    multiset<int> s;

    for (int right = 0; right < n; ++right) {
        s.insert(arr[right]);

        while (s.size() >= 3) {
            auto it = s.begin();
            int min1 = *it;
            it++;
            int min2 = *it;
            int max_val = *s.rbegin();  

            if (min1 + min2 > max_val) {
                max_len = max(max_len, right - left + 1);
                break;
            } else {
                s.erase(s.find(arr[left]));
                left++;
            }
        }
    }

    cout << max_len << endl;

    return 0;
}