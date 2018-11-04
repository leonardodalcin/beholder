#include "async_timer.hpp"

#if ENABLE_INSTRUMENTED_TIMER

#include <boost/stacktrace.hpp>

async_timer::async_timer(io_service& io) : _timer(io) {}

std::size_t async_timer::expires_from_now(duration_type const& t) {
    return _timer.expires_from_now(t);
}

void async_timer::cancel() { _timer.cancel(); }
#endif
