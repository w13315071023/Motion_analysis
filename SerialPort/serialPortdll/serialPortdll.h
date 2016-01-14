//define this dll entry functions

#ifdef SERIALPORTDLL_EXPORTS
#define SERIALPORTDLL_API __declspec(dllexport)
#else
#define SERIALPORTDLL_API __declspec(dllimport)
#endif

SERIALPORTDLL_API int get_Port_num();
SERIALPORTDLL_API int fetch_msg();