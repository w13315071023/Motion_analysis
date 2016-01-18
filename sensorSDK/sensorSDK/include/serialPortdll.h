//define this dll entry functions

#ifdef SERIALPORTDLL_EXPORTS
#define SERIALPORTDLL_API __declspec(dllexport)
#else
#define SERIALPORTDLL_API __declspec(dllimport)
#endif

SERIALPORTDLL_API int get_com_num();
SERIALPORTDLL_API bool open_com_port(int com_num);
SERIALPORTDLL_API unsigned int fetch_msg();