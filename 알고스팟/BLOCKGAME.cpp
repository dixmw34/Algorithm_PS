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
#include <cassert>

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

char c[1 << (25)];
vector<int>block;

inline int cal(int x, int y) {
	return (1 << (5 * x + y));
}

void makeblock() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			vector<int>tmp;
			tmp.push_back(cal(i, j));
			tmp.push_back(cal(i + 1, j));
			tmp.push_back(cal(i, j + 1));
			tmp.push_back(cal(i + 1, j + 1));
			int _sum = tmp[0] + tmp[1] + tmp[2] + tmp[3];
			for (int k = 0; k < 4; ++k)
				block.push_back(_sum - tmp[k]);
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i < 4)block.push_back(cal(i, j) + cal(i + 1, j));
			if (j < 4)block.push_back(cal(i, j) + cal(i, j + 1));
		}
	}
}

char sol(int state) {
	char& ret = c[state];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < block.size(); ++i) {
		if (!(state&block[i]) && !sol(state | block[i])) {
			return ret = 1;
		}
	}
	return ret;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	makeblock();
	memset(c, -1, sizeof(c));

	int t;
	cin >> t;
	while (t--) {	
		char ch;
		int start = 0;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cin >> ch;
				if (ch == '#')
					start |= cal(i, j);
			}
		}
		
		char result = sol(start);
		if (result == 1)
			cout << "WINNING\n";
		else
			cout << "LOSING\n";
	}
	

	return 0;
}