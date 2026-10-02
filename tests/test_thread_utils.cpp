#include <cassert>
#include <string>
#include <thread>
#include <iostream>

#if defined(_WIN32)
#include <pthread.h>
#endif

#include "pans/utils/thread_utils.h"

int main()
{
    std::cout << "1: main thread id:   " << pans::GetThreadId() << std::endl;
    std::cout << "2: main thread name: " << pans::GetThreadName() << std::endl;
    sleep(30);
    pans::SetThreadName("main_thread");
    std::cout << "3: main thread name: " << pans::GetThreadName() << std::endl;
    sleep(10);
    pans::SetThreadName("中文线程名");
    std::cout << "4: main thread name: " << pans::GetThreadName() << std::endl;

    std::thread worker([]() {
        std::cout << "6: main thread id:  " << pans::GetThreadId() << std::endl;
        std::cout << "7: son thread name: " << pans::GetThreadName() << std::endl;
        sleep(10);
        pans::SetThreadName("son-thread-long-name");
        std::cout << "8: son thread name: " << pans::GetThreadName() << std::endl;
        sleep(10);
        pans::SetThreadName("");
        std::cout << "9: son thread name: " << pans::GetThreadName() << std::endl;
    });
    worker.join();

    return 0;
}

