#include <iostream>
#include <sstream>
#include <string>

// Для корректной работы freeaddrinfo в MinGW
#define _WIN32_WINNT 0x501
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
#define BUF_SIZE 1024

using std::cerr;
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "НТТР - сервер запущен\n";


    WSADATA ws;
    if (WSAStartup(MAKEWORD(2, 2), &ws)) {
        cerr << "Erorr WSAStartup! \n" << WSAGetLastError();
        return -1;
    }

    // IP-адрес слушающего сокета сервера
    addrinfo* addr = NULL;

    // Шаблон для инициализации структуры адреса
    addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo("127.0.0.1", "8000", &hints, &addr)) {
        cerr << "Error getaddrinfo! \n" << WSAGetLastError();
        WSACleanup();
        return -1;
    }

    SOCKET listener = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    if (listener == INVALID_SOCKET) {
        cerr << "Error socket! \n" << WSAGetLastError();
        WSACleanup();
        return -1;
    }

    if (bind(listener, addr->ai_addr, addr->ai_addrlen) == SOCKET_ERROR) {
        cerr << "Error bind! \n" << WSAGetLastError();
        closesocket(listener);
        freeaddrinfo(addr);
        WSACleanup();
        return -1;
    }

    if (listen(listener, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Error bind! \n" << WSAGetLastError();
        closesocket(listener);
        freeaddrinfo(addr);
        WSACleanup();
        return -1;
    }
    char buf[BUF_SIZE] = {};
    SOCKET sClient;

    while (true) {

        if ((sClient = accept(listener, NULL, NULL)) == INVALID_SOCKET) {
            cerr << "Error accept! \n" << WSAGetLastError();
            closesocket(listener);
            freeaddrinfo(addr);
            WSACleanup();
            return -1;
        }
        int len = recv(sClient, (char*)buf, BUF_SIZE, 0);
        if (len == SOCKET_ERROR) {
            cerr << "Error recv! \n" << WSAGetLastError();
            closesocket(sClient);
        }
        if (len == 0) {
            cout << "Связь с клиентом закрыта" << endl;
        }
        else {
            cout << "Новый клиент!\n";

            buf[len] = '\0';


            std::stringstream responseBody, response;

            responseBody<<"<title>test serv</title>\n"
                << "<h1>serv</h1>\n"
                << "<p>...</p>\n"
                << "<h2>header request</h2>\n"
                << "<pre>" << buf << "</pre>\n"
                << "<em><small>test serv on c++</small></em>\n";



            response << "HTTP/1.1 200 OK\r\n"
                << "Version: HTTP/1.1\r\n"
                << "Content-Type: text/html; charset=utf-8\r\n"
                << "Content-Length: " << responseBody.str().length()
                << "\r\n\r\n" << responseBody.str();

            if (send(sClient, response.str().c_str(),
                response.str().length(), 0) == SOCKET_ERROR) {
                cerr << "Ошибка send! \n" << WSAGetLastError();
            }

            closesocket(sClient);
        }
    }
    closesocket(listener);
    freeaddrinfo(addr);
    WSACleanup();
    return 0;
}