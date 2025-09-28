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