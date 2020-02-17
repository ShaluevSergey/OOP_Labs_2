#include <iostream>
using namespace std;

class Pair
{
private:

	int first, second; // Целые числа

public:
	Pair() { first = second = 0 }; // Конструктор по умолчанию
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

	virtual void Addition(int x, int y) // В условиях не прослеживается явный смысл функции addition (На вход также может идти экземпляр Pair (как с & , так и без *если надо*) )
	{
		first += x;
		second += y;
	}

};
class Money : public Pair
{
private:

	int rubles, pennies;

public:
	Money() { rubles = pennies = 0 }; // Конструктор по умолчанию
	Money(int rubles, int pennies) // Конструктор с параметрами
	{
		this->rubles = rubles;
		this->pennies = pennies;
	};
	~Money() {}; // Деконструктор

	virtual void Addition(int x, int y) override // Переопределённый метод суммирования
	{
		rubles += x;
		pennies += y;
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
	return 0;
}