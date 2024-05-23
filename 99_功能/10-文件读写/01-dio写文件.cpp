#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // 包含open、close等函数
#include <unistd.h> // 包含write函数
#include <string.h> // 包含strlen函数

int main()
{
    // 申请内存与size对齐的地址
    void *ptr;
    size_t alignment = 4096; // 假设你想要16字节对齐
    size_t size = alignment;    // 申请的内存大小

    int result = posix_memalign(&ptr, alignment, size);
    if (result != 0)
    {
        fprintf(stderr, "posix_memalign failed: %s\n", strerror(result));
        return EXIT_FAILURE;
    }

    // 打开文件以写入数据，如果文件不存在则创建它
    // 使用O_WRONLY | O_CREAT | O_TRUNC标志：O_WRONLY是写入模式，O_CREAT如果文件不存在则创建，O_TRUNC清空文件内容
    int fd = open("./output.txt", O_WRONLY | O_CREAT | O_TRUNC | O_DIRECT, 0666); // 0666是文件权限
    if (fd == -1)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 将数据写入文件
    ssize_t bytesWritten = write(fd, ptr, size);
    if (bytesWritten == -1)
    {
        perror("Error writing to file");
        close(fd); // 错误处理，确保关闭文件描述符
        return EXIT_FAILURE;
    }

    // 检查是否所有数据都已成功写入
    if (bytesWritten != size)
    {
        fprintf(stderr, "Failed to write all data to file\n");
        close(fd);
        return EXIT_FAILURE;
    }

    fsync(fd);
    // 关闭文件
    if (close(fd) == -1)
    {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    printf("Data written successfully to output.txt\n");
    return EXIT_SUCCESS;
}