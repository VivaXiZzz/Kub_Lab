#include <WinSock2.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <unordered_map>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define PORT 1250   
#define sHELLO "Привет, STUDENT\n"
#define BUFF_SIZE 40

struct Stud {
    string name;
};

struct Fac {
    string faculty;
};

int main() {
    WSADATA wsData;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (WSAStartup(MAKEWORD(1, 1), &wsData))
        cout << "Error WSAStartup " << WSAGetLastError() << endl;

    SOCKET serv_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (serv_sock == INVALID_SOCKET)
        cout << "Error initialization socket " << WSAGetLastError() << endl;

    sockaddr_in serv_info;
    ZeroMemory(&serv_info, sizeof(serv_info));

    serv_info.sin_family = AF_INET;
    serv_info.sin_addr.s_addr = INADDR_ANY;
    serv_info.sin_port = htons(PORT);
    bind(serv_sock, (sockaddr*)&serv_info, sizeof(serv_info));

    sockaddr_in client_info;
    ZeroMemory(&client_info, sizeof(client_info));

    int client_info_size = sizeof(client_info);

    Stud data_in;
    Fac data_out;

    unordered_map<string, string> faculty = {
        {"дима", "ргф"},
        {"вася", "эконом"},
        {"андрей","физфак"},
        {"вова","фктипм"},
        {"рома", "биофак"},
        {"маша", "химфак"},
    };

    while (true) {
        recvfrom(serv_sock, (char*)&data_in, sizeof(data_in) - 1, 0,
            (sockaddr*)&client_info, &client_info_size);

        data_out.faculty = faculty.at(data_in.name);

        sendto(serv_sock, (char*)&data_out, sizeof(data_out), 0,
            (sockaddr*)&client_info, sizeof(client_info));
        cout << "name: " << data_in.name << endl;
    }
    closesocket(serv_sock);

    return 0;



    char buff[1024];
    // шаг 1 - подключение библиотеки 
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
    {
        cout << "WSAStartup error: " << WSAGetLastError();
        return -1;
    }
    SOCKET Lsock;
    Lsock = socket(AF_INET, SOCK_DGRAM, 0);
    if (Lsock == INVALID_SOCKET) {
        cout << "SOCKET() ERROR: " << WSAGetLastError();
        WSACleanup();
        return -1;
    }
    // шаг 3 - связывание сокета с локальным адресом 
    sockaddr_in Laddr;
    Laddr.sin_family = AF_INET;
    Laddr.sin_addr.s_addr = INADDR_ANY;   // или 0 (любой IP адрес)
    Laddr.sin_port = htons(PORT);
    if (bind(Lsock, (sockaddr*)&Laddr, sizeof(Laddr)))
    {
        cout << "BIND ERROR:" << WSAGetLastError();
        closesocket(Lsock);
        WSACleanup();
        return -1;
    }
    // шаг 4 обработка пакетов, присланных клиентами
    while (1) {
        sockaddr_in    Caddr;
        int Caddr_size = sizeof(Caddr);
        int bsize = recvfrom(Lsock, &buff[0], sizeof(buff) - 1, 0,
            (sockaddr*)&Caddr, &Caddr_size);
        if (bsize == SOCKET_ERROR)
            cout << "RECVFROM() ERROR:" << WSAGetLastError();
        // Определяем IP-адрес клиента и прочие атрибуты
        HOSTENT* hst;
        hst = gethostbyaddr((char*)&Caddr.sin_addr, 4, AF_INET);
        cout << "NEW DATAGRAM!\n" <<
            ((hst) ? hst->h_name : "Unknown host") << "/n" <<
            inet_ntoa(Caddr.sin_addr) << "/n" << ntohs(Caddr.sin_port) << '\n';
        buff[bsize] = '\0';              // добавление завершающего нуля
        cout << "C=>S:" << buff << '\n';        // Вывод на экран 
        // посылка датаграммы клиенту
        sendto(Lsock, &buff[0], bsize, 0, (sockaddr*)&Caddr, sizeof(Caddr));
    }      return 0;
}
