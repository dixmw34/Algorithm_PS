#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<bool>a(n + 1, false);
    vector<bool>b(n + 1, false);

    for (int i = 0; i < lost.size(); i++) {
        a[lost[i]] = true;
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (a[reserve[i]])a[reserve[i]] = false;
        else b[reserve[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            if (i - 1 >= 0 && b[i - 1]) {
                a[i] = b[i - 1] = false;
            }
            else if (i + 1 <= n && b[i + 1]) {
                a[i] = b[i + 1] = false;
            }
            else answer++;
        }
    }
    return n - answer;
}