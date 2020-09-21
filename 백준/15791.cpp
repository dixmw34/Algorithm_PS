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

const ll Mod = 1000000007;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	ll n, m, a = 1, b = 1, c = 1;

	cin >> n >> m;

	for (ll i = n - m + 1; i <= n; ++i) {
		a = (a*i) % Mod;
	}

	for (ll i = 1; i <= m; ++i) {
		b = (b*i) % Mod;
	}

	ll test = Mod - 2;

	while (test) {
		if (test % 2) {
			c = (b*c) % Mod;
		}
		b = (b*b) % Mod;
		test /= 2;
	}

	cout << (a*c) % Mod << '\n';

	return 0;

}