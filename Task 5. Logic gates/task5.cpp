#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    int m;
    cin >> m; cin.ignore();
    unordered_map <string, string> s_map; // создание словаря для хранения входных сигналов

    int len = 0; // переменная для определения длины сигналов
    for (int i = 0; i < n; i++) {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal; cin.ignore();
        s_map[input_name] = input_signal; // запись в словарь
        if (len == 0){ // сохранение длины сигналов
            len = size(input_signal); 
        }
    }
    for (int i = 0; i < m; i++) {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();
        string str1 = s_map[input_name_1];
        string str2 = s_map[input_name_2];
        cout << output_name << " "; // вывод имени выходного сигнала и пробела
        // вополнение логических операций и вывод результатов
        if (type == "AND"){
            for(size_t i = 0; i < len; ++i){
                if (str1[i] == '-' and str2[i] == '-')
                    cout << "-";
                else
                    cout << "_";
            }
        }
        if (type == "OR"){
            for(size_t i = 0; i < len; ++i){
                if (str1[i] == '-' or str2[i] == '-')
                    cout << "-";
                else
                    cout << "_";
            }
        }
        if (type == "XOR"){
            for(size_t i = 0; i < len; ++i){
                if (str1[i] == '-' and str2[i] == '_' or str1[i] == '_' and str2[i] == '-')
                    cout << "-";
                else
                    cout << "_";
            }
        }
        if (type == "NAND"){
            for(size_t i = 0; i < len; ++i){
                if (str1[i] == '-' and str2[i] == '-')
                    cout << "_";
                else
                    cout << "-";
            }
        }
        if (type == "NOR"){
            for(size_t i = 0; i < len; ++i){
                if (str1[i] == '-' or str2[i] == '-')
                    cout << "_";
                else
                    cout << "-";
            }
        }
        if (type == "NXOR"){
            for(size_t i = 0; i < len; ++i){
                if (str1[i] == '-' and str2[i] == '_' or str1[i] == '_' and str2[i] == '-')
                    cout << "_";
                else
                    cout << "-";
            }
        }
        cout << endl; // конец строки

    }

}