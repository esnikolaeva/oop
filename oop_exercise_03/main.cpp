/*Николаева Е.С. М8О-201Б-20
Вариант 5: Ромб, 5-угольник, 6-угольник*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Figure {
public:
    struct point {
        double x, y;
    };
    double S;
    point center;
    point read_point() {
        point p;
        while (true) {
            cin >> p.x >> p.y;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Координаты введены неверно. Попробуйте снова" << endl;
            }
            else {
                cin.ignore(32767, '\n');
                return p;
            }
        }
    }
    virtual void read() = 0;
    virtual double square() = 0;
    virtual void print_square() = 0;
    virtual void coordinates_center() = 0;
    virtual void print() = 0;
};

class Hexagon : public Figure {
private:
    int i;
public:
    point a, b, c, d, e, f;
    void read() {
        cout << "Ввод шестиугольника" << endl;
        cout << "    b---------c" << endl;
        cout << "   /           \\" << endl;
        cout << "  /             \\" << endl;
        cout << " /               \\" << endl;
        cout << "a                  d" << endl;
        cout << "\\                /" << endl;
        cout << " \\              /" << endl;
        cout << "  \\            /" << endl;
        cout << "    f----------e" << endl;
        while (true) {
            cout << "Введите координаты точки a" << endl;
            a = read_point();
            cout << "Введите координаты точки b" << endl;
            b = read_point();
            cout << "Введите координаты точки c" << endl;
            c = read_point();
            cout << "Введите координаты точки d" << endl;
            d = read_point();
            cout << "Введите координаты точки e" << endl;
            e = read_point();
            cout << "Введите координаты точки f" << endl;
            f = read_point();

            if (!((b.x < c.x) && (b.y == c.y) && (c.x < d.x) && (c.y > d.y) && (d.x > e.x) && (d.y > e.y) && (e.x > f.x) && (e.y == f.y) && (f.x > a.x) && (f.y < a.y) && (a.x < b.x) && (a.y < b.y))) {
                cout << "Координаты введены неверно." << endl;
                while (true) {
                    cout << "Попробовать снова?" << endl << "1. Да" << endl << "2. Нет" << endl;
                    cin >> i;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << "Неверный ввод" << endl;
                    }
                    else {
                        cin.ignore(32767, '\n');
                        break;
                    }
                }
                if (i == 2) return;
            }
            else
                return;
        }
    }
    double square() {
        S = (6 * (e.x - f.x) * sqrt(3)) / 4;
        return S;
    }
    void print_square() {
        cout << "Площадь шестиугольника равна " << square() << endl;
        return;
    }
    void coordinates_center() {
        center.x = (e.x - f.x) / 2;
        center.y = (b.y - f.y) / 2;
        cout << "Координаты центра шестиугольника: " << center.x << "   " << center.y << endl;
        return;
    }
    void print() {
        cout << "Вывод фигуры шестиугольник вида:" << endl;
        cout << "    b---------c" << endl;
        cout << "   /           \\" << endl;
        cout << "  /             \\" << endl;
        cout << " /               \\" << endl;
        cout << "a                  d" << endl;
        cout << "\\                /" << endl;
        cout << " \\              /" << endl;
        cout << "  \\            /" << endl;
        cout << "    f----------e" << endl;
        cout << "Координаты точки a: " << a.x << "   " << a.y << endl;
        cout << "Координаты точки b: " << b.x << "   " << b.y << endl;
        cout << "Координаты точки c: " << c.x << "   " << c.y << endl;
        cout << "Координаты точки d: " << d.x << "   " << d.y << endl;
        cout << "Координаты точки e: " << e.x << "   " << e.y << endl;
        cout << "Координаты точки f: " << f.x << "   " << f.y << endl;
        return;
    }
};

class Rhomb : public Figure {
private:
    int i;
public:
    point a, b, c, d;
    void read() {
        cout << "Ввод ромба" << endl;
        cout << "    d--------c" << endl;
        cout << "   /        /" << endl;
        cout << "  /        /" << endl;
        cout << " /        /" << endl;
        cout << "a--------b" << endl;
        while (true) {
            cout << "Введите координаты точки a" << endl;
            a = read_point();
            cout << "Введите координаты точки b" << endl;
            b = read_point();
            cout << "Введите координаты точки c" << endl;
            c = read_point();
            cout << "Введите координаты точки d" << endl;
            d = read_point();
            if (!((a.x < b.x) && (d.x < c.x) && (d.y == c.y) && (a.y == b.y) && (c.y > a.y))) {
                cout << "Координаты введены неверно." << endl;
                while (true) {
                    cout << "Попробовать снова?" << endl << "1. Да" << endl << "2. Нет" << endl;
                    cin >> i;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << "Неверный ввод" << endl;
                    }
                    else {
                        cin.ignore(32767, '\n');
                        break;
                    }
                }
                if (i == 2) return;
            }
            else
                return;
        }
    }
    double square() {
        S = (sqrt((d.y - b.y) * (d.y - b.y) + (b.x - d.x) * (b.x - d.x))) * (sqrt((d.y - b.y) * (d.y - b.y) + (c.x - a.x) * (c.x - a.x))) / 2;
        return S;
    }
    void print_square() {
        cout << "Площадь ромба равна " << square() << endl;
        return;
    }
    void coordinates_center() {
        center.x = (a.x + b.x + c.x + d.x) / 4;
        center.y = (a.y + b.y + c.y + d.y) / 4;
        cout << "Координаты центра ромба: " << center.x << "   " << center.y << endl;
        return;
    }
    void print() {
        cout << "Вывод фигуры ромб вида:" << endl;
        cout << "    d--------c" << endl;
        cout << "   /        /" << endl;
        cout << "  /        /" << endl;
        cout << " /        /" << endl;
        cout << "a--------b" << endl;
        cout << "Координаты точки a: " << a.x << "   " << a.y << endl;
        cout << "Координаты точки b: " << b.x << "   " << b.y << endl;
        cout << "Координаты точки c: " << c.x << "   " << c.y << endl;
        cout << "Координаты точки d: " << d.x << "   " << d.y << endl;
        return;
    }
};

class Pentagon :public Figure {
private:
    int i;
public:
    point a, b, c, d, e;
    void read() {
        cout << "Ввод пятиугольника" << endl;
        cout << "     d" << endl;
        cout << "    / \\ " << endl;
        cout << "   /   \\ " << endl;
        cout << "  /     \\ " << endl;
        cout << " /       \\ " << endl;
        cout << "e         c" << endl;
        cout << " \\       / " << endl;
        cout << "  a-----b  " << endl;
        while (true) {
            cout << "Введите координаты точки a" << endl;
            a = read_point();
            cout << "Введите координаты точки b" << endl;
            b = read_point();
            cout << "Введите координаты точки c" << endl;
            c = read_point();
            cout << "Введите координаты точки d" << endl;
            d = read_point();
            cout << "Введите координаты точки e" << endl;
            e = read_point();
            if (!((a.y == b.y) && (e.x < a.x) && (e.x < b.x) && (e.x < c.x) && (e.x < d.x) && (a.x - b.x) && (c.x > a.x) && (c.x > b.x) && (c.x > e.x) && (c.x > d.x) && (c.y > b.y) && (d.y > c.y) && (d.y > e.y) && (e.y > a.y))) {
                cout << "Координаты введены неверно." << endl;
                while (true) {
                    cout << "Попробовать снова?" << endl << "1. Да" << endl << "2. Нет" << endl;
                    cin >> i;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << "Неверный ввод" << endl;
                    }
                    else {
                        cin.ignore(32767, '\n');
                        break;
                    }
                }
                if (i == 2) return;
            }
            else
                return;
        }
    }
    double square() {
        S = (c.x - e.x) * (d.y - a.y) - (d.x - e.x) * (d.y - e.y) / 2 - (c.x - d.x) * (d.y - c.y) / 2 - (c.x - b.x) * (c.y - b.y) / 2 - (a.x - e.x) * (e.y - a.y) / 2;
        return S;
    }
    void print_square() {
        cout << "Площадь пятиугольника равна " << square() << endl;
        return;
    }
    void coordinates_center() {
        center.x = (a.x + b.x + c.x + d.x + e.x) / 5;
        center.y = (a.y + b.y + c.y + d.y + e.y) / 5;
        cout << "Координаты центра пятиугольника: " << center.x << "   " << center.y << endl;
        return;
    }
    void print() {
        cout << "Вывод фигуры пятиугольник вида:" << endl;
        cout << "     d" << endl;
        cout << "    / \\ " << endl;
        cout << "   /   \\ " << endl;
        cout << "  /     \\ " << endl;
        cout << " /       \\ " << endl;
        cout << "e         c" << endl;
        cout << " \\       / " << endl;
        cout << "  a-----b  " << endl;
        cout << "Координаты точки a: " << a.x << "   " << a.y << endl;
        cout << "Координаты точки b: " << b.x << "   " << b.y << endl;
        cout << "Координаты точки c: " << c.x << "   " << c.y << endl;
        cout << "Координаты точки d: " << d.x << "   " << d.y << endl;
        cout << "Координаты точки e: " << e.x << "   " << e.y << endl;
        return;
    }
};

int prov() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Неверный ввод" << endl;
        return 0;
    }
    else {
        cin.ignore(32767, '\n');
        return 1;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int k, n;
    double Si, sum = 0;
    vector <Figure*> fig;
    while (true) {
        cout << "1. Ввести фигуру" << endl << "2. Вывести координаты точек фигуры" << endl << "3. Вывести площадь фигуры" << endl << "4. Вывести центр фигуры" << endl << "5. Вывести общую площадь" << endl << "6. Удалить фигуру из массива" << endl << "0. Выход" << endl;
        cin >> k;
        if (prov()) {
            if (k == 1) {
                cout << "Введите фигуру:" << endl << "1. Шестиугольник" << endl << "2. Ромб" << endl << "3. Пятиугольник" << endl;
                cin >> n;
                if (prov()) {
                    if (n == 1) {
                        Hexagon* f = new Hexagon();
                        f->read();
                        fig.push_back(f);
                    }
                    if (n == 2) {
                        Rhomb* f = new Rhomb();
                        f->read();
                        fig.push_back(f);
                    }
                    if (n == 3) {
                        Pentagon* f = new Pentagon();
                        f->read();
                        fig.push_back(f);
                    }
                }
            }
            if (k == 2) {
                for (int i = 0; i < fig.size(); i++) {
                    cout << "Фигура " << i << endl;
                    fig[i]->print();
                }
            }
            if (k == 3) {
                for (int i = 0; i < fig.size(); i++) {
                    cout << "Фигура " << i << endl;
                    fig[i]->print_square();
                }
            }
            if (k == 4) {
                for (int i = 0; i < fig.size(); i++) {
                    cout << "Фигура " << i << endl;
                    fig[i]->coordinates_center();
                }
            }
            if (k == 5) {
                for (int i = 0; i < fig.size(); i++)
                    sum += fig[i]->square();
                cout << "Общая площадь равна " << sum << endl;
            }
            if (k == 6) {
                cout << "Введите номер удаляемого элемента" << endl;
                cin >> n;
                if (prov()) {
                    if ((n > fig.size()) || (n <= 0))
                        cout << "Данного элемента не существует" << endl;
                    else {
                        delete fig[n - 1];
                        fig.erase(fig.begin() + n - 1);
                    }
                }
            }
            if (k == 0) {
                for (int i = 0; i < fig.size(); i++)
                    delete fig[i];
                break;
            }
        }
    }
};
