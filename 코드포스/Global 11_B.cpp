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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

int a[50];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		priority_queue<int>pq;
		int ans = 0, test = 0;
		bool win = false;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') {
				if (ans > 0)test++;
				win = false;
			}
			else {
				if (test > 0) {
					pq.push(-test);
					test = 0;
				}
				if (win)ans += 2;
				else ans += 1;
				win = true;
			}
		}
		while (!pq.empty()) {
			if (-pq.top() > k) {
				ans += 2 * k;
				k = 0;
				break;
			}
			ans += 2 * (-pq.top()) + 1;
			k += pq.top();
			pq.pop();
		}
		if (ans > 0)ans = min(ans + 2 * k, 2 * n - 1);
		else if (k > 0) ans = min(2 * k - 1, 2 * n - 1);
		cout << ans << '\n';
	}

	

	return 0;

}