 #include <iostream>
 #include <functional>

 using namespace std;

int do_something(const int i)
{
    return 10 + i;
}

struct S{
    int j=5;
    int do_something(const int i)
    {
        return j + i;
    }

    int do_something_2(const int i)
    {
        return j * i;
    }

};

 int main()
 {
     cout << std::invoke(&do_something,10) << endl;
     S s;
     cout << s.do_something(7) << endl;

    auto fp = &S::do_something;
    int (S::*fp2)(int) = &S::do_something;

    cout << (s.*fp)(22) << endl;
    cout << (s.*fp2)(33) << endl;

    cout << invoke(&S::do_something,s,5) << endl;
    cout << invoke(&S::do_something_2,s,10) << endl;
    cout << invoke(&S::j,s) << endl;

     return 0;
 }