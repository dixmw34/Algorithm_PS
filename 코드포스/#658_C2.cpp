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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string a, b;
		cin >> n;
		cin >> a >> b;
		bool flip = false;
		int idx = 0;
		queue<int>q;
		for (int i = n - 1; i >= 0; --i) {
			if (flip^(a[idx] == b[i]))q.push(1);
			q.push(i + 1);
			if (flip)idx -= i;
			else idx += i;
			flip = !flip;
		}

		cout << q.size() << ' ';
		while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
		}
		cout << '\n';
	}


	return 0;

}