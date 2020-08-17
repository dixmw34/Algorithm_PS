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

const int MIN = -1e9 - 1;

vector<vector<bool>>check;

void sol(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			check[x + i][y + j] = !check[x + i][y + j];
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, num, ans = 0;

	cin >> n;

	vector<int>idx(n + 1);
	vector<int>dp(n + 1, 1);

	for (int i = 0; i < n; i++) {
		cin >> num;
		idx[num] = i;
	}

	for (int i = 1; i < n; i++) {
		if (idx[i] < idx[i + 1]) {
			dp[i + 1] = dp[i] + 1;
			ans = max(ans, dp[i + 1]);
		}
	}

	cout << n - ans << '\n';


	return 0;

}