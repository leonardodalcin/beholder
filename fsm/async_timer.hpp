#pragma once
#include <boost/asio/deadline_timer.hpp>

#ifndef ENABLE_INSTRUMENTED_TIMER
#define ENABLE_INSTRUMENTED_TIMER 0
#endif

using io_service = boost::asio::io_service;

#if !ENABLE_INSTRUMENTED_TIMER
using async_timer = boost::asio::deadline_timer;
#else

#include <boost/date_time/posix_time/posix_time.hpp>

class async_timer {
   public:
    using deadline_timer = boost::asio::deadline_timer;
    using duration_type = deadline_timer::duration_type;

    async_timer(io_service& io);

    std::size_t expires_from_now(duration_type const& t);
    void cancel();

    template <typename... Args>
    void async_wait(Args&&... args);

   private:
    deadline_timer _timer;
};

template <typename... Args>
void async_timer::async_wait(Args&&... args) {
    _timer.async_wait(std::forward<Args>(args)...);
}

#endif
