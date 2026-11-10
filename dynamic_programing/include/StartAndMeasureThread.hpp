#include <thread>
#include <chrono>

template <typename Func>
long long start_and_measure(const char* thread_name, Func func, size_t n)
{
    std::cout << "[DEBUG]Starting thread:" << thread_name << std::endl;

    using namespace std::chrono;
    long long result = 0;
    long long elapsed_ns = 0;

    std::thread t([&result, &elapsed_ns, func, n]() {
        auto start = high_resolution_clock::now();
        result = func(n);
        auto end = high_resolution_clock::now();
        elapsed_ns = duration_cast<nanoseconds>(end - start).count();
    });

    t.join();
    std::cout <<"[DEBUG]" << thread_name << " finished in " << elapsed_ns << " ns, result: " << result << std::endl;

    return result;
}
