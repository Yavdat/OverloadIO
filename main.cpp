#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;
    Duration(int h=0, int m=0) {
        hour = h;
        min = m;
    }
};

// Duration ReadDuration(istream& stream) {
//     int h = 0;
//     int m = 0;
//     stream >> h;
//     stream.ignore(1);
//     stream >> m;
//     return Duration {h, m};
// }

// void PrintDuration(ostream& stream, const Duration& duration) {
//     stream << setfill('0');
//     stream << setw(2) << duration.hour << ':'
//             << setw(2) << duration.min;
// }

istream& operator>>(istream& stream, Duration& duration) {
    
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0'); 
    stream << setw(2) << duration.hour << ':'
           << setw(2) << duration.min;
    return stream;
}

int main() {
    stringstream dur_ss("01:50");
    // Duration dur1 = ReadDuration(dur_ss);
    Duration dur1;
    dur_ss >> dur1; // без этой строки выведется 00:00
    // PrintDuration(cout, dur1);
    // cout << dur1 << endl; // с endl не сработает, так требуется возвращать ссылку на поток в перегружаемом операторе
    // cout << "hello" << " world";
    operator<<(operator<<(cout, "hello"), " world\n"); // пример цепочного вызова перегруженного оператора <<

    // выведется 00:00 так как сработал конструктор по умолчанию
    cout << dur1 << endl; // теперь все норм
    cout << endl;
    stringstream dur_ss2("02:50");
    Duration dur2;
    dur_ss2 >> dur2;
    cout << dur2 << endl;
    
    return 0;
}