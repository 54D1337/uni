#include <iostream>
#include <ctime>
#include <vector>
#include <thread>


#define NUM_OF_CORES 32
#define MAX_PRIME 99999999999999999999999999999L

void do_primes() {
    unsigned long i, num, primes = 0;
    for (num = 1; num <= MAX_PRIME; ++num) {
        for (i = 2; (i <= num) && (num % i != 0); ++i);
        if (i == num)
            ++primes;
    }
    std::cout << "Calculated " << primes << " primes." << std::endl;
}

int main() {
    time_t start, end;
    time_t run_time;
    std::vector<std::thread> threads;

    /* start of test */
    start = time(NULL);
    for (int i = 0; i < NUM_OF_CORES; ++i) {
        threads.emplace_back(do_primes);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    end = time(NULL);
    run_time = (end - start);
    std::cout << "This machine calculated all prime numbers under " << MAX_PRIME << " " << NUM_OF_CORES << " times in " << run_time << " seconds" << std::endl;
    return 0;
}
