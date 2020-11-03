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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll time = 0;
		vector<pair<ll, ll>>a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
		}
		for (int i = 0; i < n; ++i) {
			cin >> a[i].second;
			time += a[i].second;
		}
		sort(a.begin(), a.end());
		ll result = time;
		for (int i = 0; i < n; ++i) {
			time -= a[i].second;
			result = min(result, max(a[i].first, time));
		}
		cout << result << '\n';
		
	}


	return 0;

}