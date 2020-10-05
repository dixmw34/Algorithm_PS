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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	char arr[100][100];
	bool visit[100][100];
	cin >> n >> m;
	queue<pi>wolf;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'W') {
				wolf.push(pi(i, j));
				visit[i][j] = true;
			}
		}
	}

	while (!wolf.empty()) {
		int x = wolf.front().first, y = wolf.front().second; wolf.pop();
		for (int i = 0; i < 4; ++i) {
			if (!visit[x + dx[i]][y + dy[i]]) {
				if (arr[x + dx[i]][y + dy[i]] == '.') {
					visit[x + dx[i]][y + dy[i]] = true;
					wolf.push(pi(x + dx[i], y + dy[i]));
				}
				else if (arr[x + dx[i]][y + dy[i]] == '+') {
					int k = 2;
					while (arr[x + dx[i] * k][y + dy[i] * k] == '+')++k;
					if (arr[x + dx[i] * k][y + dy[i] * k] == '.' && !visit[x + dx[i] * k][y + dy[i] * k]) {
						visit[x + dx[i] * k][y + dy[i] * k] = true;
						wolf.push(pi(x + dx[i] * k, y + dy[i] * k));
					}
					else if (arr[x + dx[i] * k][y + dy[i] * k] == '#' && !visit[x + dx[i] * (k-1)][y + dy[i] * (k-1)]) {
						--k;
						visit[x + dx[i] * k][y + dy[i] * k] = true;
						wolf.push(pi(x + dx[i] * k, y + dy[i] * k));
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '.' && !visit[i][j]) {
				arr[i][j] = 'P';
			}
			cout << arr[i][j];
		}
		cout << '\n';
	}


	return 0;

}