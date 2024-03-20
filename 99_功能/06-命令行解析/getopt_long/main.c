#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// 定义结构体数组，描述长选项
static struct option long_options[] =
    {
        {"verbose", no_argument, NULL, 'v'},
        {"output", required_argument, NULL, 'o'},
        {"help", no_argument, NULL, 'h'},
        {0, 0, 0, 0}};

void print_help()
{
    printf("Usage: program [-hv] [-o output_file]\n");
    printf("\t-v, --verbose\tVerbose mode\n");
    printf("\t-o, --output FILE\tOutput file path\n");
    printf("\t-h, --help\tShow this help message and exit\n");
}

int main(int argc, char *argv[])
{
    /* 注意避坑, optind变量是一个全局变量, 指向argv中下一个未被getopt处理的元素索引
     * 当代码中多次调用getopt_long时, 一定要注意手动置为 1 !!! */
    optind = 1;
    int option_index = 0;
    int verbose_flag = 0;
    char *output_file = NULL;
    char opt;
    while ((opt = getopt_long(argc, argv, "vo:h", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
        case 'v':
            verbose_flag = 1;
            break;
        case 'o':
            output_file = optarg;
            break;
        case 'h':
            print_help();
            return 0;
        case '?':
            fprintf(stderr, "Unknown option: %s\n", argv[optind - 1]);
            print_help();
            return 1;
        default:
            abort();
        }
    }

    // 检查输出文件是否已设置
    if (output_file == NULL)
    {
        fprintf(stderr, "Error: Output file must be specified with -o or --output.\n");
        return 1;
    }

    // 现在你可以根据verbose_flag和output_file的值执行相应的操作

    // getopt_long()处理完后，通过optind访问剩余的非选项参数
    for (int i = optind; i < argc; ++i)
    {
        printf("Non-option argument: %s\n", argv[i]);
    }

    printf("output: %s\n", output_file);
    return 0;
}