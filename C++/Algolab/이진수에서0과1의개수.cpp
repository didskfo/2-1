#include "iostream"

using namespace std;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    int dec;
    for (int i = 0; i < t; i++) {
        int zero = 0;
        int one = 0;
        cin >> dec;
        string bin_str = toBinary(dec);
        for (int j = 0; j < bin_str.length(); j++) {
            if (bin_str[j] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        cout << bin_str << " " << zero << " " << one << endl;
    }
    return 0;
}