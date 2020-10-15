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

vector<int>dice(7, 0);

void changeDice(int d) {
	vector<int>temp = dice;
	if (d == 0) {
		dice[3] = temp[1];
		dice[1] = temp[4];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (d == 1) {
		dice[3] = temp[6];
		dice[1] = temp[3];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (d == 2) {
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	else if (d == 3) {
		dice[5] = temp[1];
		dice[6] = temp[5];
		dice[2] = temp[6];
		dice[1] = temp[2];
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, x, y, k, arr[20][20], d;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	while (k--) {
		cin >> d;
		--d;
		if (x + dx[d] < 0 || x + dx[d] >= n || y + dy[d] < 0 || y + dy[d] >= m)continue;
		changeDice(d);
		x += dx[d]; y += dy[d];

		if (arr[x][y]) {
			dice[6] = arr[x][y];
			arr[x][y] = 0;
		}
		else {
			arr[x][y] = dice[6];
		}
		cout << dice[1] << '\n';
	}
	

	return 0;

}