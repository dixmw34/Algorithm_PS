#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const ll Mod = 1234567;

long long solution(int n) {

    vector<ll>dp(2001, 0);
    dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % Mod;
    }

    return dp[n];
}