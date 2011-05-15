#pragma once

#include <algorithm>
#include <map>
#include <utility>

namespace util
{
  // �� iterator ��������
  #define UTIL_FOREACH(i, container, type) \
    for( type::iterator i = (container).begin(); i != (container).end(); ++i )

  // �� const_iterator ��������
  #define UTIL_CONST_FOREACH(i, container, type) \
    for( type::const_iterator i = (container).begin(); i != (container).end(); ++i )

  // ������������Ԫ�أ��Ը���Ԫ�ص��� Functor::operator()
  template <class Container, class Functor>
  inline void Vist(Container& container, Functor& functor);

  // �ж������Ƿ����ĳ�� Key
  template <class Container, class Key>
  inline bool Contain(Container& container, Key& key);

  // ɾ��������ĳ����Ϊ Key ��Ԫ��
  template <class Container, class Key>
  inline bool Remove(Container& container, Key& key);

  // ����������һ����Ԫ��
  template <class Container, class ValueType>
  inline bool Insert(Container& container, ValueType& value);

  // TODO: ��ΰ����� Get �ϲ���

  template <class Key, class Value>
  inline Value& Get(std::map<Key, Value>& container, const Key& key);

  template <class Key, class Value>
  inline Value& Get(std::multimap<Key, Value>& container, const Key& key);

  #include "container.inl"
}