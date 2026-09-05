#ifndef PANS_SRC_LOGGER_LOG_RECORD_H
#define PANS_SRC_LOGGER_LOG_RECORD_H

#include <chrono>
#include <cstdint>
#include <string_view>
#include "pans/logger/log_level.h"

namespace pans::detail {

struct LogRecordView
{
    LogLevel::Level m_level = LogLevel::Level::LOG_LV_DEBUG;
    std::string_view m_loggerName; 
    std::string_view m_message; 
    std::chrono::system_clock::time_point m_timestamp;
    std::chrono::steady_clock::duration m_elapsed;
    std::uint64_t m_threadId = 0;
    std::uint64_t m_fiberId = 0;
    std::string_view m_threadName; 
    std::string_view m_fileName;
    std::uint32_t m_line = 0;
};

}

#endif // PANS_SRC_LOGGER_LOG_RECORD_H

