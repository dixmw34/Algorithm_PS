#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	double win, lose, draw;
	cin >> win >> lose >> draw;

	double dp[21][61];

	memset(dp, 0, sizeof(dp));

	dp[0][40] = 1.0;

	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 60; ++j) {
			dp[i][j] = dp[i - 1][j - 1] * win + dp[i - 1][j + 1] * lose + dp[i - 1][j] * draw;
		}
	}
	double ans = 0.0;
	for (int i = 20; i <= 60; ++i) {
		ans += dp[20][i];
		if (i % 10 == 9) {
			printf("%0.8lf\n", ans);
			ans = 0.0;
		}
	}
	printf("%0.8lf\n", ans);
	

	return 0;

}