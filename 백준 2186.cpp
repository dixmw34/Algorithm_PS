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

const int MAX = 1000000001;

int N, M, K;
vector<vector<char>>arr;
vector<vector<vector<int>>>dp;
string s;

int dfs(int x, int y, int idx) {
	if (idx == s.size())return 1;
	if (dp[x][y][idx] != -1) return dp[x][y][idx];

	dp[x][y][idx] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= K; j++) {
			if (x + dx[i] * j >= 0 && x + dx[i] * j < N && y + dy[i] * j >= 0 && y + dy[i] * j < M && arr[x + dx[i] * j][y + dy[i] * j] == s[idx]) {
				dp[x][y][idx] += dfs(x + dx[i] * j, y + dy[i] * j, idx + 1);
			}
		}
	}
	return dp[x][y][idx];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ans = 0;
	cin >> N >> M >> K;

	arr = vector<vector<char>>(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> s;
	dp = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(s.size(), -1)));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == s[0]) {
				ans += dfs(i, j, 1);
			}
		}
	}

	cout << ans << '\n';


	return 0;


}