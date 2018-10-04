//
// Created by pierreantoine on 04/10/18.
//

#ifndef CURLY_FUNICULAR_SSH_H
#define CURLY_FUNICULAR_SSH_H

#include <string>
#include <libssh/libssh.h>


namespace networking
{
    typedef struct ssh_options_struct
    {
        std::string host;
        int         verbosity;
        int         port;
        bool connected;
    } ssh_options;

    class ssh
    {
        ssh_session           session = nullptr;
        int                   rc      = 0;
        internal::ssh_options options{};

        void checkException() const;
    public:
        ssh();
        void connect();
        void authenticate();
        void disconnect();
        ~ssh();
    };

}

#endif //CURLY_FUNICULAR_SSH_H
