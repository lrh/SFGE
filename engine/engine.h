#pragma once

// ʹ�ö�̬��汾
// engine ģ���趨�� ENGINE_DYMAMIC �� _USRDLL
// ʹ�� engine ��ģ����Ҫ���� ENGINE_DYMAMIC
//
// ʹ�þ�̬��汾
// engine ģ���ʹ�� engine ��ģ�鶼���ܶ��� ENGINE_DYMAMIC

#ifdef ENGINE_DYMAMIC
  #ifdef _USRDLL
    #define ENGINE_API __declspec(dllexport)
  #else
    #define ENGINE_API __declspec(dllimport)
  #endif
#else
  #define ENGINE_API 
#endif
