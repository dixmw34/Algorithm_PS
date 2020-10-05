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

int n, ans = INF;
int p[10];
vector<vector<int>>arr(10);
vector<bool>test;

void sol(int a, int b) {
	vector<bool>visit(n, false);
	int cnt = 0, result = 0;
	queue<int>q;
	visit[a] = visit[b] = true;
	q.push(a);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		++cnt;
		result += p[now];
		for (int i = 0; i < arr[now].size(); ++i) {
			if (test[now] == test[arr[now][i]] && !visit[arr[now][i]]) {
				visit[arr[now][i]] = true;
				q.push(arr[now][i]);
			}
		}
	}

	q.push(b);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		++cnt;
		result -= p[now];
		for (int i = 0; i < arr[now].size(); ++i) {
			if (test[now] == test[arr[now][i]] && !visit[arr[now][i]]) {
				visit[arr[now][i]] = true;
				q.push(arr[now][i]);
			}
		}
	}

	if (cnt == n)ans = min(ans, abs(result));
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int m, num;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> p[i];
	for (int i = 0; i < n; ++i) {
		cin >> m;
		while (m--) {
			cin >> num;
			arr[i].push_back(num - 1);
		}
	}
	test = vector<bool>(n, false);
	for (int i = 1; i <= (n + 1) / 2; ++i) {
		test[n - i] = true;
		do {
			int a, b;
			for (int j = 0; j < n; ++j) {
				if (test[j]) a = j;
				else b = j;
			}
			sol(a, b);
			//cout << "ans : " << ans << '\n';
		} while (next_permutation(test.begin(), test.end()));
	}

	if (ans == INF)cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;

}