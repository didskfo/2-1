#include "iostream"
#include "string"

using namespace std;

int main() {
    int t;
    string num;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> num;
        int number = 1;
        while (num.length() > 1) {
            for (int j = 0; j < num.length(); j++) {
                if (num[j] != '0') {
                    number *= num[j] - '0';
                }
            }
            num = to_string(number);
            number = 1;
        }
        cout << num << endl;
    }
    return 0;
}