// local packages
#include "camera.hpp"
#include "classifier.hpp"
#include "fsm.hpp"
#include "io.hpp"
// libraries
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char *argv[]) {
    boost::asio::io_service asio_io;
    camera cam();
    classifier cla();
    io ipop();

    fsm fsm_app(asio_io, cam, cla, ipop);
}
