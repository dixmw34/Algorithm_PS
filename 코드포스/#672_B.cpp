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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; ++i)cin >> a[i];

		sort(a.begin(), a.end());

		ll ans = 0;
		for (int i = 1; i < n; ++i) {
			int test = 1;
			while (test * 2 <= a[i])test *= 2;
			int idx = lower_bound(a.begin(), a.end(), test) - a.begin();
			ans+=(ll)(i - idx);
		}
		cout << ans << '\n';
	}



	return 0;

}