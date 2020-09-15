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

bool cmp(pi a, pi b) {
	return a.second > b.second;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pi>a(n);
		for (int i = 0; i < n; ++i) cin >> a[i].first;
		for (int i = 0; i < n; ++i) cin >> a[i].second;

		sort(a.begin(), a.end(), cmp);

		int time = 0;
		int now = 0;
		for (int i = 0; i < n; ++i) {
			time = max(time, now + a[i].first + a[i].second);
			now += a[i].first;
		}
		
		cout << time << '\n';
		
	}

	return 0;

}