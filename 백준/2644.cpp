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
#include <cassert>

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
	cin.tie(0); cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	vector<vector<int>>arr(n + 1, vector<int>(n + 1, INF));

	int m, x, y;
	cin >> m;
	while (m--) {
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j)continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	if (arr[a][b] == INF)
		cout << -1 << '\n';
	else
		cout << arr[a][b] << '\n';

	return 0;
}