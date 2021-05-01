#include <iostream>

using namespace std;

template<int n>
class Factorial {
public:
    static const int f = Factorial<n - 1>::f * n;
};

template<>
class Factorial<0> {
public:
    static const int f = 1;
};

int getFactorial(int a) {
    if (a < 0) {
        cout << "Factorial of negative number is Undefined\t";
        return -1;
    }
    if (a == 0) {
        return 1;
    }
    return a * getFactorial(a - 1);
}

int nomain() {

    //Ёквивалентно написанию 120;
    cout << Factorial<5>::f << endl;

    //«начение будет высчитыватьс€
    cout << getFactorial(5) << endl;

    cin.get();
    return 0;
}