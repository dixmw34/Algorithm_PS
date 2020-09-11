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
const ll Max = 1e15 + 1;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<pi>>arr(n);
	
	while (m--) {
		cin >> a >> b >> c;
		arr[a - 1].push_back(pi(b - 1, c));
	}

	vector<ll>visit(n, Max);
	visit[0] = 0;
	bool is_cycle = false;

	for (int t = 0; t <= n; t++) {
		for (int i = 0; i < n; i++) {
			if (visit[i] == Max)continue;
			for (int k = 0; k < arr[i].size(); k++) {
				int next = arr[i][k].first;
				ll new_val = visit[i] + (ll)arr[i][k].second;
				if (visit[next] > new_val) {
					visit[next] = new_val;
					if (t == n) is_cycle = true;
				}
			}
		}
	}

	if (is_cycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 1; i < n; i++) {
			if (visit[i] == Max)cout << -1 << '\n';
			else cout << visit[i] << '\n';
		}
	}

	return 0;

}