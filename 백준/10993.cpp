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
#include <string.h>
#include <iomanip>

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

vector<vector<char>>arr;

void sol(int num) {
	if (num == 1) {
		arr = { {'*'} };
		return;
	}

	if (num % 2 == 1) {
		vector<vector<char>>test = arr;
		arr = vector<vector<char>>(test.size() * 2 + 1, vector<char>((test[0].size() + 2) * 2 - 1, ' '));
		for (int i = 0; i < arr[0].size(); ++i)arr[arr.size()-1][i] = '*';
		int k = arr[0].size() / 2;
		for (int i = 0; i < arr.size(); ++i) {
			arr[i][k] = arr[i][arr[0].size() - 1 - k] = '*';
			if (arr[0].size() - 1 - 2 * k - 1 == test[0].size()) {
				for (int x = 0; x < test.size(); ++x) {
					for (int y = 0; y < test[0].size(); ++y) {
						arr[x + i][y + k + 1] = test[x][y];
					}
				}
			}
			--k;
		}
		return;
	}
	else {
		vector<vector<char>>test = arr;
		arr = vector<vector<char>>(test.size() * 2 + 1, vector<char>((test[0].size() + 2) * 2 - 1, ' '));
		for (int i = 0; i < arr[0].size(); ++i)arr[0][i] = '*';
		int k = 0;
		for (int i = 0; i < arr.size(); ++i) {
			arr[i][k] = arr[i][arr[0].size() - 1 - k] = '*';
			if (arr[0].size() - 1 - 2 * k - 1 == test[0].size()) {
				for (int x = 0; x < test.size(); ++x) {
					for (int y = 0; y < test[0].size(); ++y) {
						arr[x + 1][y + k + 1] = test[x][y];
					}
				}
			}
			if (k == arr[0].size() - 1 - k)break;
			++k;
		}
		return;
	}
}


int main(void) {

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)sol(i);

	if (n % 2 == 1) {
		int k = arr[0].size() / 2;
		for (int i = 0; i < arr.size(); ++i) {
			for (int j = 0; j <= k; ++j)cout << arr[i][j];
			cout << '\n';
			++k;
		}
	}
	else {
		int k = arr[0].size() - 1;
		for (int i = 0; i < arr.size(); ++i) {
			for (int j = 0; j <= k; ++j)cout << arr[i][j];
			cout << '\n';
			--k;
		}
	}

	

	return 0;

}