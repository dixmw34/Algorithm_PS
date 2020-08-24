#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0], end = commands[i][1], idx = commands[i][2];
        vector<int>a = array;
        sort(a.begin() + start - 1, a.begin() + end);
        answer.push_back(a[start + idx-2]);
    }

    return answer;
}
