#include <iostream>

using namespace std;


int main()
{
    int light_x; // начальная позиция цели (x)
    int light_y; // начальная позиция цели (y)
    int initial_tx; // начальная позиция игрока (x)
    int initial_ty; // начальная позиция игрока (y)
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();
    int x = initial_tx, y = initial_ty; // переменные для текущих координат игрока
    // game loop
    while (1) {
        int remaining_turns; // Количество ходов, которое сможет пройти игрок.
        cin >> remaining_turns; cin.ignore();

        // условия движения: по диагонали
        if (light_x < x and light_y < y){
            cout << "NW" << endl;
            x--;
            y--;
        }
        else if (light_x > x and light_y > y){
            cout << "SE" << endl;
            x++;
            y++;
        }
        else if (light_x < x and light_y > y){
            cout << "SW" << endl;
            x--;
            y++;
        }
        else if (light_x > initial_tx and light_y < initial_ty){
            cout << "NE" << endl;
            x++;
            y--;
        }
        // условия движения: по одной координате
        else if (light_x > x and light_y == y){
            cout << "E" << endl;
            x++;
        }
        else if (light_x < x and light_y == y){
            cout << "W" << endl;
            x--;
        }
        else if (light_x == x and light_y > y){
            cout << "S" << endl;
            y++;
        }
        else if (light_x == x and light_y < y){
            cout << "N" << endl;
            y--;
        }
    }
}