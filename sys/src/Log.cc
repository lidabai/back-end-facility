#include "Log.h"
#include "Logger.h"

#if LOG_ENABLE

#define LOG_FILE_ALL     "slog_all.log"
#define LOG_FILE_DEBUG   "slog_debug.log"
#define LOG_FILE_INFO    "slog_info.log"
#define LOG_FILE_VERB    "slog_verb.log"
#define LOG_FILE_WARN    "slog_warn.log"
#define LOG_FILE_ERROR   "slog_error.log"
#define LOG_FILE_FATAL   "slog_fatal.log"

void InitLogger()
{
    Logger::RunLogging();
}

void slog_all(const char* format, va_list arg)
{
    static Logger gs_log_all(LOG_FILE_ALL);
    gs_log_all.Log(format, arg);
}

void slog_debug(const char* format, va_list arg)
{
    static Logger gs_log_debug(LOG_FILE_DEBUG);
    gs_log_debug.Log(format, arg);
}

void slog_info(const char* format, va_list arg)
{
    static Logger gs_log_info(LOG_FILE_INFO);
    gs_log_info.Log(format, arg);
}

void slog_verb(const char* format, va_list arg)
{
    static Logger gs_log_verb(LOG_FILE_VERB);
    gs_log_verb.Log(format, arg);
}

void slog_warn(const char* format, va_list arg)
{
    static Logger gs_log_warn(LOG_FILE_WARN);
    gs_log_warn.Log(format, arg);
}

void slog_error(const char* format, va_list arg)
{
    static Logger gs_log_error(LOG_FILE_ERROR);
    gs_log_error.Log(format, arg);
}

void slog_fatal(const char* format, va_list arg)
{
    static Logger gs_log_fatal(LOG_FILE_FATAL);
    gs_log_fatal.Log(format, arg);
}

// TODO specify log level to filter log
// the smaller the value is the the fewer log get filterred.

static volatile int g_logLevel = LOG_ERROR;

int slog_level()
{
    return g_logLevel;
}

void SetLogLevel(int level)
{
   g_logLevel = level;
}

#endif

