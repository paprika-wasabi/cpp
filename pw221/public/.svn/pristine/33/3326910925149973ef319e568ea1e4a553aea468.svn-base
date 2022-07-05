// Copyright 2022, Univer_sity of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <chrono>
#include <ostream>

// A simple timer class.
class Timer {
 public:
  // Start upon construction.
  Timer() { start(); }
  // Reset start time to now.
  void start() { startTime_ = std::chrono::steady_clock::now(); }
  // Get time sind last start.
  int msecPassed() const {
    auto time =  std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>
      (time - startTime_).count();
  }
 private:
  // The time when the timer was started.
  std::chrono::time_point<std::chrono::steady_clock> startTime_;
};

// Define how to show a timer object in an output stream like std::cout.
std::ostream& operator<<(std::ostream& os, const Timer& timer);
