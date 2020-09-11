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
#include <climits>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

vector<int>arr(501);
vector<vector<int>>dp(500, vector<int>(500, -1));
int n;

int sol(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];

	dp[x][y] = INF;

	for (int i = x; i < y; i++) {
		dp[x][y] = min(dp[x][y], sol(x, i) + sol(i + 1, y) + arr[x] * arr[i + 1] * arr[y + 1]);
	}

	return dp[x][y];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int a, b;
	cin >> n;

	cin >> arr[0] >> arr[1];
	dp[0][0] = 0;

	for (int i = 2; i <= n; i++) {
		cin >> a >> b;
		arr[i] = b;
		dp[i - 1][i - 1] = 0;
	}

	cout << sol(0, n - 1) << '\n';

	return 0;

}