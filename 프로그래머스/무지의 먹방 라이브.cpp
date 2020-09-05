#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int solution(vector<int> food_times, ll k) {
    ll Min = 1e10 + 1, Max = 0;
    queue<pair<ll, ll>>q;
    for (int i = 0; i < food_times.size(); i++) {
        q.push(pi(food_times[i], i));
        Min = min((ll)food_times[i], Min);
        Max = max((ll)food_times[i], Max);
    }

    while (!q.empty()) {
        ll n = q.size(), num = 1e10 + 1, test = k / n;
        if (Max*n <= k)return -1;

        if (test > Min) {
            k -= n * test;
            for (int i = 0; i < n; i++) {
                q.front().first -= test;
                if (q.front().first > 0) {
                    q.push(q.front());
                    num = min(num, q.front().first);
                }
                else if (q.front().first < 0) {
                    k -= q.front().first;
                }
                q.pop();
            }
            Min = num;
        }
        else if (k >= n*Min) {
            k -= n * Min;
            for (int i = 0; i < n; i++) {
                q.front().first -= Min;
                if (q.front().first != 0) {
                    q.push(q.front());
                    num = min(num, q.front().first);
                }
                q.pop();
            }
            Min = num;
        }
        else {
            Min = k / n;
            if (Min) {
                k -= n * Min;
                for (int i = 0; i < n; i++) {
                    q.front().first -= Min;
                    if (q.front().first != 0) {
                        q.push(q.front());
                        num = min(num, q.front().first);
                    }
                    q.pop();
                }
            }
            while (k) {
                if (q.empty())return -1;
                q.pop();
                k--;
            }
            if (q.empty())return -1;
            return q.front().second + 1;
        }
    }
    return -1;
}