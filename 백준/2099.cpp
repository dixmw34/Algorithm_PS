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

int n;

vector<vector<bool>>mul(vector<vector<bool>>a, vector<vector<bool>>b) {
	vector<vector<bool>>c(n, vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (a[i][k] && b[k][j]) {
					c[i][j] = true;
					break;
				}
			}
		}
	}
	return c;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int k, m, a, b;
	cin >> n >> k >> m;
	vector<vector<bool>>arr(n, vector<bool>(n, false));
	vector<vector<bool>>ans(n, vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		ans[i][i] = true;
		cin >> a >> b;
		a--; b--;
		arr[i][a] = arr[i][b] = true;
	}
	while (k) {
		if (k % 2) {
			ans = mul(arr, ans);
		}
		arr = mul(arr, arr);
		k /= 2;
	}
	while (m--) {
		cin >> a >> b;
		if (ans[a - 1][b - 1]) cout << "death\n";
		else cout << "life\n";
	}
	

	return 0;

}