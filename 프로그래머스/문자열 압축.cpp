#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int len(int num) {
    int l = 0;
    while (num) {
        num /= 10;
        l++;
    }
    return l;
}

int solution(string s) {
    int answer = s.size();
    int n = s.size();

    int num = 0;
    string a = "";

    for (int k = 1; k <= n / 2; k++) {
        num = 0; a = "";
        int test = 0;
        for (int i = 0; i < n; i += k) {
            if (a == s.substr(i, k))num++;
            else {
                a = s.substr(i, k);
                if (num > 1) {
                    test += len(num) + k;
                }
                else if (num)test += k;
                num = 1;
            }
        }
        if (num > 1) {
            test += len(num) + k;
        }
        else if (num) {
            int i = 0;
            for (; i < a.size(); i++)if (a[i] == ' ')break;
            test += i;
        }

        answer = min(answer, test);
    }
    return answer;
}

int solution2(string s) {
	int answer = s.size();
	int n = s.size();

	int num = 0;
	string a = "";

	for (int k = 1; k <= n / 2; k++) {
		num = 0; a = "";
		string test = "";
		for (int i = 0; i < n; i += k) {
			if (a == s.substr(i, k))num++;
			else {
				if (num > 1) {
					test += to_string(num) + a;
				}
				else if (num)test += a;
				a = s.substr(i, k);
				num = 1;
			}
		}
		if (num > 1) {
			test += to_string(num) + a;
		}
		else if (num) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != ' ')test += a[i];
			}
		}
		//cout << k << " : " << test << '\n';
		answer = min(answer, (int)test.size());
	}
	return answer;
}