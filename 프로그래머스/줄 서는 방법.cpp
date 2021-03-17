#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll cal[21];

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int>test = { 1 };

    cal[1] = 1LL;
    for (int i = 2; i <= n; ++i) {
        cal[i] = cal[i - 1] * (ll)i;
        test.push_back(i);
    }

    for (int i = 0; i < n-1; ++i) {
        ll idx = (k - 1LL) / cal[n - i - 1];
        if (idx < 0)idx = 0;
        k -= idx * cal[n - i - 1];
        answer.push_back(test[(int)idx]);
        test.erase(test.begin() + (int)idx);
    }
    answer.push_back(test[0]);

    return answer;
}