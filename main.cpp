#include <iostream>
#include "build/config.h"
using namespace std;

#ifdef USER_COMMON
#include "common/common.hpp"
#endif

int main()
{
    string y;
    cout << V1 << endl;
    cout << V2 << endl;
    cin >> y;
#ifdef USER_COMMON
    printlog(y);
#else
    cout << "not common lib" << endl;
#endif
    return 0;
}