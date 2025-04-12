//Клиент

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const int N = 3;

struct Chel
{
    char name[20];
    int s[N];
} A;

int main() {
    // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleCP(1251);

    // установка кодовой страницы win-cp 1251 в поток вывода
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");

    ofstream f_REQ;
    ifstream f_ANS;

    long previousSize;
    int ans;

    //файл для ответов сервера
    const char* answer = "1";

    //файл запросов клиентов
    const char* request = "2";

    while (true)
    {
        // передача данных от клиента серверу
        cout << "Введите имя и оценки: " << endl;
        cin >> A.name >> A.s[0] >> A.s[1] >> A.s[2];

        //открытие файла REQUEST
        f_REQ.open(answer, ios::app | ios::binary);

        //запись запроса в файл REQUEST
        f_REQ.write((char*)&A, sizeof(A));

        f_REQ.close();

        // поступил ответ от сервера?
        f_ANS.open(request, ios::binary);
        //открытие файла ANSWER
        f_ANS.seekg(0, ios::end);
        //переход в конец файла ANSWER
        previousSize = f_ANS.tellg();
        while (previousSize >= f_ANS.tellg()) {
            // ждем и переходим в конец файла ANSWER
            f_ANS.seekg(0, ios::end);
        }
        // получение ответа от сервера
        f_ANS.seekg(previousSize, ios::beg);
        // на начало нового ответа
        f_ANS.read((char*)&ans, sizeof(ans));
        //считывание ответа
        f_ANS.close();

        // расшифровка ответа
        cout << ans <<endl;
    }
    return 0;
}