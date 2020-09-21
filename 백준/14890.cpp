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

int n, L;
int arr[100][100];

bool sol_x(int x, int y) {
	int test = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i][y] == arr[i - 1][y]) {
			test++;
		}
		else if (arr[i][y] > arr[i - 1][y]) {
			if (arr[i][y] - arr[i - 1][y] > 1)return false;
			if (test < L)return false;
			test = 1;
		}
		else {
			if (arr[i][y] - arr[i - 1][y] < -1)return false;
			for (int j = 1; j < L; ++j) {
				if (i + j > n || arr[i + j][y] != arr[i][y])return false;
			}
			i += L - 1;
			test = 0;
		}
	}
	return true;
}

bool sol_y(int x, int y) {
	int test = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[x][i] == arr[x][i - 1]) {
			test++;
		}
		else if (arr[x][i] > arr[x][i - 1]) {
			if (arr[x][i] - arr[x][i - 1] > 1)return false;
			if (test < L)return false;
			test = 1;
		}
		else {
			if (arr[x][i] - arr[x][i - 1] < -1)return false;
			for (int j = 1; j < L; ++j) {
				if (i + j > n || arr[x][i + j] != arr[x][i])return false;
			}
			i += L - 1;
			test = 0;
		}
	}
	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n >> L;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (sol_x(0, i))ans++;
		if (sol_y(i, 0))ans++;
	}

	cout << ans << '\n';


	return 0;

}