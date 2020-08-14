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

	int n;
	cin >> n;
	vector<vector<int>>arr(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (arr[i][j] && arr[i][k] && arr[k][j] && arr[i][j] == arr[i][k] + arr[k][j])arr[i][j] = 0;
				else if (arr[i][j] && arr[i][k] && arr[k][j] && arr[i][j] > arr[i][k] + arr[k][j]) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			result += arr[i][j];
		}
	}
	cout << result << '\n';

	return 0;
	

}