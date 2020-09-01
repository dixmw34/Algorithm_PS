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

bool test(vector<ll>a) {
	int odd = 0;
	int even = 0;

	for (int i = 0; i < 4; i++) {
		if (a[i] % 2)odd++;
		else even++;
	}
	if (even >= 3)return true;
	else return false;

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<bool>>visit(n, vector<bool>(m, false));

	a--; b--;
	int test = 0;

	cout << a + 1 << ' ' << b + 1 << '\n';
	visit[a][b] = true;
	for (int x = a; x < n; x++) {
		if (test == 0) {
			for (int y = 0; y < m; y++) {
				if (!visit[x][y]) {
					cout << x + 1 << ' ' << y + 1 << '\n';
					visit[x][y] = true;
				}
			}
			test = m - 1;
		}
		else {
			for (int y = m-1; y >= 0; y--) {
				if (!visit[x][y]) {
					cout << x + 1 << ' ' << y + 1 << '\n';
					visit[x][y] = true;
				}
			}
			test = 0;
		}
	}

	for (int x = 0; x < a; x++) {
		if (test == 0) {
			for (int y = 0; y < m; y++) {
				if (!visit[x][y]) {
					cout << x + 1 << ' ' << y + 1 << '\n';
					visit[x][y] = true;
				}
			}
			test = m - 1;
		}
		else {
			for (int y = m - 1; y >= 0; y--) {
				if (!visit[x][y]) {
					cout << x + 1 << ' ' << y + 1 << '\n';
					visit[x][y] = true;
				}
			}
			test = 0;
		}
	}

	return 0;
	

}