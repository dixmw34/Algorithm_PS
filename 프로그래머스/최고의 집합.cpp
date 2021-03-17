#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s)
        return { -1 };

    int mid = s / n;
    answer = vector<int>(n, mid);
    s %= n;
    for (int i = 1; i <= s; ++i) {
        answer[n - i]++;
    }

    return answer;
}