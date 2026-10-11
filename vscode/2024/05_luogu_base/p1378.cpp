#include <iostream>
#include <cmath>
using namespace std;

struct Time {
    long long Year;
    long long Month;
    long long Day;
    long long Hour;
    long long Min;
    long long Sec;
}Time;

long long T, Long;
int Mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void check() {
    if ((Time.Year % 4 == 0 && Time.Year % 100 != 0) || Time.Year % 400 == 0) Mth[2] = 29;
    else Mth[2] = 28;
}

int main() {
    long long n; cin >> n;
    while (n--) {
        cin >> Long >> Time.Year >> Time.Month >> Time.Day >> Time.Hour >> Time.Min >> Time.Sec;
        Long = pow(2, Long - 1) - 1;
        Time.Sec += Long;
        Time.Min += Time.Sec / 60; Time.Sec %= 60;
        Time.Hour += Time.Min / 60; Time.Min %= 60;
        Time.Day += Time.Hour / 24; Time.Hour %= 24;
        if (Time.Month == 2) check();
        while (Time.Day > Mth[Time.Month]) {
            Time.Day -= Mth[Time.Month];
            Time.Month++;
            if (Time.Month > 12) {
                Time.Month = 1;
                Time.Year++;
            }
            if (Time.Month == 2) check();
        }

        cout << Time.Year << " " << Time.Month << " " << Time.Day << " " << Time.Hour 
            << " " << Time.Min << " " << Time.Sec << endl;
    }
    return 0;
}