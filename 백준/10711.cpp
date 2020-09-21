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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int h, w;
	cin >> h >> w;
	vector<string>arr(h);
	for (int i = 0; i < h; ++i)cin >> arr[i];

	vector<string>dp(h, string(w, '0'));

	queue<pi>erase;

	for (int i = 1; i < h-1; ++i) {
		for (int j = 1; j < w-1; ++j) {
			if (arr[i][j] != '.' && arr[i][j] != '9') {
				for (int k = 0; k < 8; ++k) {
					if (arr[i + dx[k]][j + dy[k]] == '.')dp[i][j]++;
				}
				if (arr[i][j] <= dp[i][j]) {
					erase.push(pi(i, j));
				}
			}
		}
	}

	int ans = 0;
	
	
	while (1) {
		if (!erase.empty()) {
			ans++;
			int n = erase.size();
			for (int i = 0; i < n; ++i) {
				int x = erase.front().first, y = erase.front().second;
				for (int k = 0; k < 8; ++k) {
					if (++dp[x + dx[k]][y + dy[k]] == arr[x + dx[k]][y + dy[k]]) {
						erase.push(pi(x + dx[k], y + dy[k]));
					}
				}
				arr[x][y] = '.';
				erase.pop();
			}
		}
		else {
			cout << ans << '\n';
			return 0;
		}
	}


	return 0;

}