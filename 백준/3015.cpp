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

	ll ans = 0;
	stack<pi>s;
	int n, num;
	cin >> n;
	while (n--) {
		cin >> num;
		while (!s.empty() && s.top().first < num) {
			ans += (ll)s.top().second;
			s.pop();
		}

		if (!s.empty() && s.top().first == num) {
			int res = s.top().second;
			s.pop();
			if (s.size())ans += 1LL;
			ans += res;
			s.push(pi(num, res + 1));
		}
		else {
			if (!s.empty())ans += 1LL;
			s.push(pi(num, 1));
		}
	}
	cout << ans << '\n';


	return 0;
}