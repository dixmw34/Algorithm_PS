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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, ans = 0;
	cin >> N;
	vector<ll>arr(N);
	for (ll i = 0; i < N; i++)cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<>());
	for (ll i = 0; i < N; i++) {
		if (arr[i] > i) {
			ans += (arr[i] - i);
		}
		else break;
	}
	cout << ans << '\n';
		

	return 0;

}