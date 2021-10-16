/*Николаева Е.С. М8О-201Б-20
Вариант 1: Комплексное число в алгебраической форме представляются парой действительных чисел (a, b), где a – действительная часть, b – мнимая часть. Реализовать класс Complex для работы с комплексными числами. Обязательно должны быть присутствовать операции
-         сложения add, (a, b) + (c, d) = (a + c, b + d);
-         вычитания sub, (a, b) – (c, d) = (a – c, b – d);
-         умножения mul, (a, b) ´ (c, d) = (ac – bd, ad + bc);
-         деления div, (a, b) / (c, d) = (ac + bd, bc – ad) / (c2 + d2);
-         сравнение equ, (a, b) = (c, d), если (a = c) и (b = d);
-         сопряженное число conj, conj(a, b) = (a, –b).
Реализовать операции сравнения модулей.
*/


#include <iostream>
#include <math.h>
#include <complex.h>
using namespace std;

class Complex { //объявление класса
	public:
		double A;
		double B;

		void setComp(double a, double b) { //задание параметров числа
			A = a;
			B = b;
	}
		void getComp() { //получение параметров числа
			cout << "(" << A << ", " << B << "*C)";
	}
};

Complex operator+ (Complex a, Complex b) { //перегрузка оператора сложения
	Complex c;
	c.A = a.A + b.A;
	c.B = a.B + b.B;
	return (c);
}

Complex operator- (Complex a, Complex b) { //перегрузка оператора вычитания
	Complex c;
	c.A = a.A - b.A;
	c.B = a.B - b.B;
	return(c);
}

Complex operator* (Complex a, Complex b) { //перегрузка оператора умножения
	Complex c;
	c.A = (a.A * b.A) - (a.B * b.B);
	c.B = (a.A * b.B) + (a.B * b.A);
	return(c);
}

Complex operator/ (Complex a, Complex b) { //перегрузка оператора деления
	Complex c;
	c.A = (a.A * b.A) + (a.B * b.B);
	c.B = (a.B * b.A) - (a.A * b.B);
	return(c);
}

bool operator== (Complex a, Complex b) { //перегрузка оператора сравнения
	if (a.A * a.B == b.A * b.B) {
		return (true);
	}
	else {
		return (false);
	}
}

bool operator> (Complex a, Complex b) { //перегрузка оператора сравнения по модулю
	if (abs(a.A * a.B) > abs(b.A * b.B)) {
		return (true);
	}
	else {
		return (false);
	}
}

bool operator< (Complex a, Complex b) { //перегрузка оператора сравнения по модулю
	if (abs(a.A * a.B) < abs(b.A * b.B)) {
		return (true);
	}
	else {
		return (false);
	}
}

Complex operator^ (Complex a, Complex b) {
	Complex c;
	c.A = a.A;
	c.B = -a.B;
	return(c);
}


int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	int fflag = 0;
	int sflag = 0;
	Complex First;
	Complex Second;
	Complex Third;
	int c = 0;
	while (c != 10) {
		cout << "\n---\n1.Параметры первого числа \n2.Параметры второго числа \n3.Сложение чисел \n4.Вычитание чисел \n5.Умножение чисел \n6.Деление чисел \n7.Равенство чисел \n8.Сравнение чисел по модулю  \n9.Сопряженное число \n10.Выход \n---";
		cout << "\nВведите команду";
		cin >> c;
		switch (c) {
		case 1:
			cout << "\nЗадайте параметры первого числа:";
			cin >> a >> b;
			First.setComp(a, b);
			fflag = 1;
			break;
		case 2:
			cout << "\nЗадайте параметры второго числа: ";
			cin >> a >> b;
			Second.setComp(a, b);
			sflag = 1;
			break;
		case 3:
			if (fflag == 1 && sflag == 1) { //проверка непустоты параметров чисел
				Third = First + Second;
				Third.getComp();
			}
			else {
				if (fflag != 1) {
					cout << "\nПараметры первого числа не заданы";
				}
				if (sflag != 1) {
					cout << "\nПараметры второго числа не заданы";
				}
			}
			break;
		case 4:
			if (fflag == 1 && sflag == 1) { //проверка непустоты параметров чисел
				Third = First - Second;
				Third.getComp();
			}
			else {
				if (fflag != 1) {
					cout << "\nПараметры первого числа не заданы";
				}
				if (sflag != 1) {
					cout << "\nПараметры второго числа не заданы";
				}
			}
			break;
		case 5:
			if (fflag == 1 && sflag == 1) { //проверка непустоты параметров чисел
				Third = First * Second;
				Third.getComp();
			}
			else {
				if (fflag != 1) {
					cout << "\nПараметры первого числа не заданы";
				}
				if (sflag != 1) {
					cout << "\nПараметры второго числа не заданы";
				}
			}
			break;
		case 6:
			if (fflag == 1 && sflag == 1) { //проверка непустоты параметров чисел
				Third = First / Second;
				Third.getComp();
			}
			else {
				if (fflag != 1) {
					cout << "\nПараметры первого числа не заданы";
				}
				if (sflag != 1) {
					cout << "\nПараметры второго числа не заданы";
				}
			}
			break;
		case 7:
			if (fflag == 1 && sflag == 1) { //проверка непустоты параметров чисел
				if (First == Second) {
					cout << "Числа равны";
				}
				else
					cout << "Числа не равны";
			}
			else {
				if (fflag != 1) {
					cout << "\nПараметры первого числа не заданы";
				}
				if (sflag != 1) {
					cout << "\nПараметры второго числа не заданы";
				}
			}
			break;
		case 8:
			if (fflag == 1 && sflag == 1) { //проверка непустоты параметров чисел
				if (First > Second) {
					cout << "Первое число по модулю больше";
				}
				else
					if (First < Second) {
						cout << "Второе число по модулю больше";
					}
					else {
						if (fflag != 1) {
							cout << "\nПараметры первого числа не заданы";
						}
						if (sflag != 1) {
							cout << "\nПараметры второго числа не заданы";
						}
					}
				break;
		case 9:
			if (fflag == 1 && sflag == 1) {
				Third = First^Second;
				Third.getComp();
			}
			else {
				if (fflag != 1) {
					cout << "\nПараметры первого числа не заданы";
				}
				if (sflag != 1) {
					cout << "\nПараметры второго числа не заданы";
				}
			}
		case 10:
			break;
		default:
			cout << "Неверная команда\n";
			}
		}
	}
	return 0;
}