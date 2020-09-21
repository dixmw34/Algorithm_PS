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

	int n, k, a;
	ll ans = 0;

	cin >> n >> k;
	vector<int>arr(k);
	queue<int>q;

	for (int i = 0; i < k; ++i) {
		cin >> arr[i];
		q.push(arr[i]);
	}
	sort(arr.begin(), arr.end());
	ans += (ll)(arr[(k-1) / 2]);

	for (int i = k; i < n; ++i) {
		cin >> a;
		q.push(a);
		int idx = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
		arr.insert(arr.begin() + idx, a);

		idx = lower_bound(arr.begin(), arr.end(), q.front()) - arr.begin();
		arr.erase(arr.begin() + idx);
		q.pop();
		ans += (ll)(arr[(k-1) / 2]);
	}

	cout << ans << '\n';


	return 0;

}