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

vector<vector<char>>arr;

int sol(int x, int y) {

	int num1 = 0, num2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2) {
				if (arr[x + i][y + j] != 'W')num1++;
				else num2++;
			}
			else {
				if (arr[x + i][y + j] != 'B')num1++;
				else num2++;
			}
		}
	}

	return min(num1, num2);

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, ans = INF;
	cin >> n >> m;
	arr = vector<vector<char>>(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			ans = min(ans, sol(i, j));
		}
	}

	cout << ans << '\n';

	return 0;

}