#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 0;

    sort(times.begin(), times.end());
    ll left = (ll)times[0] * (n / times.size()), right = (ll)times[times.size() - 1] * (n / times.size()+1);

    //answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll test = 0;

        for (int i = 0; i < times.size(); i++) {
            test += mid / (ll)times[i];
        }

        if (test >= (ll)n) {
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return answer;
}