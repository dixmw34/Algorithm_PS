#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>arr = { { 1, 2, 3, 4, 5}, { 2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };

vector<int> solution(vector<int> answers) {
    vector<int> ans;

    vector<int>p(3, 0);

    int mx = 0;

    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (answers[i] == arr[j][i%arr[j].size()])p[j]++;
        }
    }
    for (int j = 0; j < 3; j++) {
        mx = max(mx, p[j]);
    }

    for (int j = 0; j < 3; j++) {
        if (mx == p[j])ans.push_back(j + 1);
    }


    return ans;
}