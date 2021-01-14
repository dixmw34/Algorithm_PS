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
#include <cassert>

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

const ll mod = 1000000007;

ll mypow(ll num, ll fac) {
	ll result = 1;
	while (fac) {
		if (fac % 2) {
			result = (result*num) % mod;
		}
		num = (num*num) % mod;
		fac /= 2;
	}
	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;
	ll a = 1;
	for (ll i = k + 1; i <= n; ++i) {
		a = (a*i) % mod;
	}
	ll b = 1;
	for (ll i = 1; i <= n - k; ++i) {
		b = (b*i) % mod;
	}
	b = mypow(b, mod - 2);
	cout << (a*b) % mod;



	return 0;
}