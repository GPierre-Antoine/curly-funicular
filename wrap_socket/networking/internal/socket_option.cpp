//
// Created by pierreantoine on 03/10/18.
//

#include "socket_option.h"

bool networking::internal::socket_option::operator<(const networking::internal::socket_option &other) const
{
    return option_type < other.option_type;
}
