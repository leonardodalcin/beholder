#include "fms.hpp"

fms::fms(boost::asio::io_service& asio_io,
	 camera& cam,
	 classifier& cla,
	 io& ipop) : _timer(asio_io),
		     _camera(cam),
		     _classifier(cla),
		     _io(ipop),
		     _state(state::end) {
    change_state(state::start);
}

void fsm::change_state(state new_state) {
    std::cout << "Changing state from \"" << _state << "\" to \"" << new_state << '\"';

    // On State Exit
    switch (_state) {
	case state::start:
	    exit_start();
	    break;
	case state::wait_open:
	    exit_wait_open();
	    break;
	case state::classify_cable_tie_length:
	    exit_classify_cable_tie_length();
	    break;
	case state::wait_ejection:
	    exit_wait_ejection();
	    break;
	case state::classify_ejection:
	    exit_classify_ejection();
	    break;
	case state::end:
	    exit_end();
	    break;
    }

    auto old_state = _state;
    _state = new_state;

    // On State Entry
    switch (_state) {
	case state::start:
	    enter_start();
	    break;
	case state::wait_open:
	    enter_wait_open();
	    break;
	case state::classify_cable_tie_length:
	    enter_classify_cable_tie_length();
	    break;
	case state::wait_ejection:
	    enter_wait_ejection();
	    break;
	case state::classify_ejection:
	    enter_classify_ejection();
	    break;
	case state::end:
	    enter_end();
	    break;
    }
}

// exit
void fsm::exit_start() {
}

void fsm::exit_wait_open() {
}

void fsm::exit_classify_cable_tie_length() {
}

void fsm::exit_wait_ejection() {
}

void fsm::exit_classify_ejection() {
}

void fsm::exit_end() {
    // preparar sistema
}

// enter
void fsm::enter_start() {
    // preparar sistema
    change_state(state::wait_open);
}

void fsm::enter_wait_open() {
    change_state(state::classify_cable_tie_length);
}

void fsm::enter_classify_cable_tie_length() {
    change_state(state::wait_ejection);
}

void fsm::enter_wait_ejection() {
    change_state(state::classify_ejection);
}

void fsm::enter_classify_ejection() {
    change_state(state::wait_open);
}

void fsm::enter_end() {
    // finalizar pendencias
}
