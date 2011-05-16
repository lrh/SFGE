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

  // ����Լ����
  // Ԫ�ص�����Ϊ Container::value_type
  // Ԫ�ؼ�ֵ������Ϊ Container::key_type ���� Container::value_type::first_type
  // Ԫ��ӳ��ֵ������Ϊ Container::mapped_type ���� Container::value_type::second_type

  // ������������Ԫ�أ��Ը���Ԫ�ص��� Functor::operator()
  template <class Container, class Functor>
  inline void Vist(Container& container, Functor& functor);

  // �ж������Ƿ����һ���� key Ϊ��ֵ��Ԫ��
  template <class Container>
  inline bool Contain(Container& container, const typename Container::key_type& key);

  // ɾ�������ļ�ֵΪ key ��Ԫ��
  template <class Container>
  inline bool Remove(Container& container, const typename Container::key_type& key);

  // ����������һ����Ԫ��
  template <class Container>
  inline bool Insert(Container& container, const typename Container::value_type& value);

  // ��ȡ��һ���� key Ϊ��ֵ��Ԫ�ص�ӳ��ֵ
  template <class Container>
  inline typename Container::mapped_type& Get(
    Container& container, const typename Container::key_type& key);

  #include "container.inl"
}