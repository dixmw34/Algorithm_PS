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

string a;
int idx = 0;

int sol() {
	int num = 0;
	while (idx < a.size()) {
		if (a[idx] == '(' || a[idx] == '[') {
			idx++;
			num += sol();
		}
		else if (a[idx] == ')') {
			idx++;
			if (num == 0) return 2;
			else return num * 2;
		}
		else if (a[idx] == ']') {
			idx++;
			if (num == 0) return 3;
			else return num * 3;
		}
	}
	return num;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	
	cin >> a;
	stack<char>s;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '(' || a[i] == '[')s.push(a[i]);
		else if (a[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0 << '\n';
				return 0;
			}
			s.pop();
		}
		else if (a[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0 << '\n';
				return 0;
			}
			s.pop();
		}
	}
	if (!s.empty()) {
		cout << 0 << '\n';
		return 0;
	}

	cout << sol() << '\n';

	return 0;

}