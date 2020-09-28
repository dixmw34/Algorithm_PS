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

int r, c;
vector<vector<char>>arr;

void sol(int a, int b) {
	vector<vector<bool>>visit(r, vector<bool>(c, false));
	for (int i = 0; i < 4; ++i) {
		if (a + dx[i] >= 0 && a + dx[i] < r && b + dy[i] >= 0 && b + dy[i] < c && arr[a + dx[i]][b + dy[i]] == 'x' && !visit[a + dx[i]][b + dy[i]]) {
			visit[a + dx[i]][b + dy[i]] = true;
			bool flag = false;
			queue<pi>q;
			vector<pi>v;
			q.push(pi(a + dx[i], b + dy[i]));
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				if (x == 0)flag = true;
				v.push_back(q.front());
				q.pop();
				for (int u = 0; u < 4; ++u) {
					if (x + dx[u] >= 0 && x + dx[u] < r && y + dy[u] >= 0 && y + dy[u] < c && arr[x + dx[u]][y + dy[u]] == 'x' && !visit[x + dx[u]][y + dy[u]]) {
						visit[x + dx[u]][y + dy[u]] = true;
						q.push(pi(x + dx[u], y + dy[u]));
					}
				}
			}
			if (!flag) {
				//cout << a <<' '<< b << '\n';
				sort(v.begin(), v.end());
				for (int u = 0; u < v.size(); ++u) {
					arr[v[u].first][v[u].second] = '.';
				}
				int k = 1;
				while (1) {
					if (v[0].first - k == 0 || flag)break;
					for (int u = 0; u < v.size(); ++u) {
						if (arr[v[u].first - k - 1][v[u].second] == 'x') {
							flag = true;
							break;
						}
					}
					if(!flag)++k;
				}
				for (int u = 0; u < v.size(); ++u) {
					arr[v[u].first - k][v[u].second] = 'x';
				}
				return;
			}
		}
	}
}

int main(void) {

	cin >> r >> c;
	
	arr = vector<vector<char>>(r, vector<char>(c));

	for (int i = r - 1; i >= 0; --i) {
		for (int j = 0; j < c; ++j) {
			cin >> arr[i][j];
		}
	}

	int t, a;
	cin >> t;
	for (int k = 0; k < t; ++k) {
		cin >> a;
		--a;
		if (k % 2 == 0) {
			for (int i = 0; i < c; ++i) {
				if (arr[a][i] == 'x') {
					arr[a][i] = '.';
					sol(a, i);
					break;
				}
			}
		}
		else {
			for (int i = c-1; i >= 0; --i) {
				if (arr[a][i] == 'x') {
					arr[a][i] = '.';
					sol(a, i);
					break;
				}
			}
		}
	}

	for (int i = r - 1; i >= 0; --i) {
		for (int j = 0; j < c; ++j) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;

}