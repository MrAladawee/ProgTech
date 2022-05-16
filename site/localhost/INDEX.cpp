#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void show_content();
void show_menu();

int main()
{
    cout << "Content-type: text/html; charset=Windows-1251\n\n";
    ifstream f("index.txt");
    if (f.is_open())
    {
        auto sz = 65536;
        auto buf = new char[sz];
        while (!f.eof())
        {
            f.getline(buf, sz);
            if (strcmp(buf, "<!--#CONTENT#-->") == 0)
            {
                show_content();
            }
            else if (!strcmp(buf, "<!--#MENU#-->"))
            {
                show_menu();
            }
            cout << buf;
        }
        delete[] buf;
        f.close();
    }
    else
    {
        cout << "Не удалось отобразить сайт :(";
    }

}

void show_menu()
{
    ifstream f("menu-index.txt");
    if (f.is_open())
    {
        auto sz = 1024;
        auto buf = new char[sz];
        while (!f.eof())
        {
            f.getline(buf, sz);
            char* name;
            char* addrr = strtok_s(buf, " ", &name);

            if (string(name) == "Главная") {
                cout << "<img src='assets/image/index/about/2.jpg' alt=''>" << endl;
            }

            else if (string(name) == "Текущие задания") {
                cout << "<img src='assets/image/index/about/1.jpg' alt=''>" << endl;
            }

            else if (string(name) == "Выполненные задания") {
                cout << "<img src='assets/image/index/about/6.jpg' alt=''>" << endl;
            }

            cout << "</div>" << endl;
            cout << "<div class='about__text'>" << endl;
            cout << "<a href='" << addrr << "'>" << name << "</a>" << endl;
            cout << "</div>" << endl;
            cout << "</div> <!-- item -->" << endl;

        }
    }
    f.close();
}

void show_content()
{
    cout << "<div class='menu__text'>"
            "<p>Данный сайт был создан исключительно для личного пользования по выданному заданию. Данный ресурс предполагает хранение выполненных домашних работ.</p>"
            "</div>";
}
