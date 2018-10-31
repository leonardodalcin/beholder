#pragma once

//libraries
#include <boost/asio.hpp>

/*
 Estados:
enter_state Start
exit Start
// Instanciar classes, preparar programa, iniciar ambiente

enter_state WaitOpen
exit Wait_Open
enter_state ClassifyCableTieLength
exit ClassifyCableTieLength
enter_state WaitEjection
exit WaitEjection
enter_state ClassifyEjection
exit ClassifyEjection
enter_state WaitOpen
exit Wait_Open
 */
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
