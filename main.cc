#include <iostream>
#include <cmath>
#include <stdint.h>

int main()
{
    const double R=8000;        // sample rate
    const double C=261.625565;  // frequency of middle C (hz)
    const double F=R/256;       // bytebeat frequency of 1*t due to 8-bit truncation (hz)
    const double V=127;         // a volume constant

    int x = 0;
    int y = 0;

    for (int t = 0; ; t++) {
        // uint8_t temp = (sin(t*2*M_PI/R*C)+1)*V;     // pure middle C sine wave
        // uint8_t temp = t/F*C;   // middle C saw wave (bytebeat style)

        // bytebeats
        //
        uint8_t temp = (t*5&t>>7)|(t*3&t>>10);
        // uint8_t temp = ((t/2*(15&(0x234568a0>>(t>>8&28))))|t/2>>(t>>11)^t>>12)+(t/16&t&24);
        // uint8_t temp = (t&t>>8);
        // uint8_t temp = (t>>7|t|t>>6)*10+4*(t&t>>13|t>>6);
        // uint8_t temp = ((t<<1)^((t<<1)+(t>>7)&t>>12))|t>>(4-(1^7&(t>>19)))|t>>7;
        // uint8_t temp = (t>>6|t>>(t>>16))*10+((t>>11)&7);
        // uint8_t temp = t*5&(t>>7)|t*3&(t*4>>10);
        // uint8_t temp = ((t*(t>>8|t>>9)&46&t>>8))^(t&t>>13|t>>6);

        std::cout << temp;
    }
}
