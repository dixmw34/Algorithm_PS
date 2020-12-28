#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

char chess[8][8], color[8][8];
int n, ans = 0;

bool check(int a, int b) {
	if (chess[a][b] != '.')
		return false;
	int x = a - 1, y = b - 1;
	while (true) {
		if (x < 0 || y < 0)
			break;
		if (chess[x][y] == '!')
			return false;
		else if (chess[x][y] == '*')
			break;
		x--; y--;
	}
	x = a - 1, y = b + 1;
	while (true) {
		if (x < 0 || y >= n)
			break;
		if (chess[x][y] == '!')
			return false;
		else if (chess[x][y] == '*')
			break;
		x--; y++;
	}
	return true;
}

void sol(int num, int cnt, int id) {
	if (num >= n * n) {
		ans = max(ans, cnt);
		return;
	}

	int x = num / n, y = num % n;
	while (++num < n*n) {
		int a = num / n, b = num % n;
		if (color[a][b] == id)
			break;
	}
	if (check(x, y)) {
		chess[x][y] = '!';
		sol(num, cnt + 1, id);
		chess[x][y] = '.';
	}
	
	sol(num, cnt, id);
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> chess[i][j];
				color[i][j] = (i + j) % 2;
			}
		}
		ans = 0;
		sol(0, 0, 0);
		int result = ans;
		if (n != 1) {
			ans = 0;
			sol(1, 0, 1);
			result += ans;
		}
		cout << result << '\n';
	}

	

	return 0;
}