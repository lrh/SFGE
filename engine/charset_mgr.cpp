#include "charset_mgr.h"

#include <fstream>

#include <util\container.h>
#include <util\string.h>

bool CharsetManager::LoadCharset( const std::string& key, const std::string& file )
{
	assert(!file.empty());

	std::ifstream ifs(file.c_str());
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

const Unicode::Text& CharsetManager::GetCharset( std::string key )
{
	return util::Get(charsets_, key);
}

bool CharsetManager::AddCharset( const std::string& key, const std::string& charset )
{	
	// ��ȡ���ظ��ַ�

	std::wstring wcharset = util::S2WS(charset);
	std::sort(wcharset.begin(), wcharset.end());
	std::wstring::iterator it = std::unique(wcharset.begin(), wcharset.end());
	wcharset.erase(it, wcharset.end());

    // �����ȡ�������ַ�����ע�� std::wcout<<wcharset ���޷�������ֵģ����о���

    // std::cout<<util::WS2S(wcharset)<<std::endl;

    // ���������

	return util::Insert(charsets_, std::make_pair(key, Unicode::Text(wcharset)));
}