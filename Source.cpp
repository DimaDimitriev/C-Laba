#include <iostream>
#include <vector>
#include <iomanip> // ��� std::setw

int main() {

    setlocale(LC_ALL, "Russian");
    std::cout << "���, �����, ���, ����������� 1.2, ��������� �.�., ������������ ������ �6" << std::endl;//������ ������� �����
    std::cout << "��������� � �������" << std::endl;//����������� ��������� �������


    int n;
    std::cout << "������� ����� n (n < 5): ";
    std::cin >> n;

    const int size = 2 * n + 1;
    std::vector<std::vector<int>> A(size, std::vector<int>(size, 0));

    int x = n; 
    int y = n; 
    A[x][y] = 0; 

    int num = 1; 
    int step = 1; 
    while (num < size * size) {
        // �������� �����
        for (int i = 0; i < step && num < size * size; ++i) {
            --x;
            A[x][y] = num++;
        }
        // �������� �����
        for (int i = 0; i < step && num < size * size; ++i) {
            --y;
            A[x][y] = num++;
        }
        // ����������� ��� ����� ���������� ���� �����������
        ++step;

        // �������� ����
        for (int i = 0; i < step && num < size * size; ++i) {
            ++x;
            A[x][y] = num++;
        }
        // �������� ������
        for (int i = 0; i < step && num < size * size; ++i) {
            ++y;
            A[x][y] = num++;
        }
        // ����������� ��� ����� ���������� ���� �����������
        ++step;
    }

    // ������� ������
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(3) << A[i][j]; // ���������� setw ��� ��������
        }
        std::cout << std::endl;
    }

    return 0;
}