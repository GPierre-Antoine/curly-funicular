//
// Created by pierreantoine on 03/10/18.
//

#ifdef WIN32
#include <windows.h>
#include <winsock2.h>

#else // UNIX

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <algorithm>

#endif

#include "socket.h"

void networking::socket::close()
{
#ifdef WIN32
    ::closesocket(sock);
#else
    ::close(socket_file_descriptor);
#endif
}
