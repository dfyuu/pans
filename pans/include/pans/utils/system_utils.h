#ifndef PANS_INCLUDE_PANS_UTILS_SYSTEM_UTILS_H
#define PANS_INCLUDE_PANS_UTILS_SYSTEM_UTILS_H

#include <chrono>
#include <cstdint>

#include "pans/export.h"

namespace pans {

[[nodiscard]] PANS_API std::chrono::steady_clock::duration GetElapsedTime() noexcept;

[[nodiscard]] PANS_API std::uint64_t GetFiberId() noexcept;

} // namespace pans

#endif // PANS_INCLUDE_PANS_UTILS_SYSTEM_UTILS_H

