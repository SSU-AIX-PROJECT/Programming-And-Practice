#include <winsock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

extern "C" int getConnenctionNumber() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed.\n";
        system("pause");
        return -1;
    }

    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;          // We are targeting IPv4
    hints.ai_protocol = IPPROTO_TCP;    // We are targeting TCP
    hints.ai_socktype = SOCK_STREAM;    // We are targeting TCP so its SOCK_STREAM

    struct addrinfo *targetAdressInfo = NULL;
    DWORD getAddrRes = getaddrinfo("127.0.0.1", NULL, &hints, &targetAdressInfo);
    if (getAddrRes != 0 || targetAdressInfo == NULL) {
        cout << "Could not resolve the Host Name" << endl;
        system("pause");
        WSACleanup();
        return -1;
    }

    SOCKADDR_IN sockAddr;
    sockAddr.sin_addr = ((struct sockaddr_in *) targetAdressInfo->ai_addr)->sin_addr;    // The IPv4 Address from the Address Resolution Result
    sockAddr.sin_family = AF_INET;  // IPv4
    sockAddr.sin_port = htons(8000);  // HTTP Port: 80

    freeaddrinfo(targetAdressInfo);

    SOCKET webSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (webSocket == INVALID_SOCKET) {
        cout << "Creation of the Socket Failed" << endl;
        system("pause");
        WSACleanup();
        return -1;
    }
    cout << "Connecting...\n";
    if (connect(webSocket, (SOCKADDR *) &sockAddr, sizeof(sockAddr)) != 0) {
        cout << "Could not connect";
        system("pause");
        closesocket(webSocket);
        WSACleanup();
        return -1;
    }
    cout << "Connected.\n";
    const char *httpRequest = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n";
    int sentBytes = send(webSocket, httpRequest, strlen(httpRequest), 0);
    if (sentBytes < strlen(httpRequest) || sentBytes == SOCKET_ERROR) {
        cout << "Could not send the request to the Server" << endl;
        system("pause");
        closesocket(webSocket);
        WSACleanup();
        return -1;
    }
    char buffer[100];
    ZeroMemory(buffer, sizeof(buffer));
    int dataLen;
    while ((dataLen = recv(webSocket, buffer, sizeof(buffer), 0) > 0)) {}
    closesocket(webSocket);
    WSACleanup();

    istringstream ss(buffer);
    string stringBuffer;
    vector<string> x;
    x.clear();

    int cnt = 0;
    int resNum = -1;
    while (getline(ss, stringBuffer, '|')) {

        x.push_back(stringBuffer);
        if (cnt++ == 1) {
            resNum = stoi(stringBuffer);
//            cout << stringBuffer << " ";
        }
    }

//    system("pause");
    return resNum;
}