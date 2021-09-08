#include <iostream>
using namespace std;
class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        return;
    }
    void add(fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = numerator * f2.denominator;
        int y = f2.numerator * denominator;
        numerator = x + y;
        denominator = lcm;
        simplify();
    }
    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};
int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);
    f1.add(f2);
    f1.print();
    f2.print();
}