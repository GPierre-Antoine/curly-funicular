//
// Created by pierreantoine on 03/10/18.
//

#ifndef CURLY_FUNICULAR_NETWORKING_ERROR_H
#define CURLY_FUNICULAR_NETWORKING_ERROR_H

#include <stdexcept>

namespace networking
{
    class networking_error : public std::runtime_error
    {
    public:
        networking_error(const std::string &);
    };
}

#endif //CURLY_FUNICULAR_NETWORKING_ERROR_H
