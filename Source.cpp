#include <iostream>
#include <vector>
#include <iomanip> // Для std::setw

int main() {

    setlocale(LC_ALL, "Russian");
    std::cout << "ТПУ, ИШИТР, ОИТ, Информатика 1.2, Димитриев Д.А., лабораторная работа №6" << std::endl;//Задаем русский текст
    std::cout << "Указатели и массивы" << std::endl;//настраиваем кодировку консоли


    int n;
    std::cout << "Введите число n (n < 5): ";
    std::cin >> n;

    const int size = 2 * n + 1;
    std::vector<std::vector<int>> A(size, std::vector<int>(size, 0));

    int x = n; 
    int y = n; 
    A[x][y] = 0; 

    int num = 1; 
    int step = 1; 
    while (num < size * size) {
        // Движение вверх
        for (int i = 0; i < step && num < size * size; ++i) {
            --x;
            A[x][y] = num++;
        }
        // Движение влево
        for (int i = 0; i < step && num < size * size; ++i) {
            --y;
            A[x][y] = num++;
        }
        // Увеличиваем шаг после завершения двух направлений
        ++step;

        // Движение вниз
        for (int i = 0; i < step && num < size * size; ++i) {
            ++x;
            A[x][y] = num++;
        }
        // Движение вправо
        for (int i = 0; i < step && num < size * size; ++i) {
            ++y;
            A[x][y] = num++;
        }
        // Увеличиваем шаг после завершения двух направлений
        ++step;
    }

    // Выводим массив
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(3) << A[i][j]; // Используем setw для отступов
        }
        std::cout << std::endl;
    }

    return 0;
}