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

ll ccw(pair<ll, ll>a, pair<ll, ll>b, pair<ll, ll>c) {
	return (a.first*b.second + b.first*c.second + c.first*a.second) - (b.first*a.second + c.first*b.second + a.first*c.second);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);


	int n;
	cin >> n;
	vector<pair<ll, ll>>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i].first >> a[i].second;

	ll ans = 0;
	for (int i = 2; i < n; ++i) {
		ans += ccw(a[0], a[i - 1], a[i]);
	}
	ans = abs(ans);
	cout << ans / 2;
	if (ans % 2 == 0)cout << ".0\n";
	else cout << ".5\n";

	return 0;

}