#include "OLog.h"
#include <time.h>

namespace library
{
    bool OLog::sUseFiles = false;
    bool OLog::sFilesOpen = false;

    OLog::OLog(const std::string& moduleName)
    {
        mModuleName = moduleName;
    }

    OLog::~OLog() {}

    void OLog::writeLine(const std::string& str)
    {
        time_t rawtime;
        struct tm* timeinfo;
        char timestamp[32];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(timestamp, 32, "%X", timeinfo);

        fprintf(stdout, "[%s] (%s) %s\n", timestamp, mModuleName.c_str(), str.c_str());
    }

    void OLog::errorLine(const std::string& str)
    {
        time_t rawtime;
        struct tm* timeinfo;
        char timestamp[32];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(timestamp, 32, "%X", timeinfo);

        fprintf(stderr, "[%s] (%s) %s\n", timestamp, mModuleName.c_str(), str.c_str());
    }

    void OLog::open(bool useFiles)
    {
        if(sFilesOpen)
            return;
        sUseFiles = useFiles;
        if(sUseFiles)
        {
            freopen("output.log", "a", stdout);
            freopen("error.log", "a", stderr);
            sFilesOpen = true;
        }
    }

    void OLog::close()
    {
        if(sUseFiles)
        {
            fclose(stdout);
            fclose(stderr);
        }
        sFilesOpen = false;
    }
}