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

vector<vector<int>>arr;
vector<vector<double>>dp;
vector<int>inDegree;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n, d, p, m, a;
	cin >> t;
	while (t--) {
		cin >> n >> d >> p;

		arr = vector<vector<int>>(n, vector<int>(n));
		inDegree = vector<int>(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j])inDegree[i]++;
			}
		}

		dp = vector<vector<double>>(d + 1, vector<double>(n, 0.0));
		dp[0][p] = 1.0;
		for (int k = 1; k <= d; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (arr[i][j])dp[k][i] += dp[k - 1][j] * (1.0 / (double)inDegree[j]);
				}
			}
		}
		
		cin >> m;
		vector<int>ans;
		while (m--) {
			cin >> a;
			cout.precision(8);

			cout << dp[d][a] << " ";
		}

		cout << '\n';
		arr.clear();
		inDegree.clear();
		dp.clear();
	}
	

	return 0;

}