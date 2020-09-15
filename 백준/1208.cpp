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
	cin.tie(NULL); std::cout.tie(NULL);

	int n, s;
	cin >> n >> s;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	map<int, ll>m1;
	m1[0] = 1;
	int mid = n / 2;
	for (int i = 0; i <= mid; ++i) {
		map<int, ll>m;
		for (auto x : m1) {
			m[x.first + a[i]] += x.second;
			m[x.first] += x.second;
		}
		m1 = m;
	}

	map<int, ll>m2;
	m2[0] = 1;
	for (int i = mid + 1; i < n; ++i) {
		map<int, ll>m;
		for (auto x : m2) {
			m[x.first + a[i]] += x.second;
			m[x.first] += x.second;
		}
		m2 = m;
	}

	ll ans = 0;
	for (auto x : m1) {
		ans += x.second*m2[s - x.first];
	}

	if (s == 0)ans--;
	cout << ans << '\n';

	return 0;

}