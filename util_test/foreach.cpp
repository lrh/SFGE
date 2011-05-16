#include <numeric>
#include <vector>

#include <util/container.h>

#define TEST_SUITE UtilContainer

TEST(Foreach)
{
  // ���� UTIL_FOREACH �Ƿ��ܹ�����һ������

  std::vector<int> vec;
  vec.resize(99, 1); // 99 ��ֵΪ 1 ��Ԫ��

  // ͳ��ִ�еĴ������ۼӸ���Ԫ��ֵ

  int cnt = 0;
  int sum = 0;
  UTIL_FOREACH(i, vec, std::vector<int>)
  {
    sum += *i;
    ++cnt;
  }

  CHECK(cnt == vec.size());
  CHECK(sum == std::accumulate(vec.begin(), vec.end(), 0));
}

TEST(ConstForeach)
{
  // ���� UTIL_CONST_FOREACH �Ƿ��ܹ�����һ������

  std::vector<int> vec;
  vec.resize(99, 1); // 99 ��ֵΪ 1 ��Ԫ��

  // ͳ��ִ�еĴ������ۼӸ���Ԫ��ֵ

  int cnt = 0;
  int sum = 0;
  UTIL_CONST_FOREACH(i, vec, std::vector<int>)
  {
    sum += *i;
    ++cnt;
  }

  CHECK(cnt == vec.size());
  CHECK(sum == std::accumulate(vec.begin(), vec.end(), 0));
}