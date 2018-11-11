#include "networking_error.h"

networking::networking_error::networking_error(const std::string &s) : std::runtime_error(s) {

}