#include "iostream"

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    int score;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int f = 0;
        for (int j = 0; j < n; j++) {
            cin >> score;
            if (score >= 90) {
                a++;
            } else if (score >= 80) {
                b++;
            } else if (score >= 70) {
                c++;
            } else if (score >= 60) {
                d++;
            } else {
                f++;
            }
        }
        cout << a << " " << b << " " << c << " " << d << " " << f << endl;
    }
    return 0;
}