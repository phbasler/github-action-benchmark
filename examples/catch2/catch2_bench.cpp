#include "fib.hpp"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <chrono>
#include <thread>

TEST_CASE("Fibonacci") {

  auto testfunc = [](int i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    return fib(i);
  };

  // now let's benchmark:
  BENCHMARK("Fibonacci 10") { return testfunc(10); };

  BENCHMARK("Fibonacci 20") { return fib(20); };
}
