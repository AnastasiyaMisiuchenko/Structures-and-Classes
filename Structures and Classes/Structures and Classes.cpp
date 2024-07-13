#include <iostream>
using namespace std;
#include <windows.h>
#include <cmath>
#include <math.h>

/* Задача 1: Управление студентами
Создайте структуру для хранения информации о студентах. Структура должна включать следующие поля:
 • Имя (строка)
 • Фамилия (строка)
 • Номер зачетной книжки (целое число)
 • Оценки (массив целых чисел)
Реализуйте следующие функции:
 1 Функция для создания нового студента.
 2 Функция для добавления оценки студенту.
 3 Функция для вычисления среднего балла студента.
 4 Функция для вывода информации о студенте. */
struct Students {
    
    std::string name;
    std::string surname;
    int recbook;
    int assessment[10];

};
void NewStudent(Students &novyi) {
   
    cout << "Введите имя: ";
    cin >> novyi.name;
    cout << "Введите фамилию: ";
    cin >> novyi.surname;
    cout << "Введите номер зачетной книжки: ";
    cin >> novyi.recbook;

}
double AssessmentStudent(Students &novyi) {

    cout << "Введите оценки: ";
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> novyi.assessment[i];
        sum += novyi.assessment[i];
    }
    return sum;
}
double GPA(double sum) {
    
    double gpa = sum / 10;
    cout << "Средний балл равен: " << gpa << endl;
    return gpa;
}
void allInf(Students &novyi) {
   
    Sleep(800);
    system("CLS");
    cout << novyi.name << " ";
    cout << novyi.surname << endl;
    cout << "Номер зачетной книжки: " << novyi.recbook << endl;
    cout << "Оценки:\n";
    for (int i = 0; i < 10; i++) {
        cout << novyi.assessment[i] << endl;
    }

}
void Student() {
  
    Students novyi;
    NewStudent(novyi);
    double sum = AssessmentStudent(novyi);
    GPA(sum);
    allInf(novyi);

}

/* Задача 3: Перегрузка функции для вычисления площади
   Создайте программу, которая вычисляет площадь различных геометрических фигур с использованием перегрузки функций.
 1 Напишите перегруженную функцию area для вычисления площади:
 ◦ Квадрата (один параметр: сторона)
 ◦ Прямоугольника (два параметра: длина и ширина)
 ◦ Круга (один параметр: радиус)*/
double area(double a) {
    return a * a;
}
double area(double a, double b) {
    return a * b;
}
float area(float r) {
    const double PI = acos(-1.0); 
    return pow(r,2) * PI;
}
void figures() {
    int select;
    float r;
    double a, b;
    do {
        cout << "Веберите фигуру, которой необходимо расчитать площадь? \n" << "1 - Квадрат\n2 - Прямоугольник\n3 - Круг\n4 - Выход\n";
        cin >> select;
        if (select == 1) {
            cout << "Введите длину стороны: ";
            cin >> a;
            cout << area(a) << endl;
        }
        if (select == 2) {
            cout << "Введите длину: ";
            cin >> a;
            cout << "Введите ширину: ";
            cin >> b;
            cout << area(a, b) << endl;
        }
        if (select == 3) {
            cout << "Введите радиус: ";
            cin >> r;
            cout << area(r) << endl;
        }
        if (select == 4) {
        }

        Sleep(500);
    } while (select != 4);
}

/* Задача 4: Перегрузка функции для вычисления максимума
Создайте программу, которая находит максимум среди двух или трех чисел с использованием перегрузки функций.
 1 Напишите перегруженную функцию max для нахождения максимального значения:
 ◦ Среди двух целых чисел.
 ◦ Среди двух чисел с плавающей запятой.
 ◦ Среди трех целых чисел. */
int maxnum(int a, int b) {
    int max = 0;
    if (a > b) {
        max = a;
    }
    if (a < b) {
        max = b;
    }
    if (a == b) {
        cout << "Числа равны\n";
    }
    return max;
}
double maxnum(double x, double y) {
    float max = 0;
    if (x > y) {
        max = x;
    }
    if (x < y) {
        max = y;
    }
    if (x == y) {
        cout << "Числа равны\n";
    }
    return max;
}
int maxnum(int a, int b, int c) {
    int max = 0;
    if (a > b && a > c) {
        max = a; 
    }
    if (b > a && b > c) {
        max = b;
    }
    if (c > a && c > b) {
        max = c;
    }
    if (a == b && b == c) {
        cout << "Числа равны\n";
    }
    return max;
}
void num() {
   
    cout << maxnum(41, 56) << endl;
    cout << maxnum(42.2, 1.3) << endl;
    cout << maxnum(8, 5, 9) << endl;
    
}

/* Задача 2: Управление книгами в библиотеке
Создайте структуру для хранения информации о книгах в библиотеке. Структура должна включать следующие поля:
 • Название книги (строка)
 • Автор (строка)
 • Год издания (целое число)
 • Статус (наличие на складе или выдана, булев тип)
Реализуйте следующие функции:
 1 Функция для добавления новой книги в библиотеку.
 2 Функция для изменения статуса книги (выдана или вернулась на склад).
 3 Функция для поиска книги по названию.
 4 Функция для вывода списка всех книг в библиотеке.
Эти задачи позволят вам практиковаться с основными аспектами работы со структурами данных */
struct Book {

    string name;
    string author;
    int year;
    bool availability;

    int initBook(string n, string a, int y, bool av) {

        name = n;
        author = a;
        year = y;
        availability = av;

    }
};

struct Library {

    Book books[100];
    int amount = 0;

    int addbook(string n, string a, int y, bool av) {

        Book one;


        one.name = n;
        one.author = a;
        one.year = y;

        one.availability = true;

        books[amount] = one;
        amount += 1;

        return amount;
    }

    int addbook() {

        Book one;

        cout << "Введите название книги: ";
        cin >> one.name;
        cout << "Введите автора: ";
        cin >> one.author;
        cout << "Введите год издания: ";
        cin >> one.year;

        one.availability = true;
        
        books[amount] = one;
        amount += 1;

        return amount;
    }
    void av() {
        for (int i = 0; i < amount; i++) {
            cout << "book number of #" << amount + 1 << ":" << endl;
            cout << "name: " << books[i].name << endl;
            cout << "author: " << books[i].author << endl;
            cout << "year: " << books[i].year << endl;
            cout << "status: " << books[i].availability << endl << endl << endl;
        }
        
    }

    void search() {
        string nazvanie;
        bool isfinded = false;
        cout << "Введите название книги: ";
        cin >> nazvanie;
        for (int i = 0; i < amount; i++) {
            if (nazvanie == books[i].name) {
                cout << books[i].name << endl << books[i].author << endl << books[i].year << endl;
                isfinded = true; 
            }
      
        }

        if(isfinded == false)  cout << "Book not found" << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "RU");

    Library lib;

    //lib.addbook(); lib.addbook();
    
    lib.addbook("name123", "author1", 1543, true);
    lib.addbook("1984", "author1", 1543, true);
    lib.addbook("451c", "author1", 1543, true);
    lib.addbook("NASTYASOHNETPOVLADY", "author1", 1543, true);
    lib.addbook("VLADIKLOVENASTYA", "author1", 1543, true);

    lib.av();

    lib.search();

    system("pause");
}

