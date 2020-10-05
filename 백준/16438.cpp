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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, test = 1;
	char ch = 'A';
	cin >> n;

	for (int i = 0; i < 7; ++i) {
		ch = 'A';
		for (int j = 0; j < n;) {
			if (ch == 'C')ch = 'A';
			for (int k = 0; k < test; ++k, ++j) {
				if (j == n)break;
				else if (test >= n && j == n - 1) {
					cout << 'B';
					++j;
					break;
				}
				cout << ch;
			}
			++ch;
		}
		test *= 2;
		cout << '\n';
	}

	return 0;

}