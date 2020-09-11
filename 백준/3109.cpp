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

int R, C;
char arr[10000][500];

bool sol(int x, int y) {
	if (y == C - 1)return true;

	for (int i = 0; i < 3; ++i) {
		if (x + (i - 1) >= 0 && x + (i - 1) < R && arr[x + (i - 1)][y + 1] == '.') {
			arr[x + (i - 1)][y + 1] = 'x';
			if (sol(x + (i - 1), y + 1))return true;
		}
	}
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < R; ++i) {
		if (sol(i, 0))ans++;
	}
	cout << ans << '\n';


	return 0;

}