# include<iostream>
using namespace std;

class Time {
public:
    int day;
    int month;
    int year;
};

int D1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int D2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    Time time;

    while (cin >> time.year >> time.month >> time.day) {
        bool valid = true;
        bool leap = false;
        if ((time.year % 4==0)&&(time.year%100!=0)) {
            leap = true;
        }
        if (time.month > 12 || time.month < 1) {
            valid = false;
        }
        if ( ((!leap && time.day > D1[time.month]) || (leap && time.day > D2[time.month]) || time.day < 1)) {
            valid = false;
        } 
        if (valid) {
            int ans = time.day;
            for (int i = 1; i < time.month; i++) {
                if (leap) {
                    ans += D2[i];
                }
                else {
                    ans += D1[i];
                }
            }
            cout << ans << endl;
        }
        else {
            cout << "Input error!" << endl;
        }


    }

    return 0;
}