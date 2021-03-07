#include "logger.h"
#include"Utilities.h"

const string Logger::m_sFileName = "Logger.log";
Logger* Logger::m_pThis = NULL;
ofstream Logger::m_Logfile;
bool Logger::m_LogToConsole = true;
bool Logger::m_LogToFile = true;

Logger::Logger()
{
}

Logger* Logger::GetLogger() {
    if (m_pThis == NULL) {
        m_pThis = new Logger();

        if (m_LogToFile) {
            m_Logfile.open(m_sFileName.c_str(), ios::out);
        }
    }
    return m_pThis;
}

void Logger::Log(const char* format, ...)
{
    char* sMessage = NULL;
    int nLength = 0;
    va_list args;
    va_start(args, format);
    //  Return the number of characters in the string referenced the list of arguments.
    // _vscprintf doesn't count terminating '\0' (that's why +1)
    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    vsprintf_s(sMessage, nLength, format, args);
    //vsprintf(sMessage, format, args);

    if (m_LogToFile) {
        m_Logfile << Util::CurrentDateTime() << ":\t";
        m_Logfile << sMessage << "\n";
    }

    if (m_LogToConsole) {
        cout << Util::CurrentDateTime() << ":\t";
        cout << sMessage << "\n";
    }

    va_end(args);

    delete[] sMessage;
}

void Logger::Log(const string& sMessage)
{
    if (m_LogToFile) {
        m_Logfile << Util::CurrentDateTime() << ":\t";
        m_Logfile << sMessage << "\n";
    }

    if (m_LogToConsole) {
        cout << Util::CurrentDateTime() << ":\t";
        cout << sMessage << "\n";
    }

}

Logger& Logger::operator<<(const string& sMessage)
{
    if (m_LogToFile) {
        m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
        m_Logfile << sMessage << "\n";
    }

    if (m_LogToConsole) {
        cout << Util::CurrentDateTime() << ":\t";
        cout << sMessage << "\n";
    }

    return *this;
}