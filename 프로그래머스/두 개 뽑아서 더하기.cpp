#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    priority_queue<int>pq;
    int n = numbers.size();

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            pq.push(-numbers[i] - numbers[j]);
        }
    }

    while (!pq.empty()) {
        if (answer.empty() || answer[answer.size() - 1] != -pq.top())answer.push_back(-pq.top());
        pq.pop();
    }

    return answer;
}