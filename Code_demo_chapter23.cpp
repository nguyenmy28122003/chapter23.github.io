#include <iostream>
#include <float.h>

#pragma fenv_access(on)

using namespace std;

int main(int argc, char* argv[])
{
    float a = 1.75f, b = 1e-6f;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);

    cout << "a = " << a << ", b = " << b << endl;

    _controlfp_s(NULL, _RC_DOWN, _MCW_RC);

    cout << "Result of a + b rounded down: " << a + b << endl;
    cout << "Result of a - b rounded down: " << a - b << endl;

    _controlfp_s(NULL, _RC_UP, _MCW_RC);
    cout << "Result of a + b rounded up: " << a + b << endl;
    cout << "Result of a - b rounded up: " << a - b << endl;

    _controlfp_s(NULL, _RC_NEAR, _MCW_RC);
    cout << "Result of a + b rounded to nearest: " << a + b << endl;
    cout << "Result of a - b rounded to nearest: " << a - b << endl;

    return 0;
}