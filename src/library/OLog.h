#ifndef __O_LOG_INCLUDED__
#define __O_LOG_INCLUDED__
#include <stdio.h>
#include <string>

namespace library
{
    class OLog
    {
    private:
        std::string mModuleName;
        static bool sUseFiles;
        static bool sFilesOpen;
    public:
        OLog(const std::string& moduleName);
        ~OLog();

        void writeLine(const std::string& str);
        void errorLine(const std::string& str);

        static void open(bool useFiles = false);
        static void close();

    };
}

#endif