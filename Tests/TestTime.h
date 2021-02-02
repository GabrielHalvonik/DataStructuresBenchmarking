#pragma once

#include <chrono>

class TestTime {
public:
	template <typename T, typename...Args>
	static std::chrono::nanoseconds testTime(T(*function)(Args...), Args...args);

private:
	TestTime() = default;
	static std::chrono::time_point<std::chrono::high_resolution_clock> start;
	static std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

template<typename T, typename...Args>
std::chrono::nanoseconds TestTime::testTime(T(*function)(Args...), Args...args) {
	start = std::chrono::high_resolution_clock::now();
	function(args...);
	end = std::chrono::high_resolution_clock::now();

	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}
