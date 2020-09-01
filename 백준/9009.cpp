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
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int>f(2, 1);
	int i = 0;
	while (1) {
		int num = f[i] + f[i+1];
		if (num > 1000000000)break;
		else f.push_back(num);
		i++;
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		stack<int>s;
		for (int i = f.size() - 1; i >= 0; i--) {
			if (n >= f[i]) {
				s.push(f[i]);
				n -= f[i];
				if (n == 0)break;
			}
		}
		while (!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
		cout << '\n';
	}



	return 0;

}