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

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	char ch;
	cin >> t;
	while (t--) {
		map<int, ll>m;
		m[0] = 1;
		ll ans = 0;
		int sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ch;
			sum += ch - '1';
			ans += m[sum];
			m[sum]++;
		}
		cout << ans << '\n';
	}

	return 0;

}