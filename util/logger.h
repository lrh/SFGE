#pragma once

// ���ԣ�
// 1 ��ͬʱд�����̨���ļ�
// 2 �������������
// 3 �̰߳�ȫ��������Ҫ��// δ������

// ע�⣺��ǰ������ͬһ���߳�ʹ�ã�����С�ľͳ���

#include <fstream>
#include <sstream>

#include "i_get_instance.h"

namespace util
{
  class Logger : public util::IGetInstance<Logger>
  {
  public:
    enum LogMode
    {
      LM_FILE = 1 << 0,
      LM_STDERR = 1 << 1,

      LM_ALL = 0xffffffff,
    };

    enum Loglevel
    {
      LL_INFO = 1,
      LL_WARNING = 2,
      LL_ERROR = 3,

      LL_NONE = 0x7fffffff,
    };

    Logger();

    void Log(const std::string& text, int loglevel = LL_INFO);

    void LogBegin() { logbuf_.str(""); }
    template <class T> 
    Logger& operator<<(const T& val);
    void LogEnd(int loglevel = LL_INFO) { Log(logbuf_.str(), loglevel); logbuf_.str(""); }

    int GetLogMode() const { return logMode_; }
    int GetLoglevel() const { return loglevel_; }
    std::string GetLogfile() const { return logfile_; }

    void SetLogMode(int val);
    void SetLoglevel(int val);
    void SetLogfile(const std::string& val);

  private:
    int logMode_;
    int loglevel_;
    std::string logfile_;
    std::ofstream outstream_;
    std::stringstream logbuf_;
  };

  template <class T>
  Logger& Logger::operator<<(const T& val)
  {
    logbuf_ << val;
    return *this;
  }
}

