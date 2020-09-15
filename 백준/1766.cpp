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

	int n, m, a, b;

	cin >> n >> m;

	vector<int>inDegree(n + 1, 0);
	vector<vector<int>>arr(n + 1);
	while(m--) {
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	priority_queue<int>pq;
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0)pq.push(-i);
	}

	while (!pq.empty()) {
		int now = -pq.top(); pq.pop();
		cout << now << ' ';
		for (int i = 0; i < arr[now].size(); ++i) {
			if (--inDegree[arr[now][i]] == 0)pq.push(-arr[now][i]);
		}
	}
	cout << '\n';

	return 0;

}