//define this dll entry functions

#ifdef SERIALPORTDLL_EXPORTS
#define SERIALPORTDLL_API __declspec(dllexport)
#else
#define SERIALPORTDLL_API __declspec(dllimport)
#endif

SERIALPORTDLL_API int get_com_num(); //0:no valid com port
SERIALPORTDLL_API bool open_com_port(int com_num); //TRUE:open successful; FALSE:open failed
SERIALPORTDLL_API unsigned int fetch_msg(); 
//1:no ball; 2:has ball no hit; 3:has ball hit valid; 4:has ball hit invalid;