#pragma once

namespace util
{

// ʹ�ö�̬��汾
// util ģ���趨�� UTIL_DYNAMIC �� _USRDLL
// ʹ�� util ��ģ����Ҫ���� UTIL_DYNAMIC
//
// ʹ�þ�̬��汾
// util ģ���ʹ�� util ��ģ�鶼���ܶ��� UTIL_DYNAMIC

#ifdef UTIL_DYNAMIC 
  #ifdef _USRDLL
    #define UTIL_API __declspec(dllexport)
  #else
    #define UTIL_API __declspec(dllimport)
  #endif
#else
  #define UTIL_API
#endif

}
