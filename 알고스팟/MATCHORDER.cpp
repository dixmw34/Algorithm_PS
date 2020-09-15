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

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int>b(n);
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(b.begin(), b.end());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > b[b.size() - 1]) {
				b.erase(b.begin());
			}
			else {
				int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
				ans++;
				b.erase(b.begin() + idx);
			}
		}
		cout << ans << '\n';
		
	}

	return 0;

}