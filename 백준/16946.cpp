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

int a[1000][1000], ans[1000][1000], area[1000][1000];
bool v[1000][1000];
map<int, int>_map;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	char ch;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch;
			a[i][j] = ch - '0';
			ans[i][j] = 0;
		}
	}
	memset(v, 0, sizeof(v));
	memset(area, 0, sizeof(area));
	int color = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0 && !v[i][j]) {
				area[i][j] = color;
				v[i][j] = true;
				queue<pi>q;
				q.push(pi(i, j));
				while (!q.empty()) {
					_map[color]++;
					int x = q.front().first, y = q.front().second; q.pop();
					for (int i = 0; i < 4; ++i) {
						if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && a[x + dx[i]][y + dy[i]] == 0 && !v[x + dx[i]][y + dy[i]]) {
							v[x + dx[i]][y + dy[i]] = true;
							area[x + dx[i]][y + dy[i]] = color;
							q.push(pi(x + dx[i], y + dy[i]));
						}
					}
				}
				color++;
			}
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) {
				ans[i][j] = 1;
				int x = i, y = j;
				map<int, bool>_map2;
				for (int k = 0; k < 4; ++k) {
					if (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < m && a[x + dx[k]][y + dy[k]] == 0 && _map2.find(area[x + dx[k]][y + dy[k]])==_map2.end()) {
						ans[i][j] = (ans[i][j] + _map[area[x + dx[k]][y + dy[k]]]) % 10;
						_map2[area[x + dx[k]][y + dy[k]]] = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
	
	

	
	return 0;
}