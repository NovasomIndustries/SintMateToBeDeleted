/*
* /Devel/Stm32Sw/SintMate/Core/Src/SintMate/Images/Buttons/home.c
*  Created on: Feb 4, 2021
 *      Author: bmp2ili
 */
#include "main.h"
#include "main.h"
uint16_t home_width=48;
uint16_t home_height=48;
uint16_t home[2304] = 
{
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xa300,0x3234,0x574d,0xbb55,0x1d5e,0xfd65,0x9d65,0x5d65,0x1d65,0x1c65,0x1c5d,0x1d5d,0x5d5d,0x9d5d,0xdd5d,0xfd55,0x9a4d,0x163d,0xb023,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xb43c,0x7c5e,0xbd65,0x5d65,0x3d65,0x1d65,0x1c65,0x1c65,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xdc5c,0xdc5c,0x1c55,0x3d55,0xdd55,0x5c4e,0xd123,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xc400,0x4f2b,0x5c56,0xfd65,0xfc64,0x1d65,0x1d65,0x1d65,0x1d65,0x1d5d,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xbc54,0xbc54,0x1e56,0xba45,0x8c1a,0x4100,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xc811,0x784d,0x3e66,0x3d65,0xfd64,0x1d65,0x1d65,0x1d65,0x1d65,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xdc5c,0xdc5c,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xbc54,0x9c4c,0x3d4d,0xfd4d,0xf634,0x4200,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xac1a,0x7d5e,0x7d65,0x1d65,0x1d65,0x1d65,0x1d65,0x1d5d,0xfd5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xdc5c,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xbc54,0xbc54,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0x5d4d,0x1b3e,0x0200,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6f2b,0x7d5e,0x1d65,0x1d65,0x1d65,0x1d65,0x1d5d,0xfd5c,0xfd5c,0xfd5c,0xfc5c,0xfc5c,0xfc5c,0xfc5c,0xdc5c,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xbc54,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0x9c4c,0x9c4c,0x7c44,0xdd44,0x3c3e,0x4a12,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4f23,0x1d5e,0x1d65,0x1d65,0x1d5d,0x1d5d,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfc5c,0xdd5c,0xdd54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xdc54,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0x9c4c,0x9c4c,0x9c44,0x9c44,0x9c44,0x7c44,0xbc44,0xbb3d,0x290a,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x4a1a,0x7e5e,0x1d5d,0x1d5d,0x1d5d,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xdd54,0xdd54,0xdd54,0xdd54,0xdc54,0xdc54,0xdc54,0xbc54,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0xbc4c,0x9c4c,0x9c4c,0x9c4c,0x9c4c,0x9c44,0x9c44,0x7c44,0x7c44,0x7c44,0x7c44,0x7c3c,0xbc3c,0x1c36,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x8609,0x7c56,0xfd5c,0x1d5d,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xbd4c,0xbd4c,0xbc4c,0xbc4c,0x9c4c,0x9c4c,0x9c44,0x9c44,0x9c44,0x9c44,0x9c44,0x7c44,0x7c44,0x7c44,0x7c44,0x7c3c,0x7c3c,0x7c3c,0x7c3c,0x5c3c,0xdd3c,0xda2d,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0xc300,0x5845,0x5d5d,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0x9c3c,0x1cae,0x5cb6,0x9c44,0x9c44,0x9c44,0x9c44,0x9c44,0x7c44,0x7c44,0x7c3c,0x7c3c,0x7c3c,0x7c3c,0x5c3c,0x5c3c,0x5c3c,0x5c3c,0x5c3c,0x3c34,0x5d35,0x9424,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x2e23,0x1e5e,0xfd5c,0xfd5c,0xfd5c,0xfd5c,0xfd54,0xfd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0x9c44,0x1cae,0x9eef,0x9ef7,0x5cb6,0x7c44,0x9c44,0x7c44,0x7c3c,0x7c3c,0x7c3c,0x7c3c,0x7c3c,0x5c3c,0x5c3c,0x5c3c,0x5c34,0x5c34,0x5c34,0x5c34,0x3c34,0x5c34,0xbc2d,0x090a,0x2100,0x0000,0x0000,
0x0000,0x0000,0x0000,0x3c4e,0x1d5d,0xfd5c,0xfd5c,0xfd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0x9d4c,0x9c44,0xbc9d,0xbef7,0xdfff,0xdfff,0xbef7,0x1cae,0x7c3c,0x7d3c,0x7c3c,0x7c3c,0x7c3c,0x5c3c,0x5c3c,0x5c34,0x5c34,0x5c34,0x5c34,0x3c34,0x3c34,0x3c34,0x3c34,0x3c2c,0xfd2c,0x1725,0x0000,0x0000,0x0000,
0x0000,0x0000,0x9434,0xde55,0xdd5c,0xfd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd54,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd44,0x9d44,0x7c34,0x1cae,0xbef7,0xdfff,0xffff,0xffff,0xdfff,0xbef7,0x3cb6,0x5c34,0x5d3c,0x5c3c,0x5d3c,0x5c34,0x5c34,0x5c34,0x5c34,0x3c34,0x3c34,0x3c34,0x3c2c,0x3c2c,0x3c2c,0x1c2c,0xfc2b,0xfe2d,0xac0a,0x0000,0x0000,
0x0000,0x4000,0x5c4e,0xdd54,0xfd54,0xdd54,0xdd54,0xdd54,0xdd54,0xdd4c,0xdd4c,0xbd4c,0xbd4c,0xbd4c,0x9d4c,0x9d44,0x9d44,0x9d44,0x9c44,0x1cae,0x9eef,0xdfff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0x3cb6,0x5c34,0x5d34,0x5d34,0x5d34,0x5d34,0x3d34,0x3d34,0x3d2c,0x3c2c,0x3c2c,0x3c2c,0x1c2c,0x1c2c,0x1c2c,0x1c2c,0x3d24,0xda25,0x0000,0x0000,
0x0000,0x322c,0x7d55,0xdd54,0xdd54,0xdd54,0xdd54,0xdd4c,0xdd4c,0xbd4c,0xbd4c,0xbd4c,0xbd44,0x9d44,0x9d44,0x9d44,0x9d44,0x7c3c,0xbc9d,0xbef7,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0xdca5,0x3c34,0x3d34,0x3d34,0x3d34,0x3d2c,0x3c2c,0x3c2c,0x3c2c,0x1c2c,0x1c2c,0x1c2c,0x1c24,0x1c24,0x1c24,0xdc23,0x9d25,0xcc0a,0x0000,
0x6100,0x373d,0x1d55,0xdd54,0xdd4c,0xdd4c,0xdd4c,0xdd4c,0xbd4c,0xbd4c,0xbd44,0x9d44,0x9d44,0x9d44,0x9d44,0x9d44,0x7c34,0x1cae,0xbef7,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0x1cb6,0x3c24,0x3d2c,0x3d2c,0x3d2c,0x3d2c,0x1d2c,0x1d2c,0x1d2c,0x1c24,0x1c24,0x1c24,0xfc23,0xfc23,0xfc23,0x7d24,0x9414,0x0000,
0xe809,0x9b45,0xfd4c,0xdd4c,0xdd4c,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0x9d44,0x9d44,0x9d44,0x9d44,0x9d44,0x9d44,0x7d3c,0x1cae,0x9eef,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0x9def,0xdbad,0x9c0b,0xbc1b,0xdc1b,0xfd23,0x1d2c,0x1d24,0x1d24,0x1d24,0xfd23,0xfd23,0xfd23,0xfd23,0xfd23,0x3d1c,0xf814,0xe400,
0x8b12,0xde4d,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd44,0x9d44,0x9d44,0x9d44,0x9d44,0x9d3c,0x7d3c,0x7d3c,0xbc9d,0xbef7,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbdf7,0x7b9d,0x5c03,0x5c03,0x5c03,0x7c03,0x9c13,0xdd1b,0xfd23,0xfd23,0xfd23,0xfd1b,0xfd1b,0xfd1b,0xfd1b,0x3b1d,0x0902,
0x7023,0x9e4d,0xbd4c,0xbd4c,0xbd4c,0xbd4c,0xbd44,0x9d44,0x9d44,0x9d44,0x9d3c,0x9d3c,0x7d3c,0x5d2c,0x1cae,0xbef7,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0xdbad,0x5c03,0x7c03,0x7c03,0x7c03,0x7c03,0x7c03,0xbd13,0xdd1b,0xfd1b,0xdd1b,0xdd1b,0xdd1b,0x5d1d,0x4b02,
0x952c,0x5e4d,0xbd4c,0xbd44,0xbd44,0x9d44,0x9d44,0x9d3c,0x7d3c,0x7d3c,0x7d3c,0x7d3c,0x5d34,0x1cae,0x9ef7,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0x9def,0xdbad,0x5c03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x9d0b,0xdd1b,0xdd1b,0xdd13,0x1d15,0xee02,
0x3835,0xfd44,0xbd44,0xbd44,0x9d44,0x9d44,0x9d3c,0x7d3c,0x7d3c,0x7d3c,0x7d3c,0x5d2c,0xbc95,0xbef7,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0x7b95,0x5c03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0xbd13,0xbd13,0xdd14,0xb20b,
0xba35,0xbd44,0x9d44,0x9d44,0x9d44,0x9d3c,0x7d3c,0x7d3c,0x7d3c,0x7d34,0x7d34,0xfd03,0x9eef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0x1c03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x9d0b,0x7d14,0x750c,
0xba35,0x9d44,0x9d3c,0x9d3c,0x9d3c,0x7d3c,0x7d34,0x7d34,0x7d34,0x5d34,0x5d34,0xfd03,0xbef7,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5c03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x1d04,0xb60c,
0xba35,0x9e3c,0x9d3c,0x9d3c,0x7d3c,0x7d34,0x7d34,0x7d34,0x5d34,0x5d34,0x5d34,0xdd03,0xbeef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x1d04,0x9604,
0x9a2d,0x9e3c,0x7d3c,0x7d3c,0x7d34,0x5d34,0x5d34,0x5d34,0x5d34,0x5d2c,0x5d2c,0x5d03,0x9eef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xdfff,0xdfff,0xdfff,0xdfff,0xdfff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x7d03,0x5d04,0x5504,
0x1725,0xbe3c,0x7e34,0x7e34,0x7e34,0x5e34,0x5e2c,0x5e2c,0x5e2c,0x3d2c,0xfd23,0xfd02,0x9eef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0xbef7,0xbef7,0xbef7,0xbef7,0xbef7,0xbef7,0xdef7,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x7d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x7d03,0xbe04,0x9103,
0x541c,0x1e35,0x7e34,0x7e34,0x5e2c,0x5e2c,0x5e2c,0x3e2c,0x3d2c,0x3d24,0x9d0b,0xdd02,0x9eef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xbd02,0x7d03,0x7d03,0x7d03,0x7d03,0x3d03,0xfdad,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x7d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x7d03,0xfe04,0xce02,
0x2f13,0x7e35,0x5e34,0x5e34,0x5e2c,0x5e2c,0x3e2c,0x3e2c,0x3e2c,0xdd1b,0x9d03,0xfd02,0x9eef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xfd02,0x9d03,0x9d03,0x9d03,0x9d03,0x7d03,0xfdad,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x7d03,0x3e05,0x4a02,
0x6b0a,0x9e2d,0x5e2c,0x5e2c,0x5e2c,0x3e24,0x3e24,0x3e24,0x1e24,0x9d03,0x9d03,0xfd02,0x9eef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0x3d03,0xde03,0xde03,0xde03,0xde03,0x9e03,0xfdad,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0x9d03,0xbd03,0x1b05,0xe801,
0xc801,0x5b25,0x7e2c,0x3e2c,0x3e24,0x3e24,0x3e24,0x3e24,0xde13,0x9e03,0x9e03,0xfd02,0xbeef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0x5d03,0xde03,0xde03,0xde03,0xde03,0xbe03,0xfdad,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5d03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0xfe03,0xd804,0xa300,
0x2000,0xf71c,0x9e2c,0x3e24,0x3e24,0x3e24,0x3e24,0x1e24,0xbe03,0x9e03,0xbe03,0x1d03,0xbeef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0x7d03,0xfe03,0xfe03,0xfe03,0xfe03,0xde03,0x1eae,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x7d03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x5e04,0x7404,0x0000,
0x0000,0xf113,0x3e25,0x1e24,0x3e24,0x1e24,0x1e1c,0xfe1b,0xbe03,0xbe03,0xbe03,0x3e03,0xbeef,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xdfff,0x9e03,0x1e04,0x1e04,0x1e04,0x1e04,0xfe03,0x1eae,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x7d03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x7e03,0x7d05,0x6a02,0x0000,
0x0000,0x0000,0x1c1e,0xfe23,0x1e24,0x1e1c,0x1e1c,0xfe13,0xbe03,0xbe03,0xde03,0x5e03,0xbeef,0xdfff,0xdeff,0xdeff,0xdeff,0xdeff,0xdeff,0xdeff,0xffff,0xbe03,0x3e04,0x3e04,0x3e04,0x3e04,0x1e04,0x3eb6,0xffff,0xdeff,0xdeff,0xdeff,0xdeff,0xdeff,0xdeff,0xffff,0x9d03,0xbe03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0x9e03,0xfe03,0x9905,0x0000,0x0000,
0x0000,0x0000,0x120c,0x7f1d,0xfe1b,0x1e1c,0x1e1c,0xfe13,0xbe03,0xde03,0xde03,0x9e03,0x7ebe,0xbece,0xbec6,0xbec6,0xbec6,0xbec6,0xbec6,0xbec6,0xdece,0x1e04,0x5e04,0x5e04,0x5e04,0x5e04,0x3e04,0x9e8d,0xdece,0xbec6,0xbec6,0xbec6,0x9ec6,0x9ec6,0xbec6,0xbec6,0xbe03,0xbe03,0xbe03,0xbe03,0x9e03,0x9e03,0x9e03,0x7e03,0xde05,0x2902,0x0000,0x0000,
0x0000,0x0000,0x0000,0xbb15,0x7e1c,0x1e1c,0x1e14,0xfe0b,0xde03,0xde03,0xfe03,0xfe03,0x1e1c,0x3e2c,0x5e2c,0x5e2c,0x5e2c,0x7e2c,0x7e2c,0x7e24,0x7e2c,0x5e04,0x7e04,0x7e04,0x7e04,0x7e04,0x5e04,0x5e1c,0x7e2c,0x5e2c,0x5e2c,0x5e2c,0x3e2c,0x3e2c,0x1e2c,0x1e24,0xde03,0xde03,0xbe03,0xbe03,0xbe03,0x9e03,0x9e03,0xbf04,0x9604,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0xac02,0x9e1d,0x1e14,0x1e14,0xfe0b,0xde03,0xfe03,0xfe03,0x1e04,0x1e04,0x3e04,0x3e04,0x5e04,0x5e04,0x7e04,0x7e04,0x7e04,0x7e04,0x9e04,0x9e04,0x9e04,0x9e04,0x7e04,0x7e04,0x7e04,0x7e04,0x5e04,0x5e04,0x3e04,0x3e04,0x1e04,0x1e04,0xfe03,0xfe03,0xde03,0xde03,0xbe03,0xbe03,0xbe03,0xbe03,0x5c05,0xc801,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x6100,0xd60c,0xde14,0x1e14,0xfe0b,0xfe03,0xfe03,0x1e04,0x3e04,0x3e04,0x5e04,0x5e04,0x7e04,0x7f04,0x9e04,0x9f04,0x9f04,0x9f04,0xbf04,0x9f04,0x9f04,0x9f04,0x9f04,0x9f04,0x9f04,0x9e04,0x7f04,0x7e04,0x5e04,0x5e04,0x3e04,0x1e04,0x1e04,0xfe03,0xfe03,0xde03,0xde03,0xbe03,0x7e03,0x1e05,0x1204,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0xa200,0xfc15,0x3e14,0xfe0b,0xfe03,0x1e04,0x3e04,0x3e04,0x5e04,0x5e04,0x7e04,0x7f04,0x9f04,0x9f04,0xbf04,0xbf04,0xbf04,0xdf04,0xbf04,0xbf04,0xbf04,0xbf04,0xbf04,0xbf04,0x9f04,0x9f04,0x7f04,0x7e04,0x5e04,0x5e04,0x3e04,0x1e04,0x1e04,0xfe03,0xfe03,0xde03,0xbe03,0xbf04,0x5805,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0501,0x1d0e,0x3f0c,0x1f04,0x3f04,0x3f04,0x5f04,0x5f04,0x7f04,0x9f04,0x9f04,0xbf04,0xbf04,0xdf04,0xdf04,0xdf04,0xdf04,0xff04,0xff04,0xdf04,0xdf04,0xdf04,0xbf04,0xbf04,0xbf04,0x9f04,0x7f04,0x7f04,0x5f04,0x5f04,0x3f04,0x1f04,0x1f04,0xfe03,0xde03,0x7f04,0xbb05,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x8c02,0x9c0d,0x5f04,0x3f04,0x5f04,0x5f04,0x7f04,0x9f04,0x9f04,0xbf04,0xbf04,0xdf04,0xdf04,0xff04,0xff04,0xff04,0xff04,0xff04,0xff04,0xff04,0xff04,0xdf04,0xdf04,0xbf04,0xbf04,0x9f04,0x9f04,0x7f04,0x5f04,0x5f04,0x3f04,0x1f04,0xff03,0x7f04,0x5b05,0x6601,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x8b02,0x1d06,0x7f04,0x5f04,0x7f04,0x9f04,0x9f04,0xbf04,0xdf04,0xdf04,0xff04,0xff04,0xff04,0x1f05,0x1f05,0x1f05,0x1f05,0x1f05,0x1f05,0x1f05,0xff04,0xff04,0xdf04,0xbf04,0xbf04,0x9f04,0x7f04,0x7f04,0x5f04,0x3f04,0xff03,0xdf04,0xbb05,0x4601,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x2100,0xfb05,0x1f05,0x9f04,0x9f04,0xbf04,0xbf04,0xdf04,0xff04,0xff04,0x1f05,0x1f05,0x3f05,0x3f05,0x3f05,0x3f05,0x3f05,0x3f05,0x1f05,0x1f05,0xff04,0xff04,0xdf04,0xbf04,0xbf04,0x9f04,0x7f04,0x5f04,0x7f04,0x5f05,0x5805,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xb604,0xbe05,0x1f05,0x9f04,0xdf04,0xff04,0x1f05,0x1f05,0x3f05,0x3f05,0x3f05,0x5f05,0x5f05,0x5f05,0x5f05,0x5f05,0x3f05,0x3f05,0x1f05,0xff04,0xff04,0xdf04,0xbf04,0x9f04,0x7f04,0x3f05,0x9d05,0x3304,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x2000,0x4a02,0x5905,0xff05,0xff04,0xff04,0x1f05,0x3f05,0x3f05,0x5f05,0x5f05,0x5f05,0x5f05,0x5f05,0x5f05,0x5f05,0x5f05,0x3f05,0x3f05,0x1f05,0xff04,0xff04,0xbf04,0xdf04,0x1f06,0xd704,0xe801,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4e03,0xfb05,0xbe05,0x5f05,0x5f05,0x5f05,0x5f05,0x5f05,0x7f05,0x7f05,0x7f05,0x7f05,0x5f05,0x5f05,0x3f05,0x3f05,0x3f05,0x3f05,0x3f05,0xde05,0xba05,0x4a02,0x0000,0x2000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x2e03,0xb604,0x5a05,0xbd05,0xff05,0xff05,0xdf05,0xbf05,0xbf05,0xbf05,0xbf05,0xdf05,0xff05,0xdf05,0x9c05,0x3905,0x7404,0x8b02,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4501,0x2902,0x8c02,0x9103,0x3304,0xd604,0xf704,0xf704,0xb604,0xf303,0x7003,0x6b02,0x0902,0xe400,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0840,0x962b,0x2f56,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xa012,0x1c2d,0x2f56,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

};
