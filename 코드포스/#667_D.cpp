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

int sol(ll num) {
	int a = 0;
	while (num) {
		a += (int)(num % (ll)10);
		num /= (ll)10;
	}
	return a;
}

pi test(ll num) {
	string a = to_string(num);
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != '0')return pi(a[i] - '0', i);
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, s;
	ll n;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		ll ans = 0;
		while (sol(n) > s) {
			pi a = test(n);
			ll k = (ll)pow(10, a.second)*(ll)(10 - a.first);
			n += k;
			ans += k;
		}
		cout << ans << '\n';
	}




	return 0;

}