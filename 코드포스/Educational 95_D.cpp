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
#include<string.h>

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

	int n, q, t, x;
	cin >> n >> q;
	vector<int>p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	priority_queue<pi>pq;
	for (int i = 1; i < n; ++i) {
		pq.push(pi(p[i] - p[i - 1], p[i]));
	}

	if (n <= 2)cout << 0 << '\n';
	else cout << p[n - 1] - p[0] - pq.top().first << '\n';

	while (q--) {
		cin >> t >> x;
		if (t == 0) {
			int idx = lower_bound(p.begin(), p.end(), x) - p.begin();
			p.erase(p.begin() + idx);
			if (idx != 0 && idx != n - 1)pq.push(pi(p[idx] - p[idx - 1], p[idx]));
			--n;
		}
		else {
			int idx = lower_bound(p.begin(), p.end(), x) - p.begin();
			p.insert(p.begin() + idx, x);
			if (idx != 0)pq.push(pi(p[idx] - p[idx - 1], p[idx]));
			if (idx != n)pq.push(pi(p[idx + 1] - p[idx], p[idx + 1]));
			++n;

		}
		if (n <= 2)cout << 0 << '\n';
		else {
			while (1) {
				int idx = lower_bound(p.begin(), p.end(), pq.top().second) - p.begin();
				if (idx == n || p[idx] != pq.top().second) {
					pq.pop();
					continue;
				}
				if (idx == 0 || p[idx - 1] != pq.top().second - pq.top().first) {
					pq.pop();
					continue;
				}
				break;
			}
			cout << p[n - 1] - p[0] - pq.top().first << '\n';
		}
	}

	return 0;

}