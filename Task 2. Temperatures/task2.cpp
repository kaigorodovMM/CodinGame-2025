#include <iostream>

using namespace std;


int main()
{
    int n; // количество температур для анализа
    cin >> n; cin.ignore();
    int *temperatures = new int[n];
    for (int i = 0; i < n; i++) { // ввод значений температур
        int t; // значение температуры от -273 до 5526
        cin >> t; cin.ignore();
        temperatures[i] = t;
    }

    if (n == 0) // случай, когда температуры не указаны
        cout << 0 << endl;
    else{
        // поиск минимальной по модулю температуры
        int temp = 10000;
        for (size_t i = 0; i < n; ++i){
            /*
            запомнить значение температуры, если его модуль минимален,
            или, если модули равны, но новое значение является положительным,
            а прошлое отризательным.
            */
            if ((abs(temperatures[i]) < abs(temp)) or 
                (-abs(temperatures[i]) == temp)){
                temp = temperatures[i];
            }
        }
        cout << temp << endl; // вывод найденного значения

        // очистка выделенной под динамический массив памяти, зануление указателя
        delete [] temperatures;
        temperatures = nullptr;
    }
}