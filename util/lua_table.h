#pragma once

#include <string>

#include "util.h"

struct lua_State;

namespace util
{
	UTIL_API int PrintTable(lua_State* L);

	UTIL_API bool HasField(lua_State* L, int key);
	UTIL_API bool HasField(lua_State* L, int index, int key);
	UTIL_API bool HasField(lua_State* L, const std::string& key);
	UTIL_API bool HasField(lua_State* L, int index, const std::string& key);

    // TODO: GetField ϵ�й�����ǿ���������Ĭ�Ϸ���ֵ�Ĳ���

    UTIL_API bool GetField_Boolean(lua_State* L, int key);
    UTIL_API bool GetField_Boolean(lua_State* L, int index, int key);
	UTIL_API bool GetField_Boolean(lua_State* L, const std::string& key);
	UTIL_API bool GetField_Boolean(lua_State* L, int index, const std::string& key);
    UTIL_API bool SafeGetField_Boolean(lua_State* L, const std::string& key);
    UTIL_API bool SafeGetField_Boolean(lua_State* L, int index, const std::string& key);

	UTIL_API int GetField_Integer(lua_State* L, int key);
	UTIL_API int GetField_Integer(lua_State* L, int index, int key);
	UTIL_API int GetField_Integer(lua_State* L, const std::string& key);
	UTIL_API int GetField_Integer(lua_State* L, int index, const std::string& key);

	UTIL_API double GetField_Number(lua_State* L, int key);
	UTIL_API double GetField_Number(lua_State* L, int index, int key);
	UTIL_API double GetField_Number(lua_State* L, const std::string& key);
	UTIL_API double GetField_Number(lua_State* L, int index, const std::string& key);
    UTIL_API double SafeGetField_Number(lua_State* L, int key);
    UTIL_API double SafeGetField_Number(lua_State* L, int index, int key); 
    UTIL_API double SafeGetField_Number(lua_State* L, const std::string& key);
    UTIL_API double SafeGetField_Number(lua_State* L, int index, const std::string& key);

    UTIL_API std::string GetField_String(lua_State* L, int key);
    UTIL_API std::string GetField_String(lua_State* L, int index, int key);
    UTIL_API std::string GetField_String(lua_State* L, const std::string& key);
    UTIL_API std::string GetField_String(lua_State* L, int index, const std::string& key);
    UTIL_API std::string SafeGetField_String(lua_State* L, int key);
    UTIL_API std::string SafeGetField_String(lua_State* L, int index, int key);
    UTIL_API std::string SafeGetField_String(lua_State* L, const std::string& key);
    UTIL_API std::string SafeGetField_String(lua_State* L, int index, const std::string& key);

	// Ϊʲô���� void* ʱ��������ָʾ��Ҫ�� void* ǰ����ܱ���ͨ����

	UTIL_API void* GetField_LightUserdata(lua_State* L, const std::string& key); 
	UTIL_API void* GetField_LightUserdata(lua_State* L, int index, const std::string& key); 

	UTIL_API void* GetField_Userdata(lua_State* L, const std::string& key);
	UTIL_API void* GetField_Userdata(lua_State* L, int index, const std::string& key);
}