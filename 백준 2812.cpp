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

	int N, K;
	string s;
	deque<char>dq;
	
	cin >> N >> K >> s;

	for (int i = 0; i < N; i++) {
		while (!dq.empty() && dq.back() < s[i] && K) {
			dq.pop_back();
			K--;
		}
		dq.push_back(s[i]);
	}
	while (K) {
		dq.pop_back();
		K--;
	}
	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}
	cout << '\n';




	return 0;


}