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

	int t;
	cin >> t;
	while (t--) {
		int h, w;
		cin >> h >> w;
		vector<vector<char>>arr(h + 2, vector<char>(w + 2, '.'));
		vector<vector<bool>>visit(h + 2, vector<bool>(w + 2, false));

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> arr[i][j];
			}
		}
		string key;
		cin >> key;
		vector<bool>open(26, false);
		if (key != "0") {
			for (int i = 0; i < key.size(); ++i) {
				open[key[i] - 'a'] = true;
			}
		}

		int ans = 0;
		queue<pi>man;
		queue<pi>lock;

		man.push(pi(0, 0));
		visit[0][0] = true;

		while (1) {
			while (!man.empty()) {
				int x = man.front().first, y = man.front().second; man.pop();

				for (int i = 0; i < 4; ++i) {
					if (x + dx[i] >= 0 && x + dx[i] < h + 2 && y + dy[i] >= 0 && y + dy[i] < w + 2 && !visit[x + dx[i]][y + dy[i]] && arr[x + dx[i]][y + dy[i]]!='*') {
						visit[x + dx[i]][y + dy[i]] = true;
						if (arr[x + dx[i]][y + dy[i]] == '.') {
							man.push(pi(x + dx[i], y + dy[i]));
						}
						else if (arr[x + dx[i]][y + dy[i]] == '$') {
							man.push(pi(x + dx[i], y + dy[i]));
							ans++;
						}
						else if (arr[x + dx[i]][y + dy[i]] >= 'A' && arr[x + dx[i]][y + dy[i]] <= 'Z') {
							int num = arr[x + dx[i]][y + dy[i]] - 'A';
							if (open[num]) {
								man.push(pi(x + dx[i], y + dy[i]));
							}
							else {
								lock.push(pi(x + dx[i], y + dy[i]));
							}
							
						}
						else if (arr[x + dx[i]][y + dy[i]] >= 'a' && arr[x + dx[i]][y + dy[i]] <= 'z') {
							int num = arr[x + dx[i]][y + dy[i]] - 'a';
							open[num] = true;
							man.push(pi(x + dx[i], y + dy[i]));
						}
					}
				}
			}
			int n = lock.size();
			for (int k = 0; k < n; ++k) {
				int x = lock.front().first, y = lock.front().second; lock.pop();
				int num = arr[x][y] - 'A';
				if (open[num]) {
					man.push(pi(x, y));
				}
				else {
					lock.push(pi(x, y));
				}
			}
			if (man.empty())break;
		}

		cout << ans << '\n';
	}
	

	return 0;

}