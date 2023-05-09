#include "iostream"
#include "string"

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    string num;
    int a;
    for (int q = 0; q < n; q++) {
        cin >> k;
        num = "";
        a = 0;
        while (num.length() < k) {
            num += to_string(++a);
        }
        cout << num[k-1] << endl;
    }
    return 0;
}