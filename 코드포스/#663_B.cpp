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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m, ans;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		ans = 0;
		vector<vector<char>>arr(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n-1; i++) {
			if (arr[i][m - 1] == 'R')ans++;
		}
		for (int i = 0; i < m - 1; i++) {
			if (arr[n-1][i] == 'D')ans++;
		}
		cout << ans << '\n';
		arr.clear();
	}


	return 0;


}