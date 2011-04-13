#include "lua_table.h"

#include <lua\lua.hpp>

#include "lua_base.h"

namespace util
{	
    // �ݹ��ӡһ���˱�

	int PrintTable( lua_State* L )
	{
		// first key

		lua_pushnil(L);
		int tableIndex = lua_gettop(L) - 1;
		while (lua_next(L, tableIndex) != 0) 
		{
			for (int i = 0; i < tableIndex - 1; ++i)
				printf("  ");

			// print key-type and value-type, format: %s - %s

			printf("%s - %s\n", 
				lua_typename(L, lua_type(L, -2)),	// key type
				lua_typename(L, lua_type(L, -1)));	// value type

			// value type

			if (lua_typename(L, lua_type(L, -1)) == "table")
				PrintTable(L);

			lua_pop(L, 1); // pop value, keep key
		}

		return 1;
	}

    // ��ջ���ı��Ƿ���ĳ����

	bool HasField( lua_State* L, int key )
	{
		return HasField(L, -1, key);
	}

    // ��ջ index λ�õı��Ƿ���ĳ����

	bool HasField(lua_State* L, int index, int key)
	{
		int tableIndex = ToPositiveIndex(L, index);
		lua_pushinteger(L, key);
		lua_gettable(L, tableIndex);
		bool result = !lua_isnil(L, -1);
		lua_pop(L, 1);
		return result;
	}

    // ��ջ���ı��Ƿ���ĳ����

	bool HasField( lua_State* L, const std::string& key )
	{
		return HasField(L, -1, key);
	}

    // ��ջ index λ�õı��Ƿ���ĳ����

	bool HasField(lua_State* L, int index, const std::string& key)
	{
		lua_getfield(L, index, key.c_str());
		bool result = !lua_isnil(L, -1);
		lua_pop(L, 1);
		return result;
	}

    bool GetField_Boolean(lua_State* L, int key)
    {
        return GetField_Boolean(L, -1, key);
    }

    bool SafeGetField_Boolean(lua_State* L, int key)
    {
        return SafeGetField_Boolean(L, key);
    }

    bool GetField_Boolean(lua_State* L, int index, int key)
    {
        int tableIndex = ToPositiveIndex(L, index);
        assert(lua_istable(L, tableIndex));

        // ��ȡ���

        lua_pushinteger(L, key);
        lua_gettable(L, tableIndex);

        bool result = false;
        if (lua_isboolean(L, -1))
            result = (lua_toboolean(L, -1) != 0);
        else if (lua_isnumber(L, -1))
            result = (lua_tonumber(L, -1) != 0.);

        // �����ջ����ԭջ

        lua_pop(L, 1);

        return result;	
    }

    bool SafeGetField_Boolean(lua_State* L, int index, int key)
    {
        if (HasField(L, index, key))
            return GetField_Boolean(L, index, key);
        assert(false);
        return false;
    }

    // ��ȡջ���ı�� key ��ֵ

	bool GetField_Boolean(lua_State* L, const std::string& key)
	{
		return GetField_Boolean(L, -1, key);
	}

    bool SafeGetField_Boolean(lua_State* L, const std::string& key)
    {
        return SafeGetField_Boolean(L, -1, key);
    }

	bool GetField_Boolean( lua_State* L, int index, const std::string& key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushstring(L, key.c_str());
		lua_gettable(L, tableIndex);

		bool result = false;
		if (lua_isboolean(L, -1))
			result = (lua_toboolean(L, -1) != 0);
        else if (lua_isnumber(L, -1))
            result = (lua_tonumber(L, -1) != 0.);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;
	}

    bool SafeGetField_Boolean( lua_State* L, int index, const std::string& key )
    {
        if (HasField(L, index, key))
            return GetField_Boolean(L, index, key);
        assert(false);
        return false;
    }

    // ��ȡջ���ı�� key ��ֵ

	int GetField_Integer( lua_State* L, int key )
	{
		return GetField_Integer(L, -1, key);
	}

	int GetField_Integer( lua_State* L, int index, int key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���

		lua_pushinteger(L, key);
		lua_gettable(L, tableIndex);

		int result = 0;
		if (lua_isnumber(L, -1))
			result = lua_tointeger(L, -1);

		// �����ջ����ԭջ

		lua_pop(L, 1);

		return result;	
	}

    // ��ȡջ���ı�� key ��ֵ

	int GetField_Integer( lua_State* L, const std::string& key )
	{
		return GetField_Integer(L, -1, key);
	}

	int GetField_Integer( lua_State* L, int index, const std::string& key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushstring(L, key.c_str());
		lua_gettable(L, tableIndex);

		int result = 0;
		if (lua_isnumber(L, -1))
			result = lua_tointeger(L, -1);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;	
	}

    // ��ȡջ���ı�� key ��ֵ

	double GetField_Number(lua_State* L, int key)
	{
		return GetField_Number(L, -1, key);
	}

	double GetField_Number( lua_State* L, int index, int key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushinteger(L, key);
		lua_gettable(L, tableIndex);

		double result = 0.0f;
		if (lua_isnumber(L, -1))
			result = lua_tonumber(L, -1);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;	
	}

    // ��ȡջ���ı�� key ��ֵ

	double GetField_Number(lua_State* L, const std::string& key)
	{
		return GetField_Number(L, -1, key);
	}

    double SafeGetField_Number(lua_State* L, const std::string& key)
    {
        return SafeGetField_Number(L, -1, key);
    }

	double GetField_Number(lua_State* L, int index, const std::string& key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushstring(L, key.c_str());
		lua_gettable(L, tableIndex);

		double result = 0.0;
		if (lua_isnumber(L, -1))
			result = lua_tonumber(L, -1);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;	
	}

    double SafeGetField_Number(lua_State* L, int index, const std::string& key )
    {
        if (HasField(L, index, key))
            return GetField_Number(L, index, key);
        assert(false);
        return 0.0;
    }

    // ��ȡջ���ı�� key ��ֵ

	std::string GetField_String(lua_State* L, const std::string& key)
	{
		return GetField_String(L, -1, key);
	}

	std::string UTIL_API GetField_String( lua_State* L, int index, const std::string& key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushstring(L, key.c_str());
		lua_gettable(L, tableIndex);

		std::string result = "";
		if (lua_isstring(L, -1))
			result = lua_tostring(L, -1);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;
	}

    // ��ȡջ���ı�� key ��ֵ

	void* GetField_LightUserdata(lua_State* L, const std::string& key)
	{
		return GetField_LightUserdata(L, -1, key);
	}

    void* GetField_LightUserdata( lua_State* L, int index, const std::string& key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushstring(L, key.c_str());
		lua_gettable(L, tableIndex);

		void* result = NULL;
		if (lua_islightuserdata(L, -1))
			result = lua_touserdata(L, -1);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;
	}

    // ��ȡջ���ı�� key ��ֵ

	void* GetField_Userdata(lua_State* L, const std::string& key)
	{
		return GetField_Userdata(L, -1, key);
	}

    void* GetField_Userdata( lua_State* L, int index, const std::string& key )
	{
		int tableIndex = ToPositiveIndex(L, index);
		assert(lua_istable(L, tableIndex));

		// ��ȡ���
		lua_pushstring(L, key.c_str());
		lua_gettable(L, tableIndex);

		void* result = NULL;
		if (lua_isuserdata(L, -1))
			result = lua_touserdata(L, -1);

		// �����ջ����ԭջ
		lua_pop(L, 1);

		return result;
	}
}