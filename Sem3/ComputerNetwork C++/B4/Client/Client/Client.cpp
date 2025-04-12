#include <WinSock2.h>
#include <iostream>
#include <string>
#include <windows.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define PORT 1250
#define SRV_HOST "localhost"
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

    SOCKET client_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_sock == INVALID_SOCKET)
        cout << "Error initialization socket " << WSAGetLastError() << endl;

    hostent* hp;
    hp = gethostbyname(SRV_HOST);

    sockaddr_in serv_info;
    ZeroMemory(&serv_info, sizeof(serv_info));

    serv_info.sin_family = AF_INET;
    ((unsigned long*)&serv_info.sin_addr)[0] = ((unsigned long**)hp->h_addr_list)[0][0];
    serv_info.sin_port = htons(PORT);

    int serv_info_size = sizeof(serv_info);

    Fac data_in;
    Stud data_out;

    while (true) {
        cout << "Введи имя студента: ";
        cin >> data_out.name;

        sendto(client_sock, (char*)&data_out, sizeof(data_out), 0,
            (sockaddr*)&serv_info, sizeof(serv_info));

        recvfrom(client_sock, (char*)&data_in, sizeof(data_in) - 1, 0,
            (sockaddr*)&serv_info, &serv_info_size);
        cout << data_in.faculty << endl;
    }
    closesocket(client_sock);

    return 0;
}