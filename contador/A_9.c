#include "contador.h"

void A_9(){
    uint32_t img1[5][5]={
    { 0x000000,   0x000020,   0x000020,   0x000020,   0x000000 },
    { 0x000000,   0x000020,   0x000000,   0x000020,   0x000000 },
    { 0x000000,   0x000020,   0x000020,   0x000020,   0x000000 },
    { 0x000000,   0x000000,   0x000000,   0x000020,   0x000000 },
    { 0x000000,   0x000000,   0x000000,   0x000020,   0x000000 }
    };
    renderRGBMatrix(img1);
   
}