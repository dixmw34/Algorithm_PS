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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int n;
bool arr[1000][10], dp[1000][10];
int re[1000][10];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));

	cin >> n;
	int m, a;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		while (m--) {
			cin >> a;
			arr[i][a] = true;
			
		}
	}
	for (int i = 1; i < 10; ++i)if (arr[0][i])dp[0][i] = true;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < 10; ++j) {
			if (dp[i - 1][j]) {
				for (int k = 1; k < 10; ++k) {
					if (k == j)continue;
					if (arr[i][k]) {
						dp[i][k] = true;
						re[i][k] = j;
					}
				}
			}
		}
	}

	stack<int>s;

	for (int i = 1; i < 10; ++i) {
		if (dp[n - 1][i]) {
			s.push(i);
			break;
		}
	}

	if (s.empty()) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = n - 1; i > 0; --i) {
		s.push(re[i][s.top()]);
	}

	while (!s.empty()) {
		cout << s.top() << '\n';
		s.pop();
	}
	

	

	return 0;

}