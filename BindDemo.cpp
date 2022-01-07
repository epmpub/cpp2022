#include <iostream>
#include <functional>
#include <string>
#include <cstdio>

using namespace std;
template<typename T>
void print(const T i, const std::string& s)
{
    std::cout << i << ' ' << s << "\n";
}
int main()
{
    int i = 5;
    const auto f = std::bind(&print<int>, std::placeholders::_1,std::placeholders::_2);
    f(i, "HEllO");
    i = 6;
    f(i, "WORLD");

    std::function<void(int, const std::string&)>f2(f);
    f2(10, "test");

    return 0; 
}
