#include <chrono>
#include <future>
#include <iostream>
#include <thread>

double function(const double var) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return var;
}

int main(int argc, char** agrv) {
    // Compute f1 + f2 + f3 + f4 using one thread.
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    
    double result = function(1.) + function(2.) + function(3.) + function(4.);
    
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    double time_cost = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000.;
    std::cout << std::fixed << "Sigal thread result: " << result << " and time cost: " << time_cost << std::endl;

    // Compute f1 + f2 + f3 + f4 using four threads.
    t1 = std::chrono::steady_clock::now();
    
    std::future<double> f1(std::async(std::launch::async, function, 1.));
    auto f2 = std::async(std::launch::async, function, 2.);
    auto f3 = std::async(std::launch::async, function, 3.);
    result = function(4.) + f1.get() + f2.get() + f3.get();

    t2 = std::chrono::steady_clock::now();
    time_cost = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000.;
    std::cout << std::fixed << "Multi-threads result: " << result << " and time cost: " << time_cost << std::endl;

    return 1;
}
