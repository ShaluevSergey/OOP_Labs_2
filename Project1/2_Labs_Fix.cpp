#include <iostream>
#include <string>
using namespace std;

class Pair
{
protected:

    int first, second; // Целые числа

public:
    Pair() // Конструктор по умолчанию
    {
        first = second = 0;
    };

    Pair(int first, int second) // Конструктор с параметрами
    {
        this->first = first;
        this->second = second;
    };

    Pair NumMultipl(int k) // Умножает пару чисел на коэффициент k
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
    Money() : Pair() // Конструктор по умолчанию, вызывающий конструктор базового класса
    {}

    Money(int rubles, int pennies) : Pair(rubles, pennies) // Конструктор с параметрами, вызывающий конструктор базового класса
    {}

    Money Addition(int rubles, int pennies)  // Переопределённый метод суммирования
    {
        Pair::Addition(rubles, pennies); // используем для сложения метод базового класса

        if (second >= 100) // корректируем результат с учетом денежной реализации, т.е. переводит копейки в рубли
        {
            int countRublInPennies = second / 100; // сколько целых рублей в копейках
            first += countRublInPennies; // переводим это количество в рубли
            second -= countRublInPennies * 100; // корректируем копейки
        }

        return *this;
    }

    Money Addition(const Money& othMoney)
    {
        return Addition(othMoney.first, othMoney.second);
    }

    Money Subtraction(const Money& othMoney) // Вычитание
    {
        if (othMoney.first > first || (othMoney.first == first && othMoney.second > second)) // предполагаем, что отрицательных денег быть не должно
            return *this;

        Pair::Addition(-othMoney.first, -othMoney.second);

        if (second < 0) { // если копейки получили отриц. значение, то переводит рубли в копейки
            int countRubl = second / 100 + 1;
            first -= countRubl;
            second += countRubl * 100;
        }

        return *this;
    }

    Money Division(int delet) // Деление
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


