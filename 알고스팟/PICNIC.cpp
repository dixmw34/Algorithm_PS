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

vector<bool>visit;
vector<vector<bool>>arr;
int n, ans;

void dfs(int num) {
	if (num == n / 2) {
		ans++;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (visit[i])continue;
			for (int j = i + 1; j < n; j++) {
				if (visit[j] || i == j)continue;
				if (arr[i][j]) {
					visit[i] = visit[j] = true;
					dfs(num + 1);
					visit[i] = visit[j] = false;
				}
			}
			break;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		arr = vector<vector<bool>>(n, vector<bool>(n, false));
		while (m--) {
			cin >> a >> b;
			arr[a][b] = arr[b][a] = true;
		}
		ans = 0;
		visit = vector<bool>(n, false);
		visit[0] = true;
		for (int i = 1; i < n; i++) {
			if (arr[0][i]) {
				visit[i] = true;
				dfs(1);
				visit[i] = false;
			}
		}

		cout << ans << '\n';
		arr.clear();
		visit.clear();

	}

	

	return 0;

}