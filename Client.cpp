//Implementation of CClient
#include "Client.h"
#include <cstdio>
int CClient::Connect(int port, const char *address)
{
    int nStatus = 0;
    WSAData wsadata;
    //Launch winsock
    int nErrMsg = WSAStartup(MAKEWORD(1, 1), &wsadata);
    if (nErrMsg != NO_ERROR)
    {
        nStatus = 1;
        return nStatus;
    }
    //Generate socket
    m_socketKernel = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socketKernel == INVALID_SOCKET)
    {
        nStatus = 2;
        return nStatus;
    }
    //Initial Server
    sockaddr_in sockaddrServer;
    ZeroMemory((char*)&sockaddrServer, sizeof(sockaddrServer));
    sockaddrServer.sin_family = AF_INET;
    sockaddrServer.sin_port = port;
    sockaddrServer.sin_addr.S_un.S_addr = inet_addr(address);
    //Connect
    nErrMsg = connect(m_socketKernel, (sockaddr*)&sockaddrServer, sizeof(sockaddrServer));
    if (nErrMsg < 0)
    {
        nStatus = 3;
        return nStatus;
    }
    ioctlsocket(m_socketKernel, FIONBIO, (u_long*)&nMode);
    return nStatus;
}
int CClient::SendMsg(const char *msg, int len)
{
    int nStatus = 0;
    //Send Message
    int nErrMsg = send(m_socketKernel, msg, len, 0);
    if (nErrMsg < 0)
    {
        nStatus = 1;
        return nStatus;
    }
    return nStatus;
}
void CClient::Close()
{
    int nErrMsg = closesocket(m_socketKernel);
}
CClient::CClient(int mode)
{
    nMode = mode;
}
int CClient::RecvMsg(char *msg, int len)
{
    int nStatus = 0;
    //RecieveMessage
    int nErrMsg = recv(m_socketKernel, msg, len, 0);
    if (nErrMsg < 0)
    {
        nStatus = 1;
        return nStatus;
    }
    return nStatus;
}
