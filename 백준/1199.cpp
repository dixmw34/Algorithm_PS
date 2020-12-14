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

int degree[1000], l[1000][1000], sum = 0, n;
vector<int>ans;

bool dfs(int start) {
	ans.push_back(start + 1);
	if (ans.size() == sum + 1) {
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return true;
	}
	for (int i = 0; i < n; ++i) {
		if (l[start][i]) {
			l[start][i]--;
			l[i][start]--;
			if (dfs(i))return true;
			l[start][i]++;
			l[i][start]++;
		}
	}
	ans.pop_back();
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool result = true;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		degree[i] = 0;
		for (int j = 0; j < n; ++j) {
			cin >> l[i][j];
			degree[i] += l[i][j];
		}
		if (degree[i] % 2 == 1)result = false;
		else sum += degree[i] / 2;
	}

	if (!result) {
		cout << -1 << '\n';
	}
	else {
		dfs(0);
	}

	return 0;
}