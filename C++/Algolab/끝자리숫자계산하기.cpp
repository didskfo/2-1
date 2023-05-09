#include "iostream"

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    int a;
    int num;
    for (int i = 0; i < t; i++) {
        cin >> n;
        num = 1;
        for (int j = 0; j < n; j++) {
            cin >> a;
            num *= a%10;
            num = num%10;
        }
        cout << num%10 << "\n";
    }
    return 0;
}