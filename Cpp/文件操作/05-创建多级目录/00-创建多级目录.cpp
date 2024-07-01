#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h> // For mkdir
#include <unistd.h>   // For access, chdir
#include <errno.h>    // For errno

bool dirExists(const std::string &path)
{
    struct stat info;
    if (stat(path.c_str(), &info) != 0)
    {
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;
}

bool createDirs(const std::string &path)
{
    std::string cur_path = "./";
    std::vector<std::string> dirs;
    size_t start = 0;
    size_t end = path.find("/");

    // 将完整路径以"/"为标志进行分割
    while(end != std::string::npos)
    {
        dirs.push_back(path.substr(start, end - start));
        start = end + 1;
        end = path.find("/", start);
    }
    dirs.push_back(path.substr(start, end));

    for(const auto &dir : dirs)
    {
        if(dir.empty() || dir == ".")
        {
            // 空路径或当前路径
            continue;
        }
        else if(dir == "..")
        {
            // 上一级路径
            size_t pos = cur_path.find_last_of("/");
            if(pos != std::string::npos)
            {
                cur_path = cur_path.substr(0, pos);
            }
            else
            {
                cur_path = "..";
            }
        }
        else
        {
            if(cur_path != ".")
            {
                cur_path += "/";
            }
            cur_path += dir;

            if(!dirExists(cur_path))
            {
                if(mkdir(cur_path.c_str(), 0755) != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    createDirs("./some/path/..//to/my/directory/");
    return 0;
}