#include <iostream>

using namespace std;

int main()
{

    // game loop
    while (1) {
        int mountains_h[8]; // создание массива из 8 элементов
        for (int i = 0; i < 8; i++) { //заполнение массива входными данными
            int mountain_h; // высота одной горы
            cin >> mountain_h; cin.ignore();
            mountains_h[i] = mountain_h;
        }
        
        // поиск маскимального элемента
        int max_h = 0;
        int max_h_i = -1;
        for (size_t i = 0; i < 8; ++i){
            if (mountains_h[i] > max_h){
                max_h = mountains_h[i];
                max_h_i = i;
            }
        }
        cout << max_h_i << endl; // вывод индекса самой высокой горы
    }
}