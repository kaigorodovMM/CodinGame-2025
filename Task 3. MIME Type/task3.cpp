#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string,string> types; // создание словаря для храниения таблицы ассоциаций.
    int n; // Количество элементов в таблице ассоциаций
    cin >> n; cin.ignore();
    int q; // Количество имён файлов для анализа
    cin >> q; cin.ignore();
    for (int i = 0; i < n; i++) {
        string ext; // Тасширение файла
        string mt; // MIME тип.
        cin >> ext >> mt; cin.ignore();
        for (size_t i = 0; i < size(ext); ++i){
            ext[i] = tolower(ext[i]); // привести строку к нижнему регистру
        }
        types[ext] = mt;
    }

    for (int i = 0; i < q; i++) {
        string fname;
        getline(cin, fname); // Ввод имени файла для анализа
        for (size_t i = 0; i < size(fname); ++i){
            fname[i] = tolower(fname[i]); // привести строку к нижнему регистру
        }
        size_t pos = fname.rfind('.'); // поиск вхождения последней точки в имени файла
        // проверка, что точка есть и что такое расширение есть в словаре.
        if (pos != -1 and types.count(fname.substr(pos+1)) == 1) 
            cout << types[fname.substr(pos+1)] << endl; // вывод MIME type из словаря
        else {
            cout << "UNKNOWN" << endl; // случай, когда типа нет в словаре или нет расширения
        }
    }

}