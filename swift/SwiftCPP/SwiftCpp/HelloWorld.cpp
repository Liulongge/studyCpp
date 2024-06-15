// C++文件

#include "HelloWorld.hpp"

#include <iostream>
#include <dirent.h>
#include <vector>
#include <string>

void listFilesInDirectory(const std::string& directoryPath, std::vector<std::string>& filesList) {
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(directoryPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // 排除"."和".."
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                filesList.push_back(ent->d_name);
            }
        }
        closedir(dir);
    } else {
        std::cerr << "Could not open directory: " << directoryPath << std::endl;
    }
}

std::string sayHello(int i, char *path)
{
    printf("[TEST] %d %s\n", i, path);
    return "Hello from CPP World! 你好呀";
}

std::int64_t setNSPath(std::string &path)
{
    std::vector<std::string> files;
    printf("[cpp] NS path: %s\n", path.c_str());
    listFilesInDirectory(path + "/Library", files);
    listFilesInDirectory(path + "/Documents", files);
    listFilesInDirectory(path + "/tmp", files);
    listFilesInDirectory(path + "/SystemData", files);

    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
    return 0;
}

std::int64_t HelloWorld::getRandomNumber()
{
    static int num = 0;
    return num ++;
};
