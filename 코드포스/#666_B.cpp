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
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	ll ans = 0, k = 2;
	cin >> n;
	vector<ll>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i];
	}
	ans -= (ll)n;
	sort(arr.begin(), arr.end());

	while (1) {
		ll sum = 0;
		ll test = 1;
		for (int i = 0; i < n; i++) {
			sum += abs(arr[i] - test);
			test *= k;
			if (test < 0) {
				sum = ans * 2;
				break;
			}
		}
		if (ans < sum) {
			break;
		}
		ans = sum;
		k++;
	}

	cout << ans << '\n';

	return 0;

}