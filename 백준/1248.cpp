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
#include<cassert>

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

char s[11][11];
int n, sum[11];

bool check(int idx) {
	for (int i = 1; i <= idx; ++i) {
		int num = sum[idx] - sum[i - 1];
		char ch = s[i][idx];
		if (ch == '+' && num <= 0)return false;
		if (ch == '-' && num >= 0)return false;
		if (ch == '0' && num != 0)return false;
	}
	return true;
}

void dfs(int idx) {
	if (idx == n + 1) {
		for (int i = 1; i <= n; ++i) {
			cout << sum[i] - sum[i - 1] << ' ';
		}
		cout << '\n';
		exit(0);
	}

	for (int i = -10; i <= 10; ++i) {
		sum[idx] = sum[idx - 1] + i;
		if (check(idx))dfs(idx + 1);
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			cin >> s[i][j];
		}
	}

	sum[0] = 0;
	dfs(1);

	return 0;
}