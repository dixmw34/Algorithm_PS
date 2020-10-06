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
vector<vector<int>>arr;
stack<int>s;
bool dp[1000][10];

bool dfs(int day, int pre) {
	if (day == n)return true;
	if (!dp[day][pre])return false;
	for (int i = 0; i < arr[day].size(); ++i) {
		if (arr[day][i] != pre) {
			if (dfs(day + 1, arr[day][i])) {
				s.push(arr[day][i]);
				return true;
			}
		}
	}

	return dp[day][pre] = false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n;
	arr = vector<vector<int>>(n);
	int m, a;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		while (m--) {
			cin >> a;
			arr[i].push_back(a);
		}
	}

	memset(dp, -1, sizeof(dp));

	if (dfs(0, 0)) {
		while (!s.empty()) {
			cout << s.top() << '\n';
			s.pop();
		}
	}
	else cout << -1 << '\n';

	return 0;

}