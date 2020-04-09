#include <iostream>
#include <string>
using namespace std;

class Pair
{
protected:

    int first, second; // ����� �����

public:
    Pair() // ����������� �� ���������
    {
        first = second = 0;
    };

    Pair(int first, int second) // ����������� � �����������
    {
        this->first = first;
        this->second = second;
    };

    Pair NumMultipl(int k) // �������� ���� ����� �� ����������� k
    {
        first *= k;
        second *= k;
        return *this;
    }

    Pair Addition(int rubles, int pennies)
    {
        first += rubles;
        second += pennies;
        return *this;
    }

};


class Money : public Pair
{
public:
    Money() : Pair() // ����������� �� ���������, ���������� ����������� �������� ������
    {}

    Money(int rubles, int pennies) : Pair(rubles, pennies) // ����������� � �����������, ���������� ����������� �������� ������
    {}

    Money Addition(int rubles, int pennies)  // ��������������� ����� ������������
    {
        Pair::Addition(rubles, pennies); // ���������� ��� �������� ����� �������� ������

        if (second >= 100) // ������������ ��������� � ������ �������� ����������, �.�. ��������� ������� � �����
        {
            int countRublInPennies = second / 100; // ������� ����� ������ � ��������
            first += countRublInPennies; // ��������� ��� ���������� � �����
            second -= countRublInPennies * 100; // ������������ �������
        }

        return *this;
    }

    Money Addition(const Money& othMoney)
    {
        return Addition(othMoney.first, othMoney.second);
    }

    Money Subtraction(const Money& othMoney) // ���������
    {
        if (othMoney.first > first || (othMoney.first == first && othMoney.second > second)) // ������������, ��� ������������� ����� ���� �� ������
            return *this;

        Pair::Addition(-othMoney.first, -othMoney.second);

        if (second < 0) { // ���� ������� �������� �����. ��������, �� ��������� ����� � �������
            int countRubl = second / 100 + 1;
            first -= countRubl;
            second += countRubl * 100;
        }

        return *this;
    }

    Money Division(int delet) // �������
    {
        this->first /= delet;
        this->second /= delet;
        return *this;
    }

    string toString()
    {
        return to_string(first) + " Rub, " + to_string(second) + " Cop";
    }
};


int main()
{
    Money A(10, 10);
    Money B(1, 99);

    cout << " = " << A.toString() << endl;

    A.Addition(B);

    cout << " + " + B.toString() + " = " << A.toString() << endl;

    A.Subtraction(B);

    cout << " - " + B.toString() + " = " << A.toString() << endl;

    A.Division(2);

    cout << " / 2 = " << A.toString() << endl;

    return 0;
}


