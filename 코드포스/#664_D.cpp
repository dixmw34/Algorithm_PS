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

bool cmp(ll a, ll b) {
	return a > b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, d, m, a;
	cin >> n >> d >> m;

	vector<ll>big;
	vector<ll>small;

	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a > m) big.push_back(a);
		else small.push_back(a);
	}

	sort(big.begin(), big.end(), cmp);
	for (int i = 1; i < big.size(); i++) {
		big[i] += big[i - 1];
	}
	big.insert(big.begin(), 0);

	sort(small.begin(), small.end(), cmp);
	for (int i = 1; i < small.size(); i++) {
		small[i] += small[i - 1];
	}
	small.insert(small.begin(), 0);
	while (small.size() < n)small.push_back(small.back());

	ll ans = small.back();
	int idx = n - 1;

	for (int i = 1; i < big.size(); i++) {
		if (idx < 0)break;
		ans = max(ans, big[i] + small[idx]);
		idx -= (d + 1);
	}

	cout << ans << '\n';

	return 0;

}