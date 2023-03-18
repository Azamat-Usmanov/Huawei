#include <stdio.h>
#include "asm.h"
#include "cpu.h"

int main() 
{
    compile("equal.txt");
    Run("binary_file.txt");
    return 0;
}