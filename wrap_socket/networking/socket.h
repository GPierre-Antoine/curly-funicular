//
// Created by pierreantoine on 03/10/18.
//

#ifndef CURLY_FUNICULAR_BROAD_SOCKET_H
#define CURLY_FUNICULAR_BROAD_SOCKET_H


namespace networking
{
    class socket
    {
        int socket_file_descriptor = 0;
    public:
        socket() = default;

        socket(const socket &) = delete;

        void close();
    };

}

#endif //CURLY_FUNICULAR_BROAD_SOCKET_H
