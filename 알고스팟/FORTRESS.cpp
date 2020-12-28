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

struct Node
{
	int x;
	int y;
	int r;
	vector<Node*>child;
};

bool isinclude(Node* a, Node* b) {
	return (a->r>b->r) && (pow(a->r - b->r, 2) > pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

struct Tree
{
	Node* root = NULL;
};

Node* insert_node(Node* par, Node* new_node) {
	if (par == NULL) {
		par = new_node;
		return par;
	}
	for (int i = 0; i < par->child.size(); ++i) {
		Node* child = par->child[i];
		if (isinclude(child, new_node)) {
			insert_node(child, new_node);
			return par;
		}
	}
	
	for (int i = 0; i < par->child.size(); ++i) {
		Node* child = par->child[i];
		if (isinclude(new_node, child)) {
			new_node->child.push_back(child);
			par->child.erase(par->child.begin() + i);
			i--;
		}
	}
	par->child.push_back(new_node);
	return par;
}

int ans = 0;

int sol(Node* now) {
	priority_queue<int>pq;
	for (int i = 0; i < now->child.size(); ++i) {
		pq.push(sol(now->child[i]));
	}
	if (pq.size() == 0) {
		ans = max(ans, 0);
		return 1;
	}
	else if (pq.size() == 1) {
		ans = max(ans, pq.top());
		return pq.top() + 1;
	}
	else {
		int num = pq.top(); pq.pop();
		ans = max(ans, num + pq.top());
		return num + 1;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		Tree mytree;
		int n, x, y, r;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y >> r;
			mytree.root = insert_node(mytree.root, new Node{ x, y, r });
		}
		ans = 0;
		sol(mytree.root);
		cout << ans << '\n';
	}

	

	return 0;
}