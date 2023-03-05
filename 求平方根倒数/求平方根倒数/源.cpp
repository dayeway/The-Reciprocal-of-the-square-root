#include <iostream>
using namespace std;

//在上世纪 90 年代，多数浮点数操作的速度更是远远滞后于整数操作。所以，这段代码所带来的作用是非常大的
//高效求平方根倒数
float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y; // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1);  // what the fuck? 
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));  // 1st iteration 
    // 2nd iteration, this can be removed
    // y  = y * ( threehalfs - ( x2 * y * y ) ); 

    return y;
}

int main()
{
    int a;
    while (cin >> a)
    {
        cout << "新算法结果：" << Q_rsqrt(a) << endl;
        cout << "常规结果：" << 1/sqrt(a) << endl;
    }
}
