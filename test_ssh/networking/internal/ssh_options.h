//
// Created by pierreantoine on 04/10/18.
//

#ifndef CURLY_FUNICULAR_SSH_OPTIONS_H
#define CURLY_FUNICULAR_SSH_OPTIONS_H

#include <string>

namespace networking
{
    namespace internal
    {
        typedef struct ssh_options_struct
        {
            std::string host;
            int         verbosity;
            int         port;
            bool        connected     = false;
            bool        authenticated = false;
        } ssh_options;
    }
}

#endif //CURLY_FUNICULAR_SSH_OPTIONS_H
