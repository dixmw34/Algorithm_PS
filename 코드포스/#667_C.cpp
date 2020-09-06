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
	cin.tie(NULL); cout.tie(NULL);

	int t, n, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		int sub = y - x;
		int ans = INF;
		vector<int>arr;
		
		for (int i = n - 1; i >= 1; i--) {
			vector<int>a;
			int Max = y;
			if (sub%i == 0) {
				int dis = sub / i;
				for (int k = x; k <= y; k += dis) {
					a.push_back(k);
				}
				while (a.size() < n ) {
					x -= dis;
					if (x > 0)a.push_back(x);
					else break;
				}
				while (a.size() < n) {
					y += dis;
					a.push_back(y);
					Max = y;
				}
				if (ans > Max) {
					ans = Max;
					arr = a;
				}
			}
		}

		sort(arr.begin(), arr.end());
		for (int i = 0; i < n; i++)cout << arr[i] << ' ';
		cout << '\n';

	}



	return 0;

}