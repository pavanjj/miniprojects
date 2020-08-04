#include <iostream>
#include <string>
using namespace std;

void inline printLine(const string &printStr)
{
    cout << printStr << endl;
}
template <class T>
void inline readInput(const string &displayLine, T &var)
{
    printLine(displayLine);
    cin << var;
}