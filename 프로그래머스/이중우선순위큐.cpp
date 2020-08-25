#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {

	deque<int>dq;

	for (int i = 0; i < operations.size(); i++) {
		if (operations[i] == "D 1") {
			if (!dq.empty())dq.pop_back();
		}
		else if (operations[i] == "D -1") {
			if (!dq.empty())dq.pop_front();
		}
		else {
			int num = atoi(operations[i].substr(2, operations[i].size() - 2).c_str());
			if (dq.empty() || dq.back() <= num)dq.push_back(num);
			else {
				deque<int>::iterator it = lower_bound(dq.begin(), dq.end(), num);
				dq.insert(it, num);
			}
		}
	}

	if (dq.empty())return { 0, 0 };
	else return { dq.back(), dq.front() };

}