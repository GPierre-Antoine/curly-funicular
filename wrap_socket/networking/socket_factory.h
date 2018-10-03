//
// Created by pierreantoine on 03/10/18.
//

#ifndef CURLY_FUNICULAR_SOCKET_FACTORY_H
#define CURLY_FUNICULAR_SOCKET_FACTORY_H

#include <memory>
#include <set>
#include <sys/socket.h>

#include "socket.h"
#include "internal/socket_option.h"

namespace networking
{


    class socket_factory
    {
    private:
        internal::sock_ipv4               v4{};
        internal::sock_ipv6               v6{};
        internal::socket_domain           domain{internal::socket_domain::ipv4};
        internal::socket_type             type{internal::socket_type::tcp};
        std::set<internal::socket_option> options;
    public:
        socket_factory();
    };
}


#endif //CURLY_FUNICULAR_SOCKET_FACTORY_H
