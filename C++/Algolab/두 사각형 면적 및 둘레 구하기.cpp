#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    int n;
    int a, b, c, d, e, f, g, h;
    int s, l;
    cin >> n;
    for (int q = 0; q < n; q++) {
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        if (c <= e || g <= a || b >= h || d <= f) {             // 안겹칠 때
            s = (c-a)*(d-b) + (g-e)*(h-f);
            l = (c-a+d-b)*2 + (g-e+h-f)*2;
        } else {
            if (g <= c && e >= a && d >= h && e >= b) {         // 포함될 때 1
                s = (c-a)*(d-b);
                l = (c-a+d-b)*2;
            } else if (a >= e && g >= c && f <= b && h >= d) {  // 포함될 때 2
                s = (g-e)*(h-f);
                l = (g-e+h-f)*2;
            } else {                                            // 겹칠 때 정렬해서 풀었다.
                int x[4] = {a, c, e, g};
                int y[4] =  {b, d, f, h};
                sort(x, x+4);
                sort(y, y+4);
                s = (c-a)*(d-b) + (g-e)*(h-f) - (x[2]-x[1])*(y[2]-y[1]);
                l = (c-a+d-b)*2 + (g-e+h-f)*2 - (x[2]-x[1]+y[2]-y[1])*2;
            }
        }
        cout << s << " " << l << endl;
    }
    return 0;
}