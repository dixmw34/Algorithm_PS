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

ll a, b;
ll const Mod = 20090711;

ll signal(ll num) {
	return (num*a + b) % Mod;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n >> a >> b;
		ll start = 1983, ans = 1983;
		vector<ll>v(1, 1983);
		for (int i = 1; i < n; ++i) {
			start = signal(start);
			
			int idx = lower_bound(v.begin(), v.end(), start) - v.begin();
			v.insert(v.begin() + idx, start);

			ans = (ans + v[(v.size()-1)/2]) % Mod;
		}
		cout << ans << '\n';

	}

	return 0;

}