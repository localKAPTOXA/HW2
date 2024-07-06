#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <regex>

using namespace std;

void out(bool b)
{
    cout << (b ? "��� ������ ������������� ����������� ���������" : "��� ������ �� ������������� ����������� ���������") << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string data;
    //data = "  12.43��� ������ 12354 ������� ����� 123.8437��.��";
    data = "�������� ������ ����    ������   0923   ���������  671236 khg jfy";
    //data = "�������� 73 ������� ����� 8347��.�� ����";

    cout << "����������� ������: " << data << endl << endl;

    regex reg("(((\\s+\\d+\\.\\d+.+\\s+)|(.+\\s+))|(.{0}))(��������|�������|������|��������)((\\s+\\d*\\s+)|(\\s+))(((�������\\s+.+\\s+\\d+((\\.\\d+)|(.{0}))��\\.��))|(���������\\s+(\\d+(\\.\\d+)*)))");
   
    auto pos = data.cbegin();
    auto end = data.cend();
    smatch m;
    bool search = regex_search(data, reg);
    if (search) {
        for (; regex_search(pos, end, m, reg); pos = m.suffix().first)
        {
            string str = m.str(18);
            if (str.empty()) {
                cout << "��������� search: " << m.str() << endl;
            }
            else {
                cout << "������: ��������� �������� �� � ����� ��������\n";
                return 0;
            }
        }
    }
    else {
        cout << "��� ����� ���������" << endl;
    }

    bool match = regex_match(data, reg);
    cout << "��������� match: ";
    out(match);

    return 0;
}