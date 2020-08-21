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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	ll ans = 0;

	cin >> n >> m;
	vector<vector<ll>>arr(n, vector<ll>(m));

	vector<ll>col(m, 0);
	vector<ll>row(n, 0);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			col[j] = max(col[j], arr[i][j]);
			row[i] = max(row[i], arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != col[j] && arr[i][j] != row[i]) {
				ans += arr[i][j];
				arr[i][j] = 0;
			}
		}
	}

	cout << ans << '\n';
	


	return 0;

}