#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _left[1000000], _right[1000000];

int solution(vector<int> a) {

    int n = a.size();

    _left[0] = a[0];
    for (int i = 1; i < n; ++i) {
        _left[i] = min(a[i], _left[i - 1]);
    }
    _right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        _right[i] = min(a[i], _right[i + 1]);
    }

    int ans = min(n, 2);
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] <= _left[i - 1] || a[i] <= _right[i + 1])
            ans++;
    }

    return ans;
}