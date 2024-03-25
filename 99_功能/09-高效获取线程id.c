#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// pthread_self()函数调用不会引起上下文切换。
// 上下文切换通常发生在操作系统为了调度不同线程或进程而暂停当前执行线程，保存其上下文（如寄存器状态、内存映射等），
// 然后恢复另一个线程或进程的上下文以便继续执行的过程。上下文切换是一种相对昂贵的操作，因为它涉及到CPU状态的保存和恢复，以及可能的缓存失效等开销。

// 相比之下，pthread_self()函数是纯粹的用户空间操作，其目的是获取当前正在执行线程的标识符。
// 这个标识符通常由线程库在创建线程时初始化，并在每个线程的内部数据结构中维护。当调用`pthread_self()`时，它仅需访问线程本地存储（TLS）或其他线程相关的内部数据结构来返回这个预先已知的标识符。这个过程不涉及操作系统内核，不需要任何系统调用，也不涉及线程或进程状态的切换。

// 因此，pthread_self()函数调用与普通函数调用在性能上没有显著差异，都是在同一线程上下文中快速执行的用户空间操作。
// 它不会触发上下文切换，也不会带来额外的系统开销，可以认为是几乎瞬时完成的。
// 在多线程编程中，频繁地调用pthread_self()以获取当前线程ID通常不会成为性能瓶颈，可以放心在需要时使用。

// 定义线程处理函数
void *thread_function(void *arg) {
    pthread_t tid = pthread_self();

    printf("Hello from thread %d\n", tid);
    return NULL;
}

int main() {
    const int num_threads = 3; // 创建3个线程

    pthread_t threads[num_threads]; // 用于存储线程ID的数组

    for (int i = 0; i < num_threads; ++i) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // 等待所有线程完成
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");

    return EXIT_SUCCESS;
}
