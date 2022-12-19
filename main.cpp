#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;
};

Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration {h, m};
}

void PrintDuration(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':'
            << setw(2) << duration.min;
}

int main() {
    stringstream dur_ss("01:50");
    Duration dur1 = ReadDuration(dur_ss);
    PrintDuration(cout, dur1);
    cout << endl;
    return 0;
}