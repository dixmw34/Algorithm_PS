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

const int MIN = -1e9 - 1;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, MAX = 0;
	ll k;

	cin >> t;
	while (t--) {
		MAX = MIN;
		cin >> n >> k;
		vector<int>arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			MAX = max(MAX, arr[i]);
		}
		int num = MAX; MAX = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = num - arr[i];
			MAX = max(MAX, arr[i]);
		}
		if (k % 2 == 1) {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << ' ';
			}
			cout << endl;
		}
		else {
			int num = MAX; MAX = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = num - arr[i];
			}
			for (int i = 0; i < n; i++) {
				cout << arr[i] << ' ';
			}
			cout << endl;
		}
	}

	return 0;

}