// local packages
#include "fsm.hpp"
// libraries
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// language
#include <iostream>

int main(int argc, char *argv[]) {
    boost::asio::io_service io;
    fsm(io);
}
