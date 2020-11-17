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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int v, m, n, a, b, c;
		cin >> v >> m >> n;
		vector<vector<int>>l(v, vector<int>(v, INF));
		while (m--) {
			cin >> a >> b >> c;
			l[a][b] = min(l[a][b], c);
			l[b][a] = min(l[b][a], c);
		}

		for (int k = 0; k < v; ++k) {
			for (int i = 0; i < v; ++i) {
				for (int j = 0; j < v; ++j) {
					if (i == j)continue;
					if (l[i][j] > l[i][k] + l[k][j])l[i][j] = l[i][k] + l[k][j];
				}
			}
		}

		int ans = 0;
		while (n--) {
			cin >> a >> b >> c;
			if (l[a][b] > c) {
				l[a][b] = l[b][a] = c;
				for (int i = 0; i < v; ++i) {
					for (int j = 0; j < v; ++j) {
						if (i == j)continue;
						if (l[i][j] > l[i][a] + l[a][j])l[i][j] = l[i][a] + l[a][j];
					}
				}
				for (int i = 0; i < v; ++i) {
					for (int j = 0; j < v; ++j) {
						if (i == j)continue;
						if (l[i][j] > l[i][b] + l[b][j])l[i][j] = l[i][b] + l[b][j];
					}
				}
			}
			else ans++;
		}
		cout << ans << '\n';
	}
	

	return 0;

}