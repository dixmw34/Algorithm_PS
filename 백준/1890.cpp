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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, C, M, start, end, amount, ans = 0;
	cin >> N >> C >> M;

	vector<map<int, int>>arr(N+1);
	queue<pi>q;

	while (M--) {
		cin >> start >> end >> amount;

		arr[start][end] += amount;
	}

	for (int i = 1; i <= N; i++) {
		int size = C;

		if (!q.empty() && q.front().first == i) {
			ans += q.front().second;
			q.pop();
		}

		while (!q.empty()) {
			arr[i][q.front().first] += q.front().second;
			q.pop();
		}

		for (auto x : arr[i]) {
			int a = min(size, x.second);
			q.push(pi(x.first, a));
			size -= a;
			if (size == 0)break;
		}

	}
	cout << ans << '\n';


	return 0;

}