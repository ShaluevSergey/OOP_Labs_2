#include <iostream>
using namespace std;

class Pair
{
private:

	int first, second; // Целые числа

public:
	Pair()
	{
		first = second = 0;
	}; // Конструктор по умолчанию
	Pair(int first, int second) // Конструктор с параметрами
	{
		this->first = first;
		this->second = second;
	};
	~Pair() {}; // Деконструктор


	void NumMultipl(int k) // Умножает пару чисел на коэффициент k
	{
		first *= k;
		second *= k;
	}

	virtual void Addition(int x, int y)
	{
		first += x;
		second += y;
		cout << first << endl << second;
	}

};
class Money : public Pair
{
private:

	int rubles, pennies;

public:
	Money()
	{
		rubles = pennies = 0;
	}; // Конструктор по умолчанию
	Money(int rubles, int pennies) // Конструктор с параметрами
	{
		this->rubles = rubles;
		this->pennies = pennies;
	};
	~Money() {}; // Деконструктор

	virtual void Addition(int x, int y) override // Переопределённый метод суммирования с помощью виртуального метода
	{
		rubles += x;
		pennies += y;
		cout << rubles << endl << pennies;
	}
	 
	void Subtraction(int x, int y) // Вычитание
	{
		rubles -= x;
		pennies -= y;
	}
	void division(int x, int y) // Деление
	{
		rubles /= x;
		pennies /= y;
	}
};
int main()
{
	Pair A;
	Money B;
	int a = 2;
	int b = 4;




	A.Addition(a, b);
	A.Addition(1, 3);

	return 0;
}