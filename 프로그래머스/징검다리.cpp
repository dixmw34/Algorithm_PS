#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    int left = 1, right = distance;

    while (left <= right) {
        int mid = (left + right) / 2;
        int test = 0, l = 0;
        for (int i = 0; i < rocks.size(); i++) {
            if (l + mid <= rocks[i]) {
                l = rocks[i];
                test++;
            }
        }

        if (test + n >= rocks.size()) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }


    return answer;
}