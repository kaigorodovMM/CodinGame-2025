#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    int max_v; // максимальное значение на данный момент
    cin >> max_v;
    int max_dist = 0; // максимальное падение на данный момент
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        if (v - max_v < max_dist) {
            max_dist = v - max_v; // обновление максимального падения
        }
        if (v > max_v) {
            max_v = v; // обновление максимального значения
        }
    }

    cout << max_dist << endl;
}