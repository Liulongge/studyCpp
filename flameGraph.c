// step 1: 采集数据
// sudo perf record -F 99 -p 22645 -g -- sleep 30 
// OR
// sudo perf_4.9 record -F 99 -p 2102 -g -- sleep 30
// perf record表示记录，-F 99表示每秒99次，-p 13204是进程号，即对哪个进程进行分析，-g表示记录调用栈，sleep 30则是持续30秒

// step 2：转换为 svg图片
// sudo perf script | ./stackcollapse-perf.pl | ./flamegraph.pl > out.svg

#include <stdio.h>
 
int func(int a, int b)
{
  return a / b;
}
 
int main()
{
  while(1)
  {
    int x = 10;
    int y = 2;
    printf("%d / %d = %d\n", x, y, func(x, y));
    usleep(200*1000);
  }
  return 0;
}