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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<string>arr(n);
	ll ans = 0;
	map<ll, ll>_map;
	map<ll, ll>::iterator it, jt;

	for (ll i = 0; i < n; ++i) {
		cin >> arr[i];
		int num = 0;
		for (int k = 0; k < arr[i].size(); ++k) {
			int temp = (1 << (arr[i][k] - '0'));
			num |= temp;
		}
		_map[num]++;
	}

	for (it = _map.begin(); it != _map.end(); ++it) {
		for (jt = it; jt != _map.end(); ++jt) {
			if (jt == it)
				ans += (jt->second)*(jt->second - 1) / 2;
			else if((it->first&jt->first))
				ans += (it->second)*(jt->second);
		}
	}

	cout << ans << '\n';


	return 0;
}