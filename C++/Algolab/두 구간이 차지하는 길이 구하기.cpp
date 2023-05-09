#include "iostream"

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    for (int q = 0; q < n; q++) {
        cin >> a >> b >> c >> d;
        if (b <= c) {
            cout << 0 << " " << b-a + d-c << endl;
        } else if (c <= a && d >= b) {
            cout << b-a << " " << d-c << endl;
        } else if (d <= a){
            cout << 0 << " " << b-a + d-c << endl;
        } else if (c >= a && d <= b) {
            cout << d-c << " " << b-a << endl;
        } else if (c >= a && c <= b && d >= b) {
            cout << b-c << " " << d-a << endl;
        } else {
            cout << d-a << " " << b-c << endl;
        }
    }
    return 0;
}