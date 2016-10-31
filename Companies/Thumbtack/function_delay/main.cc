#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;

void print(string line) {
    cout << line << endl;
    return;
}

void FunctionDelay(std::function<void(string)> f, unsigned long ms) {
    usleep(ms); // 1 ms = 10^-6 s
    f("hello");
    return;
}

int main()
{
    FunctionDelay(print, 1000000);
    return 0;
}
