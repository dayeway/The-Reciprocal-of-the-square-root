#include <iostream>
using namespace std;

//�������� 90 ����������������������ٶȸ���ԶԶ�ͺ����������������ԣ���δ����������������Ƿǳ���ġ�
//��Ч��ƽ��������
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
        cout << "���㷨�����" << Q_rsqrt(a) << endl;
        cout << "��������" << 1/sqrt(a) << endl;
    }
}