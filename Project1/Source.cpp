#include <iostream>
using namespace std;

class Pair
{
private:

	int first, second; // ����� �����

public:
	Pair() { first = second = 0 }; // ����������� �� ���������
	Pair(int first, int second) // ����������� � �����������
	{
		this->first = first;
		this->second = second;
	};
	~Pair() {}; // �������������


	void NumMultipl(int k) // �������� ���� ����� �� ����������� k
	{
		first *= k;
		second *= k;
	}

	virtual void Addition(int x, int y) // � �������� �� �������������� ����� ����� ������� addition (�� ���� ����� ����� ���� ��������� Pair (��� � & , ��� � ��� *���� ����*) )
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
	Money() { rubles = pennies = 0 }; // ����������� �� ���������
	Money(int rubles, int pennies) // ����������� � �����������
	{
		this->rubles = rubles;
		this->pennies = pennies;
	};
	~Money() {}; // �������������

	virtual void Addition(int x, int y) override // ��������������� ����� ������������
	{
		rubles += x;
		pennies += y;
	}

	void Subtraction(int x, int y) // ���������
	{
		rubles -= x;
		pennies -= y;
	}
	void division(int x, int y) // �������
	{
		rubles /= x;
		pennies /= y;
	}
};
int main()
{
	return 0;
}