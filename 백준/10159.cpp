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

	int n, m, a, b;
	cin >> n >> m;

	vector<vector<bool>>heavy(n + 1, vector<bool>(n + 1, false));
	vector<vector<bool>>light(n + 1, vector<bool>(n + 1, false));

	while (m--) {
		cin >> a >> b;
		heavy[a][b] = light[b][a] = true;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j)continue;
				if (!heavy[i][j] && heavy[i][k] && heavy[k][j])heavy[i][j] = true;
				if (!light[i][j] && light[i][k] && light[k][j])light[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j)continue;
			if (heavy[i][j])ans++;
			else if (light[i][j])ans++;
		}
		cout << n - ans - 1 << '\n';
	}

	return 0;

}