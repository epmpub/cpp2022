#include <any>
#include <vector>
#include <string>
#include <iostream>
#include <type_traits>

using namespace std;


struct S {
    S(const S& s) = default;
    S() = default;
};

int main()
{
    vector<std::any> v{5,3.14,string("EHCO"),S()};

    // for(auto i:v){
    //     cout << i << endl;
    // }
    cout << sizeof(v) << endl;
    cout << any_cast<double>(v[1]) << endl;
    cout << any_cast<string>(v[2]) << endl;
    cout << v[1].type().name() << endl;

    static_assert(is_nothrow_constructible<S>::value, "no nothrow_constructible");

    int* p = any_cast<int>(&v[0]);
    *p = 20;
    cout << any_cast<int>(v[0]) << endl;
    return 0;
}  