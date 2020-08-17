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

vector<vector<bool>>check;

void sol(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			check[x + i][y + j] = !check[x + i][y + j];
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, ans = 0;
	char ch;

	cin >> N >> M;

	vector<vector<char>>arr(N, vector<char>(M));
	check = vector<vector<bool>>(N, vector<bool>(M, true));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			if (arr[i][j] != ch)check[i][j] = false;
		}
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			if (!check[i][j]) {
				ans++;
				sol(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	cout << ans << '\n';

	return 0;

}