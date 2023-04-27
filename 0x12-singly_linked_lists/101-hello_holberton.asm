#include <stdio.h>

void main(void)
{
    __asm__("mov $message, %rdi;"
            "xor %rax, %rax;"
            "call printf;"
            "mov $0, %eax;"
            "ret;"
            "message: .asciz \"Hello, Holberton\\n\";");
}
