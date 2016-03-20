//#include "NeoCol.h"
//
//unsigned int8_t NeoGreen [NeoNum];
//unsigned int8_t NeoBlue [NeoNum];
//unsigned int8_t NeoRed [NeoNum];
//
//void NeoBit (int8_t Bit) {
//    
//   if (Bit != 0x00) {
//       LATBbits.LATB1 = 1;
////       __delay_us (6);
//       Nop();
//       Nop();
////       Nop();
////       Nop();
////       Nop();
////       Nop();
//       
//       LATBbits.LATB1 = 0;
//       // delay_cycles (3); // Bit '1'
//   } else {
//        LATBbits.LATB1 = 1;
////        delay_cycles (3);
//        
////        Nop();
////        Nop();
////        Nop();
//        
//        LATBbits.LATB1 = 0;
//   } // delay_cycles (6); // Bit '0'   
//}
//
//void NeoInit (void) {
//  
//    unsigned int8_t NeoPixel;
//   for (NeoPixel = 0; NeoPixel < NeoNum; NeoPixel++) {
//      
//       NeoGreen[NeoPixel] = 128;
//       NeoBlue[NeoPixel] = 0;
//       NeoRed[NeoPixel] = 0;
//       
//       
////       if (NeoPixel < 4) { 
//////          NeoGreen[NeoPixel] = 0;
//////          NeoBlue[NeoPixel] = 0;
//////          NeoRed[NeoPixel] = 64;
////          NeoGreen[NeoPixel] = 128;
////          NeoBlue[NeoPixel] = 0;
////          NeoRed[NeoPixel] = 0;
////       } else if ((NeoPixel >= 4) & (NeoPixel < 8)) {
//////           NeoGreen[NeoPixel] = 0;
//////           NeoBlue[NeoPixel] = 64;
//////           NeoRed[NeoPixel] = 0;
////           NeoGreen[NeoPixel] = 128;
////          NeoBlue[NeoPixel] = 0;
////          NeoRed[NeoPixel] = 0;
////       } else if ((NeoPixel >= 8) & (NeoPixel < 16)) {
//////           NeoGreen[NeoPixel] = 0;
//////           NeoBlue[NeoPixel] = 64;
//////           NeoRed[NeoPixel] = 64;
////           NeoGreen[NeoPixel] = 128;
////          NeoBlue[NeoPixel] = 0;
////          NeoRed[NeoPixel] = 0;
////       } else if ((NeoPixel >= 16) & (NeoPixel < 20)) { 
//////           NeoGreen[NeoPixel] = 64;
//////           NeoBlue[NeoPixel] = 0;
//////           NeoRed[NeoPixel] = 0;
////           NeoGreen[NeoPixel] = 128;
////          NeoBlue[NeoPixel] = 0;
////          NeoRed[NeoPixel] = 0;
////       } else if ((NeoPixel >= 20) & (NeoPixel < 21)) { 
//////           NeoGreen[NeoPixel] = 64;
//////           NeoBlue[NeoPixel] = 0;
//////           NeoRed[NeoPixel] = 64;
////           NeoGreen[NeoPixel] = 128;
////          NeoBlue[NeoPixel] = 0;
////          NeoRed[NeoPixel] = 0;
////       } else if ((NeoPixel >= 21) & (NeoPixel < NeoNum)) {
//////           NeoGreen[NeoPixel] = 64;
//////           NeoBlue[NeoPixel] = 64;
//////           NeoRed[NeoPixel] = 0;
////           NeoGreen[NeoPixel] = 128;
////          NeoBlue[NeoPixel] = 0;
////          NeoRed[NeoPixel] = 0;
////       }      
//   }
//}
//
//void NeoDraw (void)
//{
//   unsigned int8_t NeoPixel;
//   signed int8_t BitCount;
//   for (NeoPixel = 0; NeoPixel < NeoNum; NeoPixel++) {    
//      
//       for (BitCount = 7; BitCount >= 0; BitCount--) {  
//         NeoBit(bit_test(NeoGreen[NeoPixel], BitCount));
//       }
//      
//      for (BitCount = 7; BitCount >= 0; BitCount--) {    
//         NeoBit(bit_test(NeoRed[NeoPixel], BitCount));  
//      }
//      
//      for (BitCount = 7; BitCount >= 0; BitCount--) {
//         NeoBit(bit_test(NeoBlue[NeoPixel], BitCount));
//      }
//   }
//   
//   LATBbits.LB1 = 0;
//}
//
//void NeoRotate (void)
//{
//   unsigned int8_t NeoPixel;   
//   for (NeoPixel = 0; NeoPixel < NeoNum - 1; NeoPixel++)   
//   {           
//      NeoGreen[NeoPixel] = NeoGreen[NeoPixel + 1];
//      NeoBlue[NeoPixel] = NeoBlue[NeoPixel + 1];
//      NeoRed[NeoPixel] = NeoRed[NeoPixel + 1];
//   }
//   NeoGreen[NeoNum - 1] = NeoGreen[0];
//   NeoBlue[NeoNum - 1] = NeoBlue[0];
//   NeoRed[NeoNum - 1] = NeoRed[0]; 
//}
//
//void neoMain()
//{   
//   NeoInit ();   
//   while(true)
//   {       
//      NeoDraw ();
////      NeoRotate ();
////      __delay_ms (25);
//   }
//}
