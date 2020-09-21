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

ll gcd(ll a, ll b) {
	while (a%b) {
		ll r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	ll n, m, time = 0;

	cin >> n >> m;
	vector<ll>a(m);
	for (int i = 0; i < m; ++i)cin >> a[i];
	ll num;
	if (m > 1) {
		num = (a[0] / gcd(a[0], a[1]))*a[1];
		for (int i = 2; i < m; ++i) {
			num = (num / gcd(num, a[i]))*a[i];
		}
	}
	else num = a[0];
	ll reset = 0;
	for (int i = 0; i < m; ++i) {
		reset += num / a[i];
	}
	while (reset <= n)n -= reset;

	if (n <= m)cout << n << '\n';
	else {
		n -= m;
		ll left = 1, right = num - 1, ans = 0;

		while (left <= right) {
			ll mid = (left + right) / 2;
			ll test = 0;
			for (int i = 0; i < m; ++i) {
				test += mid / a[i];
			}
			if (test < n) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		for (int i = 0; i < m; ++i) {
			n -= ans / a[i];
		}
		while (n) {
			ans++;
			for (int i = 0; i < m; ++i) {
				if (ans%a[i] == 0) {
					if (--n == 0) {
						cout << i + 1 << '\n';
						return 0;
					}
				}
			}
			
		}
		
	}
	


	return 0;

}