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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, a, mx;

	cin >> t;
	while (t--) {
		cin >> n;
		mx = 0;
		map<int, int>m;
		map<int, int>::iterator it;
		for (int i = 0; i < n; i++) {
			cin >> a;
			it = m.find(a);
			if (it == m.end()) {
				m.insert(pi(a, 1));
				mx = max(1, mx);
			}
			else {
				it->second++;
				mx = max(it->second, mx);
			}
		}

		int ans = -1;
		for (auto i : m) {
			if (i.second == mx) {
				ans++;
				n -= mx;
			}
		}
		ans += (n / (mx-1));

		cout << ans << '\n';
		
	}


	return 0;

}