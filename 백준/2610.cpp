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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k, a, b;
	cin >> n >> k;

	vector<vector<int>>arr(n, vector<int>(n, INF));

	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		arr[a - 1][b - 1] = arr[b - 1][a - 1] = 1;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)continue;
				if (arr[i][j] > arr[i][k] + arr[k][j])arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	priority_queue<int>pq;
	vector<bool>visit(n, false);
	for (int i = 0; i < n; ++i) {
		if (visit[i])continue;
		vector<int>a;
		a.push_back(i);
		visit[i] = true;
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] != INF) {
				a.push_back(j);
				visit[j] = true;
			}
		}
		vector<int>test(a.size(), 0);
		for (int x = 0; x < a.size(); ++x) {
			for (int y = 0; y < a.size(); ++y) {
				if (x == y)continue;
				test[x] = max(test[x], arr[a[x]][a[y]]);
			}
		}
		int mn = 0;
		for (int j = 1; j < a.size(); ++j) {
			if (test[mn] > test[j])mn = j;
		}
		pq.push(-a[mn] - 1);
	}
	
	cout << pq.size() << '\n';
	while (!pq.empty()) {
		cout << -pq.top() << '\n';
		pq.pop();
	}
	

	return 0;

}