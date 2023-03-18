#define DEF_CMD(name, num, arg, code) \
    CMD_##name = num,

enum Commands { 
    #include "cmd.h"
    };

#undef DEF_CMD