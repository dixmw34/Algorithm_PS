#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

int dp[201][201][201];
vector<vector<int>>arr(3);

int sol(vector<int>c, vector<priority_queue<int>>arr) {
	int ans = 0;
	while (1) {
		if ((c[0] == 0 && c[1] == 0) || (c[0] == 0 && c[2] == 0) || (c[1] == 0 && c[2] == 0))break;
		pi result1 = pi(0, 0);
		pi result2 = pi(0, 0);

		for (int i = 0; i < 3; i++) {
			if (!arr[i].empty() && result1.first < arr[i].top()) {
				result2 = result1;
				result1 = pi(arr[i].top(), i);
			}
			else if (!arr[i].empty() && result2.first < arr[i].top()) {
				result2 = pi(arr[i].top(), i);
			}
		}

		arr[result1.second].pop(); arr[result2.second].pop();
		c[result1.second]--; c[result2.second]--;

		ans += result1.first*result2.first;
	}
	return ans;
}

int dfs(int r, int g, int b) {

	if (dp[r][g][b] != 0)return dp[r][g][b];

	dp[r][g][b] = 0;

	if (r > 0 && g > 0) {
		dp[r][g][b] = max(dp[r][g][b], arr[0][r-1]*arr[1][g-1] + dfs(r - 1, g - 1, b));
	}

	if (r > 0 && b > 0) {
		dp[r][g][b] = max(dp[r][g][b], arr[0][r - 1] * arr[2][b - 1] + dfs(r - 1, g, b - 1));
	}

	if (g > 0 && b > 0) {
		dp[r][g][b] = max(dp[r][g][b], arr[1][g - 1] * arr[2][b - 1] + dfs(r, g - 1, b - 1));
	}
	return dp[r][g][b];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, ans = 0;
	vector<int>c(3);
	

	cin >> c[0] >> c[1] >> c[2];

	for (int i = 0; i < c[0]; i++) {
		cin >> num;
		arr[0].push_back(num);
	}
	for (int i = 0; i < c[1]; i++) {
		cin >> num;
		arr[1].push_back(num);
	}
	for (int i = 0; i < c[2]; i++) {
		cin >> num;
		arr[2].push_back(num);
	}

	sort(arr[0].begin(), arr[0].end());
	sort(arr[1].begin(), arr[1].end());
	sort(arr[2].begin(), arr[2].end());

	cout << dfs(c[0], c[1], c[2]) << '\n';
	

	return 0;
	

}