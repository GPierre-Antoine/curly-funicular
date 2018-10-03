//
// Created by pierreantoine on 03/10/18.
//

#include <algorithm>

#include "socket_factory.h"

networking::socket_factory::socket_factory()
{
    v4 = internal::sock_ipv4{};
    v6 = internal::sock_ipv6{};
}