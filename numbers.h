#include "bits.h" 

struct bits8 {
  struct bit b0;
  struct bit b1;
  struct bit b2;
  struct bit b3;
  struct bit b4;
  struct bit b5;
  struct bit b6;
  struct bit b7;
};

// Addition
struct bits8 bits8_add(struct bits8 x, struct bits8 y){
   struct bit c;
   struct bits8 s;

   // Definerer c-værdierne
   struct bit c0 = bit_or((bit_and(x.b0,y.b0)),bit_and((bit_or(x.b0,y.b0)),c));
   struct bit c1 = bit_or((bit_and(x.b1,y.b1)),bit_and((bit_or(x.b1,y.b1)),c));
   struct bit c2 = bit_or((bit_and(x.b2,y.b2)),bit_and((bit_or(x.b2,y.b2)),c));
   struct bit c3 = bit_or((bit_and(x.b3,y.b3)),bit_and((bit_or(x.b3,y.b3)),c));
   struct bit c4 = bit_or((bit_and(x.b4,y.b4)),bit_and((bit_or(x.b4,y.b4)),c));
   struct bit c5 = bit_or((bit_and(x.b5,y.b5)),bit_and((bit_or(x.b5,y.b5)),c));
   struct bit c6 = bit_or((bit_and(x.b6,y.b6)),bit_and((bit_or(x.b6,y.b6)),c));
   struct bit c7 = bit_or((bit_and(x.b7,y.b7)),bit_and((bit_or(x.b7,y.b7)),c));

   // Definerer s-værdierne
   struct bit s0 = bit_xor(bit_xor(x.b0,y.b0),c0);
   struct bit s1 = bit_xor(bit_xor(x.b1,y.b1),c0);
   struct bit s2 = bit_xor(bit_xor(x.b2,y.b2),c1);
   struct bit s3 = bit_xor(bit_xor(x.b3,y.b3),c2);
   struct bit s4 = bit_xor(bit_xor(x.b4,y.b4),c3);
   struct bit s5 = bit_xor(bit_xor(x.b5,y.b5),c4);
   struct bit s6 = bit_xor(bit_xor(x.b6,y.b6),c5);
   struct bit s7 = bit_xor(bit_xor(x.b7,y.b7),c6);

   // Definerer den endelige 8-bit efter addition
   s.b0 = s0;
   s.b1 = s1;
   s.b2 = s2;
   s.b3 = s3;
   s.b4 = s4;
   s.b5 = s5;
   s.b6 = s6;
   s.b7 = s7;

   // Returnerer den endelige 8-bit efter addition
   return s;

};

