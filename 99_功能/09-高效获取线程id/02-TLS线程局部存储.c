#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// 可以利用TLS设置获取进程内线程唯一标识

// 自定义线程局部数据结构
typedef struct
{
    int thread_id;
    int thread_local_counter;
} ThreadLocalData;

// TLS键
static pthread_key_t tls_key;

// 销毁TLS数据的回调函数
void destroy_thread_local_data(void *data)
{
    free((ThreadLocalData *)data);
}

// 初始化TLS键
void init_tls_key()
{
    if (pthread_key_create(&tls_key, destroy_thread_local_data) != 0)
    {
        perror("pthread_key_create");
        exit(EXIT_FAILURE);
    }
}

// 设置线程的自定义数据
void set_thread_data(int thread_id)
{
    ThreadLocalData *data = (ThreadLocalData *)malloc(sizeof(ThreadLocalData));
    if (data == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    data->thread_id = thread_id;
    data->thread_local_counter = 0;

    pthread_setspecific(tls_key, data);
}

// 获取当前线程的自定义数据
ThreadLocalData *get_thread_data()
{
    return (ThreadLocalData *)pthread_getspecific(tls_key);
}

// 线程任务函数
void *thread_task(void *arg)
{
    int thread_num = *(int *)arg;

    // 设置当前线程的自定义数据
    set_thread_data(thread_num);

    for (int i = 0; i < 10; ++i)
    {
        ThreadLocalData *data = get_thread_data();
        data->thread_local_counter++;

        printf("Thread %d: Local counter = %d\n", data->thread_id, data->thread_local_counter);
    }

    return NULL;
}

int main()
{
    const int num_threads = 3;

    // 初始化TLS键
    init_tls_key();

    pthread_t threads[num_threads];
    int thread_args[num_threads];

    for (int i = 0; i < num_threads; ++i)
    {
        thread_args[i] = i + 1;

        if (pthread_create(&threads[i], NULL, thread_task, &thread_args[i]) != 0)
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_threads; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");

    return 0;
}