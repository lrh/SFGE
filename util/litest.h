#pragma once

// home.zhenliang@gmail.com 

// ʵ��ԭ��
//
// TestUnit Ϊÿ�����Ե�Ԫ�Ļ���
// ���� TEST ���ݴ�����������ɶ�Ӧ�����ࣨTestUnit_SuiteName_TestName������ Run ����
// TEST ��������֮������һ��ȫ�ֱ�����kTestUnit_SuiteName_TestName��
// ����Ϊÿ�� TestUnit �ڴ�����ʱ���Զ����� Run ����
// ��ÿ�� TestUnit �����Լ��������������Զ����в��ԣ��ﵽ�Զ����Ե�Ŀ��

#include <sstream>
#include <iostream>

namespace util
{
  class TestUnit
  {
  public:
    TestUnit(const std::string& suite, const std::string& name);
    virtual void Run() = 0;

  protected:
    std::string suite_;
    std::string name_;
  };

  template <class T1, class T2>
  void Fail(const std::string& suite, const std::string& test, const std::string& file, long line,
    const T1& expected, const T2& actual);
  void Fail(const std::string& suite, const std::string& test, const std::string& file, long line,
    const std::string& msg);

  #include "litest.inl"
}
