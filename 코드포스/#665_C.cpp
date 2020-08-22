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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

const int MAX = 1e9+1;

int gcd(int a, int b) {
	while (a%b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;

	cin >> t;

	while (t--) {
		
		cin >> n;
		vector<int>arr(n);

		int mn = MAX;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mn = min(mn, arr[i]);
		}

		priority_queue<int>pq;

		for (int i = 0; i < n; i++) {
			if (gcd(mn, arr[i]) == mn) {
				pq.push(-arr[i]);
			}
		}

		for (int i = 0; i < n; i++) {
			if (gcd(mn, arr[i]) == mn) {
				arr[i] = -pq.top();
				pq.pop();
			}
		}
		bool test = true;
		for (int i = 1; i < n; i++) {
			if (arr[i]<arr[i-1]) {
				test = false;
				break;
			}
		}

		if (test)cout << "YES\n";
		else cout << "NO\n";
		
	}

	return 0;

}