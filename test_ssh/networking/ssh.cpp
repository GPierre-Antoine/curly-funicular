//
// Created by pierreantoine on 04/10/18.
//

#include "ssh.h"
#include "../../networking/networking_error.h"

using networking::networking_error;


void networking::ssh::checkException() const
{
    switch (rc)
    {
        case SSH_OK:return;
        default:throw networking_error(ssh_get_error(session));
    }
}


networking::ssh::ssh()
{
    session = ssh_new();
    if (session == nullptr)
    {
        throw networking_error("Could not initiate SSH session");
    }
}

void networking::ssh::connect()
{
    ssh_options_set(session, SSH_OPTIONS_HOST, options.host.c_str());
    ssh_options_set(session, SSH_OPTIONS_LOG_VERBOSITY, &options.verbosity);
    ssh_options_set(session, SSH_OPTIONS_PORT, &options.port);
    rc = ssh_connect(session);
    checkException();
    options.connected = true;
}


networking::ssh::~ssh()
{
    disconnect();
    ssh_free(session);
}

void networking::ssh::disconnect()
{
    if (options.connected)
    {
        ssh_disconnect(session);
        options.connected = false;
    }
}

void networking::ssh::authenticate()
{

}
