#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    for (int i = 3; i < 2500; i++) {
        for (int j = 3; j <= i; j++) {
            int a = (i + j - 2) * 2;
            int b = (i - 2)*(j - 2);
            if (a == brown && b == yellow) {
                return { i, j };
            }
        }
    }
}

vector<int> solution2(int brown, int yellow) {

	brown = (brown / 2) + 2;
	int w, h;
	if (brown % 2) {
		w = brown / 2 + 1;
		h = brown / 2;
	}
	else {
		w = brown / 2;
		h = brown / 2;
	}

	while (h) {
		if ((w - 2)*(h - 2) == yellow)return { w, h };
		w++; h--;
	}
}