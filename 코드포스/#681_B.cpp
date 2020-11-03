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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ll a, b, result;
		string s;
		cin >> a >> b >> s;

		priority_queue<ll>pq;
		bool flag = false;
		ll zero = 0, one = 0, plus = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '1') {
				flag = true;
				if (zero) {
					pq.push(-zero);
					zero = 0;
				}
			}
			else if(flag) {
				if (s[i - 1] == '1')one++;
				++zero;
			}
		}
		if (s[s.size() - 1] == '1')one++;

		result = one * a;
		while (!pq.empty()) {
			one--;
			plus -= pq.top();
			pq.pop();
			result = min(one*a + plus * b, result);
		}
		cout << result << '\n';
		
	}


	return 0;

}