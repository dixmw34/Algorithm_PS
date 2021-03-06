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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;
	vector<ll>_time(m);
	for (int i = 0; i < m; ++i) {
		cin >> _time[i];
	}

	if (n <= m) {
		cout << n << '\n';
		return 0;
	}
	n -= m;

	ll left = 0, right = 2000000000LL * 30LL, ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll test = 0;
		for (int i = 0; i < m; ++i) {
			test += mid / _time[i];
		}
		if (test < n) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	for (int i = 0; i < m; ++i) {
		n -= ans / _time[i];
	}

	while (true) {
		ans++;
		for (int i = 0; i < m; ++i) {
			if (ans%_time[i] == 0) {
				n--;
				if (n == 0) {
					cout << i + 1 << '\n';
					return 0;
				}
			}
		}
	}


	return 0;
}