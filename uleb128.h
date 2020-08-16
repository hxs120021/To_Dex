#include "DexFile.h"
#include "dex_string.h"

u4 getLEB128Lenght(char* str);
u4 LEB128toInt(char* str);
int readUnsignedLeb128(const u1** pStream);
char* getString(DexHeader* header, u8 index);