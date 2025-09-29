#include <iostream>

using namespace std;


int main()
{
    int h;
    cin >> h; cin.ignore();

    //создание двумерного массива
    int** arr_2d = new int* [h];
    for (size_t i = 0; i < h; ++i) {
        arr_2d[i] = new int[h];
    }

    //заполнение двумерного массива
    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < h; ++j) {
            cin >> arr_2d[i][j];
            //cerr << arr_2d[i][j] << " ";
        }
        //cerr << endl;
    }
    // были ли уже найдены пики или провалы
    bool peaks = false;
    bool valleys = false;

    // проверка условий для пика
    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < h; ++j) {
            int zn = arr_2d[i][j];
            if (i == h - 1 or i != h - 1 and arr_2d[i][j] > arr_2d[i + 1][j])
                if (j == h - 1 or j != h - 1 and arr_2d[i][j] > arr_2d[i][j + 1])
                    if (i == 0 or i != 0 and arr_2d[i][j] > arr_2d[i - 1][j])
                        if (j == 0 or j != 0 and arr_2d[i][j] > arr_2d[i][j - 1])
                            if (i == 0 or j == 0 or i != 0 and j != 0 and arr_2d[i][j] > arr_2d[i - 1][j - 1])
                                if (i == h - 1 or j == h - 1 or i != h - 1 and j != h - 1 and arr_2d[i][j] > arr_2d[i + 1][j + 1])
                                    if (i == 0 or j == h - 1 or i != 0 and j != h - 1 and arr_2d[i][j] > arr_2d[i - 1][j + 1])
                                        if (i == h - 1 or j == 0 or i != h - 1 and j != 0 and arr_2d[i][j] > arr_2d[i + 1][j - 1]) {
                                            // клетка является пиком
                                            if (peaks == false)
                                                cout << "(" << j << ", " << i << ")"; // первый вывод
                                            else
                                                cout << ", (" << j << ", " << i << ")"; // последующие выводы
                                            peaks = true;
                                        }

        }
    }
    // вывод, если пики отсутствуют
    if (peaks == false)
        cout << "NONE";
    cout << endl;

    // проверка условий для впадины
    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < h; ++j) {
            if (i == h - 1 or i != h - 1 and arr_2d[i][j] < arr_2d[i + 1][j])
                if (j == h - 1 or j != h - 1 and arr_2d[i][j] < arr_2d[i][j + 1])
                    if (i == 0 or i != 0 and arr_2d[i][j] < arr_2d[i - 1][j])
                        if (j == 0 or j != 0 and arr_2d[i][j] < arr_2d[i][j - 1])
                            if (i == 0 or j == 0 or i != 0 and j != 0 and arr_2d[i][j] < arr_2d[i - 1][j - 1])
                                if (i == h - 1 or j == h - 1 or i != h - 1 and j != h - 1 and arr_2d[i][j] < arr_2d[i + 1][j + 1])
                                    if (i == 0 or j == h - 1 or i != 0 and j != h - 1 and arr_2d[i][j] < arr_2d[i - 1][j + 1])
                                        if (i == h - 1 or j == 0 or i != h - 1 and j != 0 and arr_2d[i][j] < arr_2d[i + 1][j - 1]) {
                                            // клетка является впадиной
                                            if (valleys == false)
                                                cout << "(" << j << ", " << i << ")"; // первый вывод
                                            else
                                                cout << ", (" << j << ", " << i << ")"; // последующие выводы
                                            valleys = true;
                                        }

        }
    }
    //вывод, если впадины отстутствуют
    if (valleys == false)
        cout << "NONE";
    cout << endl;


    // очистка памяти
    for (size_t i = 0; i < h; ++i) {
        delete[] arr_2d[i];
    }
    delete[] arr_2d;

    
}