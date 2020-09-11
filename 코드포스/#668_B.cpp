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
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll>p(n);
		for (int i = 0; i < n; ++i)cin >> p[i];
		ll ans = 0, test = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] > 0) {
				test += p[i];
			}
			else {
				if (p[i] < -test) {
					p[i] += test;
					ans += -p[i];
					test = 0;
				}
				else {
					test += p[i];
				}
			}
		}
		cout << ans << '\n';

	}

	

	return 0;

}