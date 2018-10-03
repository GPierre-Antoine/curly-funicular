//
// Created by pierreantoine on 03/10/18.
//

#ifndef CURLY_FUNICULAR_SOCKET_OPTION_H
#define CURLY_FUNICULAR_SOCKET_OPTION_H


#include <sys/socket.h>
#include <netinet/in.h>


namespace networking
{
    namespace internal
    {


        typedef struct sockaddr_in  sock_ipv4;
        typedef struct sockaddr_in6 sock_ipv6;


        enum socket_domain
        {
            file = AF_LOCAL, ipv4 = AF_INET, ipv6 = AF_INET6
        };

        enum socket_type
        {
            tcp = SOCK_STREAM, udp = SOCK_DGRAM, raw = SOCK_RAW, };

        enum option_type
        {
              debug         = SO_DEBUG
            , reuse_address = SO_REUSEADDR
            , reuse_port    = SO_REUSEPORT
            , reuse_both    = SO_REUSEADDR | SO_REUSEPORT
            , keepalive     = SO_KEEPALIVE
            , dontroute     = SO_DONTROUTE
            , linger        = SO_LINGER
            , broadcast     = SO_BROADCAST
            , };

        class socket_option
        {
            int option_type;
            int value;
        public:
            bool operator<(const socket_option &other) const;
        };
    }
}


#endif //CURLY_FUNICULAR_SOCKET_OPTION_H
