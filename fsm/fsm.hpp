#pragma once
// local packages
#include "camera.hpp"
#include "classifier.hpp"
#include "io.hpp"
//libraries
#include <boost/asio.hpp>

class fsm {
   public:
    fsm(boost::asio::io_service& io,
	camera& cam,
	classifier& cla,
	io& ipop);

   private:
    enum class state {
	start,
	wait_open,
	classify_cable_tie_length,
	wait_ejection,
	classify_ejection,
	end
    };

    void change_state(state s);

    void exit_start();
    void exit_wait_open();
    void exit_classify_cable_tie_length();
    void exit_wait_ejection();
    void exit_classify_ejection();
    void exit_end();

    void enter_start();
    void enter_wait_open();
    void enter_classify_cable_tie_length();
    void enter_wait_ejection();
    void enter_classify_ejection();
    void enter_end();

    void start_timer();
    void handle_timer(const boost::system::error_code& e);
    void stop_timer();

    state _state;
    async_timer _timer;
    camera& _camera;
    classifier& _classifier;
    io& _io;
};
