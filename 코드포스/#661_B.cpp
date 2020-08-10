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

const int MAX = 1000001;
const int MOD = 1000000007;

vector<vector<pi>>road;
vector<vector<pi>>back;
vector<int>inDegree;
vector<int>outDegree;
vector<int>time;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	ll minA, minB, ans;
	vector<pair<ll, ll>>arr;

	cin >> t;
	while (t--) {
		minA = minB = 1000000000;
		ans = 0;
		cin >> n;
		arr = vector<pair<ll, ll>>(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
			minA = min(arr[i].first, minA);
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].second;
			minB = min(arr[i].second, minB);
		}
		for (int i = 0; i < n; i++) {
			ans += max(arr[i].first - minA, arr[i].second - minB);
		}
		cout << ans << '\n';
		arr.clear();
	}



	return 0;


}