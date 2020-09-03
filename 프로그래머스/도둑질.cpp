#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<int> money) {
    int answer = 0;

    int n = money.size();

    vector<int>dp(n, 0);

    dp[0] = money[0];

    for (int i = 1; i < n; i++) {
        int x = 0;
        if (i - 2 >= 0)x = dp[i - 2];
        if (i - 3 >= 0)x = max(x, dp[i - 3]);
        dp[i] = x + money[i];
    }
    answer = max(dp[n - 2], dp[n - 3]);

    dp = vector<int>(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int x = 0;
        if (i - 2 >= 0)x = dp[i - 2];
        if (i - 3 >= 0)x = max(x, dp[i - 3]);
        dp[i] = x + money[i];
    }
    answer = max(answer, dp[n-1]);

    return answer;
}