#include <REG52.H>

sbit p1 = P2^2;
sbit p2 = P2^3;
sbit p3 = P2^4;

void my_func(int digit);
void display_num_7seg(long num);

void M0T0delay(void) {
    TMOD = 0x01;  // 16-bit non-autoreload mode, timer_0, mode_1
    TL0 = 0x99; 
    TH0 = 0xEF;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}

void main() {
    long num = 97561654;
    while (1) {
        display_num_7seg(num);
    }
}

void display_num_7seg(long num) {
    int i;
    for (i = 0; i < 8; i++) {
        p1 = i & 0x01;
        p2 = (i >> 1) & 0x01;
        p3 = (i >> 2) & 0x01;
        my_func(num % 10);
        M0T0delay();
        num /= 10;
    }
}

void my_func(int digit) {
    switch(digit) {
        case 0:
            P0 = 0x3F;
            break;
        case 1:
            P0 = 0x06;
            break;
        case 2:
            P0 = 0x5B;
            break;
        case 3:
            P0 = 0x4F;
            break;
        case 4:
            P0 = 0x66;
            break;
        case 5:
            P0 = 0x6D;
            break;
        case 6:
            P0 = 0x7D;
            break;
        case 7:
            P0 = 0x07;
            break;
        case 8:
            P0 = 0x7F;
            break;
        case 9:
            P0 = 0x6F;
            break;
    }
}
