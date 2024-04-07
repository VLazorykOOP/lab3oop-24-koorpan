/*#include <iostream>
#include <cmath>
using namespace std;

class RegularTetrahedron {
private:
    double side;
    string color;
public:
    //конструктори
    RegularTetrahedron() {
        side = 0;
        color = "undefined";
    }

    RegularTetrahedron(double s, string col) {
        if (s <= 0) {
            cout << "Помилка: некоректна довжина сторони." << endl;
            side = 0;
        }
        else {
            side = s;
        }
        color = col;
    }

    // функції-члени для обчислення площі, периметру, об'єму
    double surfaceArea() const {
        return sqrt(3) * side * side;
    }
    double perimeter() const {
        return 6 * side;
    }
    double volume() const {
        return (sqrt(2) / 12) * side * side * side;
    }

    // функції-члени для встановлення значень
    void setSide(double s) {
        if (s <= 0) {
            cout << "Помилка: некоректна довжина сторони." << endl;
        }
        else {
            side = s;
        }
    }
    void setColor(string col) {
        color = col;
    }
    // функції-члени для отримання значень
    double getSide() const {
        return side;
    }
    string getColor() const {
        return color;
    }
    //функція для друку
    void print() const {
        cout << "Правильний тетраедр:" << endl;
        cout << "Сторона: " << side << endl;
        cout << "Колір: " << color << endl;
        cout << "Площа поверхні: " << surfaceArea() << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Об'єм: " << volume() << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    //створення об'єкту тетраедра
    RegularTetrahedron tetrahedron(5, "червоний");
    //виведення інформації про тетраедр
    tetrahedron.print();
    //зміна сторони тетраедра та перевірка площі
    tetrahedron.setSide(7);
    cout << "Площа поверхні після зміни сторони: " << tetrahedron.surfaceArea() << endl;
    return 0;
}*/


#include <iostream>
#include <stdexcept>
using namespace std;

class Vector {
private:
    double elements[3];
    int errorCode;
    static int objectCount; // Статичний лічильник об'єктів
public:
    // Конструктори
    Vector() {
        for (int i = 0; i < 3; i++) {
            elements[i] = 0;
        }
        errorCode = 0;
        objectCount++; // Збільшуємо лічильник при створенні нового об'єкту
    }
    Vector(double val) {
        for (int i = 0; i < 3; i++) {
            elements[i] = val;
        }
        errorCode = 0;
        objectCount++; // Збільшуємо лічильник при створенні нового об'єкту
    }
    Vector(double* arr) {
        if (arr == nullptr) {
            errorCode = 1;
        }
        else {
            for (int i = 0; i < 3; i++) {
                elements[i] = arr[i];
            }
            errorCode = 0;
        }
        objectCount++; // Збільшуємо лічильник при створенні нового об'єкту
    }
    // Деструктор
    ~Vector() {
        cout << "Деструктор вектора. Код помилки: " << errorCode << endl;
        objectCount--; // Зменшуємо лічильник при знищенні об'єкту
    }

    // Інші методи класу

    // Функція для встановлення масиву значеннями за замовчуванням
    void setElements(double val = 0) {
        for (int i = 0; i < 3; i++) {
            elements[i] = val;
        }
    }
    // Функція для отримання елементу масиву
    double getElement(int index) const {
        if (index < 0 || index >= 3) {
            throw out_of_range("Недійсний індекс");
        }
        return elements[index];
    }
    // Функція арифметичних операцій
    Vector add(const Vector& other) const {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }
    Vector subtract(const Vector& other) const {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }
    Vector multiply(double scalar) const {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }
    Vector crossProduct(const Vector& other) const {
        Vector result;
        result.elements[0] = elements[1] * other.elements[2] - elements[2] * other.elements[1];
        result.elements[1] = elements[2] * other.elements[0] - elements[0] * other.elements[2];
        result.elements[2] = elements[0] * other.elements[1] - elements[1] * other.elements[0];
        return result;
    }
    // Функція ділення на ціле
    Vector divide(short divisor) const {
        Vector result;
        if (divisor != 0) {
            for (int i = 0; i < 3; i++) {
                result.elements[i] = elements[i] / divisor;
            }
        }
        else {
            cout << "НЕ можна ділити на 0!";
        }
        return result;
    }
    // Функції порівняння
    bool isEqual(const Vector& other) const {
        for (int i = 0; i < 3; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }
    bool isNotEqual(const Vector& other) const {
        return !isEqual(other);
    }
    bool isGreater(const Vector& other) const {
        for (int i = 0; i < 3; i++) {
            if (elements[i] <= other.elements[i]) {
                return false;
            }
        }
        return true;
    }
    bool isLess(const Vector& other) const {
        for (int i = 0; i < 3; i++) {
            if (elements[i] >= other.elements[i]) {
                return false;
            }
        }
        return true;
    }
    bool isGreaterOrEqual(const Vector& other) const {
        return !isLess(other);
    }
    bool isLessOrEqual(const Vector& other) const {
        return !isGreater(other);
    }
    // Функція для виведення вектора
    void print() const {
        cout << "(" << elements[0] << ", " << elements[1] << ", " << elements[2] << ")" << endl;
    }

    // Статичний метод для отримання кількості створених об'єктів
    static int countObjects() {
        return objectCount;
    }
};

// Ініціалізація статичного лічильника класу Vector
int Vector::objectCount = 0;

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // Vector тест
    Vector v1; // Створюємо об'єкт за допомогою конструктора за замовчуванням
    Vector v2(1.5); // Створюємо об'єкт за допомогою конструктора з одним параметром
    double arr[3] = { 2.5, 3.5, 4.5 };
    Vector v3(arr); // Створюємо об'єкт за допомогою конструктора з вказівником
    // Виведення векторів
    cout << "Вектор v1: ";
    v1.print();
    cout << "Вектор v2: ";
    v2.print();
    cout << "Вектор v3: ";
    v3.print();
    // Підрахунок числа об'єктів
    cout << "Кількість об'єктів типу Vector: " << Vector::countObjects() << endl;
    //Деструктор вектора. Код помилки: 0(означає що помилок немає)
    return 0;
}