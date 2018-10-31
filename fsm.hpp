#pragma once

//libraries
#include <boost/asio.hpp>

class fsm {
   public:
    fsm(boost::asio::io_service& io);

   private:
    enum class state {
	start,
	end
    };

    void change_state(state s);

    void exit_start();
    void exit_end();

    void enter_start();
    void enter_exit();

    void start_timer();
    void handle_timer(const boost::system::error_code& e);
    void stop_timer();

    state _state;
    async_timer _timer;
};
