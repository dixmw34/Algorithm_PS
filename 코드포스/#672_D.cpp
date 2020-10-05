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

const ll Mod = 998244353;

vector<ll>fac(300001, 1);
vector<ll>inv_fac(300001, 1);

ll sol(int n, int m) {
	return ((fac[n] * inv_fac[n - m]) % Mod)*inv_fac[m] % Mod;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k, l, r;

	cin >> n >> k;

	for (int i = 2; i <= n; ++i) {
		fac[i] = (fac[i - 1] * (ll)i) % Mod;

		ll a = fac[i], ind = Mod - 2;
		while (ind) {
			if (ind % 2)inv_fac[i] = (inv_fac[i] * a) % Mod;
			a = (a*a) % Mod;
			ind /= (ll)2;
		}
	}

	vector<int>a(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		a[i] = 2 * l;
		a[n + i] = r * 2 + 1;
	}
	sort(a.begin(), a.end());

	ll ans = 0;
	int num = 0;

	for (int i = 0; i < 2 * n;) {
		int j = i;
		while (i < 2 * n && a[i] == a[j])++i;

		int added = i - j;

		if (a[j] % 2 == 0) {
			if (added + num >= k)ans = (ans + sol(added + num, k)) % Mod;
			if (num >= k)ans = (ans - sol(num, k)) % Mod;
			if (ans < 0)ans += Mod;
			num += added;
		}
		else {
			num -= added;
		}
	}

	cout << ans << '\n';

	return 0;

}