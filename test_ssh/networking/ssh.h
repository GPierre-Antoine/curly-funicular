//
// Created by pierreantoine on 04/10/18.
//

#ifndef CURLY_FUNICULAR_SSH_H
#define CURLY_FUNICULAR_SSH_H

#include <string>
#include <libssh/libssh.h>
#include "internal/ssh_options.h"


namespace networking
{
    class ssh
    {
        ssh_session           session = nullptr;
        int                   rc      = 0;
        internal::ssh_options options{};

        void checkException() const;
        void set_ssh_options(const std::string & hostname);
        void actually_connect_ssh();
        void authenticate();
    public:
        ssh();

        void connect(const std::string & hostname);

        void disconnect();

        ~ssh();
    };

}

#endif //CURLY_FUNICULAR_SSH_H
