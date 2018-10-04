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

void networking::ssh::connect(const std::string &hostname)
{
    set_ssh_options(hostname);
    actually_connect_ssh();
    authenticate();
}

void networking::ssh::actually_connect_ssh()
{
    this->rc = ssh_connect(this->session);
    checkException();
    options.connected = true;
}

void networking::ssh::set_ssh_options(const std::string &hostname)
{
    options.host = hostname;
    ssh_options_set(this->session, SSH_OPTIONS_HOST, this->options.host.c_str());
    ssh_options_set(this->session, SSH_OPTIONS_LOG_VERBOSITY, &this->options.verbosity);
    ssh_options_set(this->session, SSH_OPTIONS_PORT, &this->options.port);
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
    options.authenticated = true;
}
