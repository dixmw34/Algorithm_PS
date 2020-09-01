#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int x = 0, y = 0;
            if (j - 1 >= 0)x = triangle[i - 1][j - 1];
            if (j < triangle[i - 1].size())y = triangle[i - 1][j];
            triangle[i][j] += max(x, y);
            answer = max(answer, triangle[i][j]);
        }
    }

    return answer;
}