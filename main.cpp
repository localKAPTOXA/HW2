#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <regex>

using namespace std;

void out(bool b)
{
    cout << (b ? "Вся строка удовлетворяет регулярному выражению" : "Вся строка НЕ удовлетворяет регулярному выражению") << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string data;
    //data = "  12.43рыо Польша 12354 площадь ирваи 123.8437кв.км";
    data = "олыирлва ыврашы ыгрв    Польша   0923   население  671236 khg jfy";
    //data = "Беларусь 73 площадь оывар 8347кв.км ывтщ";

    cout << "Изначальная строка: " << data << endl << endl;

    regex reg("(((\\s+\\d+\\.\\d+.+\\s+)|(.+\\s+))|(.{0}))(Беларусь|Венгрия|Польша|Болгария)((\\s+\\d*\\s+)|(\\s+))(((площадь\\s+.+\\s+\\d+((\\.\\d+)|(.{0}))кв\\.км))|(население\\s+(\\d+(\\.\\d+)*)))");
   
    auto pos = data.cbegin();
    auto end = data.cend();
    smatch m;
    bool search = regex_search(data, reg);
    if (search) {
        for (; regex_search(pos, end, m, reg); pos = m.suffix().first)
        {
            string str = m.str(18);
            if (str.empty()) {
                cout << "Результат search: " << m.str() << endl;
            }
            else {
                cout << "Ошибка: население передано не в целом значении\n";
                return 0;
            }
        }
    }
    else {
        cout << "Нет такой подстроки" << endl;
    }

    bool match = regex_match(data, reg);
    cout << "Результат match: ";
    out(match);

    return 0;
}