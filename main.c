#include <stdio.h>
#include <windows.h>
void delay(unsigned int ms) { Sleep(ms); }
int main() {
    system("cls");
    unsigned short heart_pattern[] = {
        0x0000, 
        0x0C30, 
        0x1E78, 
        0x3FFC, 
        0x7FFE, 
        0xFFFF, 
        0xFFFF, 
        0xFFFF, 
        0x7FFE, 
        0x3FFC, 
        0x1FF8, 
        0x0FF0, 
        0x07E0, 
        0x03C0, 
        0x0180, 
        0x0000  
    };
    int length = sizeof(heart_pattern) / sizeof(heart_pattern[0]);
    printf("--- 电控任务：寄存器心形流水灯 ---\n\n");
    for (int i = 0; i < length; i++) {
        printf("0x%04X | ", heart_pattern[i]);
        for (int bit = 15; bit >= 0; bit--) {
            if ((heart_pattern[i] >> bit) & 1) {
                printf("* "); 
            } else {
                printf("  "); 
            }
        }
        printf("\n");
        delay(120); 
    }
    printf("\n--- 演示结束 ---\n");
    return 0;
}