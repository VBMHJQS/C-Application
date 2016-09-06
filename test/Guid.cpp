#include <objbase.h>
#include <stdio.h>

//--生成GUID
const char* newGUID()
{
	static char buf[64] = {0};
	GUID guid;
	if (S_OK == ::CoCreateGuid(&guid))
	{
		_snprintf(buf, sizeof(buf)
				, "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
				, guid.Data1
				, guid.Data2
				, guid.Data3
				, guid.Data4[0], guid.Data4[1]
											, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
																									  , guid.Data4[6], guid.Data4[7]
		);
	}
	return (const char*)buf;
}

int main(int argc, char* argv[])
{
	//--COM
	CoInitialize(NULL);

	printf(newGUID());
	printf("\r\n");

	//--COM
	CoUninitialize();

	return 0;
}
