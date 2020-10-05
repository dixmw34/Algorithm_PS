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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int n = 10;
char arr[10][10];
int paper[] = { 5, 5, 5, 5, 5 };

int sol(int now) {
	while (now < 100) {
		int x = now / 10, y = now % 10;
		if (arr[x][y] == '1') {
			int num = INF;

			for (int k = 0; k < 5; ++k) {
				if (x + k < 10 && y + k < 10 && paper[k]) {
					bool flag = true;
					for (int i = 0; i <= k; ++i) {
						for (int j = 0; j <= k; ++j) {
							if (arr[x + i][y + j] == '0')flag = false;
						}
					}
					if (flag) {
						for (int i = 0; i <= k; ++i) {
							for (int j = 0; j <= k; ++j) {
								arr[x + i][y + j] = '0';
							}
						}
						paper[k]--;
						num = min(num, sol(now + 1) + 1);
						paper[k]++;
						for (int i = 0; i <= k; ++i) {
							for (int j = 0; j <= k; ++j) {
								arr[x + i][y + j] = '1';
							}
						}
					}
				}
			}
			return num;
		}
		++now;
	}
	return 0;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> arr[i][j];
		}
	}
	
	int result = sol(0);
	if (result == INF)cout << -1 << '\n';
	else cout << result << '\n';

	return 0;

}