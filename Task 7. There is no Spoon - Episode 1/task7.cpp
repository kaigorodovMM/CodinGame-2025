#include <iostream>
#include <string>

using namespace std;


int main()
{
    // задание размеров поля
    int width; 
    cin >> width; cin.ignore();
    int height; 
    cin >> height; cin.ignore();

    //создание двумерного массива
    char** grid = new char* [height];
    for (size_t i = 0; i < height; ++i) {
        grid[i] = new char[width];
    }

    //заполнение двумерного массива
    for (size_t i = 0; i < height; ++i) {
        string line;
        getline(cin, line); // строка символов 0 или .
        cerr << line << endl;
        for (size_t j = 0; j < width; ++j) {
            grid[i][j] = line[j];
        }
    }


    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            //вывод исследуемого узла
            if (grid[i][j] == '.'){
                continue;
            }
            cout << j << " " << i << " ";
            
            
            bool neighbor = false; // переменная для запоминания, найден ли сосед
            // проверка наличия соседа справа
            for (size_t k = j + 1; k < width; ++k){
                
                if (grid[i][k] == '0'){
                    cout << k << " " << i << " ";
                    neighbor = true;
                    break;
                }
            }
            if (neighbor == false){ // случай, когда сосед не найден
                cout << -1 << " " << -1 << " ";
            }

            neighbor = false;
            // проверка наличия соседа снизу
            for (size_t k = i + 1; k < height; ++k){
                
                if (grid[k][j] == '0'){
                    cout << j << " " << k << " ";
                    neighbor = true;
                    break;
                }
            }
            if (neighbor == false){ // случай, когда сосед не найден
                cout << -1 << " " << -1 << " ";
            }
            
            cout << endl;
        }
    }

    // очистка памяти
    for (size_t i = 0; i < height; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}