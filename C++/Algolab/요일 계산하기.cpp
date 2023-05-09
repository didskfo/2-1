#include "iostream"

using namespace std;

int main() {
    int t;
    cin >> t;
    int y, m, d;
    int cnt;
    bool yoon;
    int yoon_day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nyoon_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (t--) {
        cin >> y >> m >> d;
        cnt = 0;
        yoon = false;
        for (int i = 1582; i < y; i++) {
            if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0))) {
                cnt += 366;
            } else {
                cnt += 365;
            }
        }
        if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) {
            yoon = true;
        }
        if (yoon) {
            for (int i = 0; i < m; i++) {
                cnt += yoon_day[i];
            }
            cnt += d;
        } else {
            for (int i = 0; i < m; i++) {
                cnt += nyoon_day[i];
            }
            cnt += d;
        }
        cout << (cnt-3) % 7 << "\n";
    }
    return 0;
}