#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <memory>
#include <mutex>
#include <sstream>
#include <string_view>
#include <vector>

#include "pans/utils/system_utils.h"

namespace pans {

std::chrono::steady_clock::duration GetElapsedTime() noexcept
{
    static const auto START_TIME = std::chrono::steady_clock::now();
    return std::chrono::steady_clock::now() - START_TIME;
}

std::uint64_t GetFiberId() noexcept
{
    return 0;
}

}
