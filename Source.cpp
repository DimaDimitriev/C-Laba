#include <iostream>
#include <vector>
#include <iomanip> // Äëÿ std::setw

int main() {

    setlocale(LC_ALL, "Russian");
    std::cout << "ÒÏÓ, ÈØÈÒÐ, ÎÈÒ, Èíôîðìàòèêà 1.2, Äèìèòðèåâ Ä.À., ëàáîðàòîðíàÿ ðàáîòà ¹6" << std::endl;//Çàäàåì ðóññêèé òåêñò
    std::cout << "Óêàçàòåëè è ìàññèâû" << std::endl;//íàñòðàèâàåì êîäèðîâêó êîíñîëè


    int n;
    std::cout << "Ââåäèòå ÷èñëî n (n < 5): ";
    std::cin >> n;

    const int size = 2 * n + 1;
    std::vector<std::vector<int>> A(size, std::vector<int>(size, 0));

    int x = n; 
    int y = n; 
    A[x][y] = 0; 

    int num = 1; 
    int step = 1; 
    while (num < size * size) {
        // Äâèæåíèå ââåðõ
        for (int i = 0; i < step && num < size * size; ++i) {
            --x;
            A[x][y] = num++;
        }
        // Äâèæåíèå âëåâî
        for (int i = 0; i < step && num < size * size; ++i) {
            --y;
            A[x][y] = num++;
        }
        // Óâåëè÷èâàåì øàã ïîñëå çàâåðøåíèÿ äâóõ íàïðàâëåíèé
        ++step;

        // Äâèæåíèå âíèç
        for (int i = 0; i < step && num < size * size; ++i) {
            ++x;
            A[x][y] = num++;
        }
        // Äâèæåíèå âïðàâî
        for (int i = 0; i < step && num < size * size; ++i) {
            ++y;
            A[x][y] = num++;
        }
        // Óâåëè÷èâàåì øàã ïîñëå çàâåðøåíèÿ äâóõ íàïðàâëåíèé
        ++step;
    }

    // Âûâîäèì ìàññèâ
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(3) << A[i][j]; // Èñïîëüçóåì setw äëÿ îòñòóïîâ
        }
        std::cout << std::endl;
    }

    return 0;
}
