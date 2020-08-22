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

int n, m;
int a[200];
int b[200];

bool sol(int c) {

	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < m; j++) {
			int num = a[i] & b[j];
			if ((c | num) == c) {
				check = true;
				break;
			}
		}
		if (!check)return false;
	}

	return true;

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];

	int ans = pow(2, 9) - 1;

	for (int i = 8; i >= 0; i--) {
		if (sol(ans - (1 << i)))ans -= (1 << i);
	}

	cout << ans << '\n';

	return 0;

}