//Сервер

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const int N = 3;

struct Human {
    char name[20];
    int s[N];
} B;

int ans;
long previousSize;

int main() {
    setlocale(LC_ALL, "rus");

    // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleCP(1251);

    // установка кодовой страницы win-cp 1251 в поток вывода
    SetConsoleOutputCP(1251);

    ifstream in;
    ofstream out;

    //файл запросов клиентов
    const char* request = "1";

    //файл ответов сервера
    const char* answer = "2";

    cout << "Сервер запущен" << endl;

    //открытие файла REQUEST
    in.open(request, ios::binary);

    //стартовая позиция сервера в файле REQUEST
    in.seekg(0, ios::end);

    //записываем размер файла
    previousSize = in.tellg();

    in.close();

    // начало работы сервера
    while (true) {
        //открытие файла REQUEST
        in.open(request, ios::binary);

        //переход в конец файла REQUEST
        in.seekg(0, ios::end);

        //проверка на наличие новых запросов
        while (previousSize >= in.tellg()) {
            in.seekg(0, ios::end);
        }

        //переход к началу полученного запроса
        in.seekg(previousSize, ios::beg);

        //считывание данных клиента
        in.read((char*)&B, sizeof(B));

        // на конец обработанных данных
        previousSize = in.tellg();

        in.close();

        // определение оценки
        double sum = B.s[0] + B.s[1] + B.s[2];
        sum /= N;
        ans = static_cast<int>(std::round(sum));
        cout << B.name<</*" "<<sum<<*/ endl;
        // передача ответа клиенту
        out.open(answer, ios::binary | ios::app);

        //открытие файла ANSWER
        out.write((char*)&ans, sizeof(ans));

        //запись ответа клиенту
        out.close();
    }
}