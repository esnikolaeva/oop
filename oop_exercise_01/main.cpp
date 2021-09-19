#include <iostream>

class Modulo {
	int X;
	int N;

public:
	Modulo() = default;

	Modulo(int x, int n)
	{
		if (n == 0)
			std::cout << "Ошибка, деление на 0" << '\n';
		else
		{
			X = x % n; N = n;
		}
	}

	Modulo vv(Modulo z) {
		std::cout << "Число по модулю:" << z.X << '\n' << "Модуль:" << z.N << '\n';
		return z;
	}
	Modulo s(Modulo z, int a) {
		z.X = (z.X + a) % z.N;
		return z;
	}
	Modulo a(Modulo z, int q) {
		z.X = (z.X - q) % z.N;
		return z;
	}
	Modulo p(Modulo z, int k) {
		z.X = (z.X * k) % z.N;
		return z;
	}
	Modulo d(Modulo z, int c) {
		z.X = (z.X / c) % z.N;
		return z;
	}
	Modulo sr(Modulo z, int o) {
		z.X = z.X % z.N;

		if (z.X < o)
			std::cout << z.X << " " << "Меньше" << " " << o << '\n';
		if (z.X > o)
			std::cout << z.X << " " << "Больше" << " " << o << '\n';
		if (z.X == o)
			std::cout << z.X << " " << "Равно" << " " << o << '\n';
		return z;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	Modulo f;
	while (1)
	{
		std::cout << "1. Введите число и его модуль" << "\n" << "2. Напечатать число по модулю и значение модуля" << "\n" << "3. Сумма модуля и числа" << "\n" << "4. Разность модуля и числа" << "\n" << "5. Умножение модуля на число"
			<< "\n" << "6. Деление модуля на число" << "\n" << "7. Сравнение модуля и числа" << "\n" << "8. Выход" << "\n";
		std::cin >> i;
		if (i == 1) {
			int c, d;
			std::cin >> c >> d;
			Modulo m(c, d);
			f = m;
		}
		if (i == 2) {
			f.vv(f);
		}
		if (i == 3) {
			int t;
			std::cout << "Введите число, с которым складываем:" << '\n';
			std::cin >> t;
			f.vv(f.s(f, t));
		}
		if (i == 4) {
			int b;
			std::cout << "Введите число, которое вычитаем" << '\n';
			std::cin >> b;
			f.vv(f.a(f, b));
		}
		if (i == 5) {
			int y;
			std::cout << "Введите число, на которое умножаем" << '\n';
			std::cin >> y;
			f.vv(f.p(f, y));
		}
		if (i == 6) {
			int h;
			std::cout << "Введите число, на которое делим" << '\n';
			std::cin >> h;
			f.vv(f.d(f, h));
		}
		if (i == 7) {
			int g;
			std::cout << "Введите число, с которым сравниваем" << '\n';
			std::cin >> g;
			f.sr(f, g);
		}
		if (i == 8) {
			break;
		}
	}
	return 0;
}