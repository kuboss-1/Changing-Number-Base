#include <iostream>
using namespace std;

void to_ten_base(int given_base, int num, int *result)
{
    int remainder, division, multiplication = 1;

    while(num != 0)
    {
        remainder = num %10;
        *result += remainder * multiplication;
        division = num/10;
        num = division;
        multiplication *= given_base;
    }
}

void to_another_base_from_ten(int wanted_base, int num, int *result)
{
    int remainder, division, multiplication = 1;
    *result = 0;
    while(num != 0)
    {
        remainder = num % wanted_base;
        *result += multiplication*remainder;
        division = num/wanted_base;
        num = division;
        multiplication *=10;
    }


}

void change_base(int num_base, int num, int wanted_base, int *result)
{
    int ten;
    to_ten_base(num_base, num, &ten);
    to_another_base_from_ten(wanted_base, ten, result);

}

int main()
{
    int num, wanted_base, given_base, num_base,result;

    cout << "Please enter your number: ";
    cin >> num;
    cout << "What is the base of this number? ";
    cin >> num_base;
    cout << "Which base do you want to choose? ";
    cin >> wanted_base;
    change_base(num_base, num, wanted_base, &result);
    cout << result;


    return 0;
}
