#pragma once

#include "util.h"

namespace util
{
  struct UTIL_API DeleteVisitor
  {
    template <class T>
    void operator()(T* e) const
    {
      delete e; // ע�� DLL �ڴ�ռ�����
    }
  };

  struct UTIL_API DeleteVisitor_Second
  {
    template <class T>
    void operator()(T& e) const
    {
      delete e.second;
    }
  };

  struct UTIL_API UpdateVisitor 
  {
    explicit UpdateVisitor(float delta) 
      : delta_(delta) 
    {

    }

    template <class T>
    void operator()(T* e) const
    {
      e->Update(delta_);
    }

    template <class T>
    void operator()(T& e) const 
    {
      e.Update(delta_);
    }

    float delta_;
  };

  struct UTIL_API UpdateVisitor_Second
  {
    explicit UpdateVisitor_Second(float& delta)
      : delta_(delta)
    {

    }

    template <class T>
    void Update(T& e) const
    {
      e.Update(delta_);
    }

    template <class T>
    void Update(T* e) const
    {
      e->Update(delta_);
    }

    template <class T>
    void operator()(T& pair) const
    {
      Update(pair.second);
    }

    float delta_;
  };
}