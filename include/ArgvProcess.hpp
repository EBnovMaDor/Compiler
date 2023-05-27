#pragma once
#include <vector>
#include <map>
#include <string>

class ArgvProcess
{
    std::vector<std::string> argv;
    std::map<std::string, std::string> argm;

public:
    // constructor
    ArgvProcess() {}
    ArgvProcess(int argc, const char *argv[])
    {
        // argv[0] = "./complier"
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == '-')
            {
                std::string flag(&argv[i][1]);
                if (i + 1 < argc && argv[i + 1][0] != '-')
                {
                    argm[flag] = argv[i + 1];
                    i++;
                }
                else
                {
                    argm[flag] = "";
                }
            }
        }
    }

    bool findName(std::string flag, std::string &fileName)
    {
        auto iter = argm.find(flag);
        if (iter == argm.end())
            return false;
        fileName = iter->second;
        return true;
    }
};