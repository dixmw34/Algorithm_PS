#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

const int MOD =  1000000007;



int solution(int m, int n, vector<vector<int>> puddles) {

	int dp[101][101] = {0, };

	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][1]][puddles[i][0]] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
			}
			else if (dp[i][j] == -1)dp[i][j] = 0;
			else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	return dp[n][m];
}

int solution2(int m, int n, vector<vector<int>> puddles) {

	vector<vector<int>>dp(n, vector<int>(m, 0));
	vector<vector<bool>>water(n, vector<bool>(m, false));
	vector<vector<bool>>visit(n, vector<bool>(m, false));
	vector<vector<int>>time(n, vector<int>(m, INF));
	dp[0][0] = 1; visit[0][0] = true; time[0][0] = 0;

	for (int i = 0; i < puddles.size(); i++) {
		water[puddles[i][1] - 1][puddles[i][0] - 1] = true;
	}

	queue<pi>q;
	q.push(pi(0, 0));

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (x == n - 1 && y == m - 1)return dp[x][y];

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && !water[x + dx[i]][y + dy[i]] && time[x + dx[i]][y + dy[i]] >= time[x][y] + 1) {
				dp[x + dx[i]][y + dy[i]] = (dp[x + dx[i]][y + dy[i]] + dp[x][y]) % MOD;
				time[x + dx[i]][y + dy[i]] = time[x][y] + 1;
				if (!visit[x + dx[i]][y + dy[i]]) {
					visit[x + dx[i]][y + dy[i]] = true;
					q.push(pi(x + dx[i], y + dy[i]));
				}
			}
		}
	}

	return 0;
}