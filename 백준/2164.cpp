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
	cin.tie(0); cout.tie(0);

	int i = 0, n;
	cin >> n;
	queue<int>q;
	for (int i = 1; i <= n; ++i)q.push(i);

	while (q.size() > 1) {
		if (i % 2 != 0)q.push(q.front());
		q.pop();
		i++;
	}

	cout << q.front() << '\n';

	
	return 0;

}