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

	int n, m, a, b, set_cost = INF, one_cost = INF, ans = 0;

	cin >> n >> m;

	while (m--) {
		cin >> a >> b;
		set_cost = min(set_cost, a);
		one_cost = min(one_cost, b);
	}

	while (n) {
		if (n >= 6) {
			if (set_cost >= (one_cost * 6)) {
				ans = one_cost * n;
				cout << ans << '\n';
				return 0;
			}
			else {
				ans += set_cost * (n / 6);
				n %= 6;
			}
		}
		else {
			if (set_cost >= (one_cost * n)) {
				ans += one_cost * n;
				cout << ans << '\n';
				return 0;
			}
			else {
				ans += set_cost;
				cout << ans << '\n';
				return 0;
			}
		}
	}
	cout << ans << '\n';


	return 0;
	

}