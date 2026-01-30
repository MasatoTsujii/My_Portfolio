#include "vs_disp.h"
#include <mbed.h>
#include "init.h"
#include <USBSerial.h>

void disp(int num){
    printf("%d\t", num);
}

void dispd(double num){
    printf("%f\t", num);
}

void Ndisp(const char *str, int num){
    printf("%s : %d\t", str, num);
}

void Ndispd(const char *str, double num){
    printf("%s : %lf \t", str, num);
}

void lb(void){          //line break 改行
    printf("\n");
}