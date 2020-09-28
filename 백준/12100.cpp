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

int big(vector<vector<int>>arr) {
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mx = max(mx, arr[i][j]);
		}
	}
	return mx;
}

vector<vector<int>>up(vector<vector<int>>arr) {
	for (int k = 0; k < n; ++k) {
		queue<int>q;
		for (int j = 0; j < n; ++j) {
			if (arr[j][k]) {
				q.push(arr[j][k]);
				arr[j][k] = 0;
			}
		}
		int idx = 0;
		while (!q.empty()) {
			int num = q.front(); q.pop();
			if (!q.empty() && q.front() == num) {
				q.pop();
				num *= 2;
			}
			arr[idx++][k] = num;
		}
	}
	return arr;
}

vector<vector<int>>down(vector<vector<int>>arr) {
	for (int k = 0; k < n; ++k) {
		queue<int>q;
		for (int j = n - 1; j >= 0; --j) {
			if (arr[j][k]) {
				q.push(arr[j][k]);
				arr[j][k] = 0;
			}
		}
		int idx = n - 1;
		while (!q.empty()) {
			int num = q.front(); q.pop();
			if (!q.empty() && q.front() == num) {
				q.pop();
				num *= 2;
			}
			arr[idx--][k] = num;
		}
	}
	return arr;
}

vector<vector<int>>left(vector<vector<int>>arr) {
	for (int k = 0; k < n; ++k) {
		queue<int>q;
		for (int j = 0; j < n; ++j) {
			if (arr[k][j]) {
				q.push(arr[k][j]);
				arr[k][j] = 0;
			}
		}
		int idx = 0;
		while (!q.empty()) {
			int num = q.front(); q.pop();
			if (!q.empty() && q.front() == num) {
				q.pop();
				num *= 2;
			}
			arr[k][idx++] = num;
		}
	}
	return arr;
}

vector<vector<int>>right(vector<vector<int>>arr) {
	for (int k = 0; k < n; ++k) {
		queue<int>q;
		for (int j = n - 1; j >= 0; --j) {
			if (arr[k][j]) {
				q.push(arr[k][j]);
				arr[k][j] = 0;
			}
		}
		int idx = n - 1;
		while (!q.empty()) {
			int num = q.front(); q.pop();
			if (!q.empty() && q.front() == num) {
				q.pop();
				num *= 2;
			}
			arr[k][idx--] = num;
		}
	}
	return arr;
}

int dfs(vector<vector<int>>arr, int cnt) {
	if (cnt == 5)return big(arr);

	int result = dfs(up(arr), cnt + 1);
	result = max(result, dfs(down(arr), cnt + 1));
	result = max(result, dfs(left(arr), cnt + 1));
	result = max(result, dfs(right(arr), cnt + 1));

	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n;
	vector<vector<int>>arr(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	cout << dfs(arr, 0) << '\n';

	return 0;

}