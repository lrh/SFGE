#include "charset_mgr.h"

#include <fstream>

#include <util\container.h>
#include <util\string.h>

bool CharsetManager::AddCharset(const std::string& key, const std::string& charset)
{	
  // ��ȡ���ظ��ַ�

  std::wstring wcharset = util::S2WS(charset); // ת���ַ�
  std::sort(wcharset.begin(), wcharset.end()); // ����
  std::wstring::iterator i = std::unique(wcharset.begin(), wcharset.end()); // �޳��ظ��ַ�
  wcharset.erase(i, wcharset.end()); // ɾ�������ַ�

  // �����ȡ�������ַ�����ע�� std::wcout<<wcharset ���޷�������ֵģ����о���

  std::cout<<util::WS2S(wcharset)<<std::endl;

  // ���������

  return util::Insert(charsets_, std::make_pair(key, Unicode::Text(wcharset)));
}

bool CharsetManager::AddCharsetFromFile(const std::string& key, const std::string& path)
{
  assert(!path.empty());

  std::ifstream ifs(path.c_str());
  if (ifs.is_open())
  {	
    std::string charset;

    const size_t MAX_LEN = 255;
    char line[MAX_LEN + 1] = {};

    while (ifs.getline(line, MAX_LEN))
      charset += line;

    return AddCharset(key, charset);
  }

  return false;
}

const Unicode::Text& CharsetManager::GetCharset(const std::string& key)
{
  return util::Get(charsets_, key);
}
