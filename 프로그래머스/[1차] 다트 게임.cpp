#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<int>score(3, 0);
    int k = 0;

    for (int i = 0; i < 3; i++) {
        score[i] += s[k++] - '0';
        if (s[k - 1] == '1' && s[k] == '0') {
            k++;
            score[i] = 10;
        }
        if (s[k] == 'D') {
            score[i] = score[i] * score[i];
        }
        else if (s[k] == 'T') {
            score[i] = score[i] * score[i] * score[i];
        }
        k++;
        if (k < s.size() && (s[k] == '*' || s[k] == '#')) {
            if (s[k] == '*') {
                score[i] *= 2;
                if (i != 0) {
                    score[i - 1] *= 2;
                }
            }
            else {
                score[i] = -score[i];
            }
            k++;
        }
    }

    return score[0]+score[1]+score[2];
}