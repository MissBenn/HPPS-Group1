#include <stdlib.h>
#include "numbers_mikael.h"
#include <stdio.h>
 


struct bits8 random_bits8(){
  struct bits8 x;

  srand(time(NULL));// use different seeds. 
  x.b0=bit_from_int(rand()%2);
  x.b1=bit_from_int(rand()%2);
  x.b2=bit_from_int(rand()%2);
  x.b3=bit_from_int(rand()%2);
  x.b4=bit_from_int(rand()%2);
  x.b5=bit_from_int(rand()%2);
  x.b6=bit_from_int(rand()%2);
  x.b7=bit_from_int(rand()%2);

  return x;

}


unsigned int bits8_to_int(struct bits8 x){

unsigned int y=0;
y=(bit_to_int(x.b0)<<0)+(bit_to_int(x.b1) <<1)+(bit_to_int(x.b2)<<2)
 +(bit_to_int(x.b3)<<3)+(bit_to_int(x.b4)<<4)+(bit_to_int(x.b5)<<5)
 +(bit_to_int(x.b6)<<6)+(bit_to_int(x.b7)<<7);

 return y;

}

struct bits8 bits8_from_int(unsigned int x){
  struct bits8 y;
  y.b0=bit_from_int(((x>>0) &1));
  y.b1=bit_from_int(((x>>1) &1));
  y.b2=bit_from_int(((x>>2) &1));
  y.b3=bit_from_int(((x>>3) &1));
  y.b4=bit_from_int(((x>>4) &1));
  y.b5=bit_from_int(((x>>5) &1));
  y.b6=bit_from_int(((x>>6) &1));
  y.b7=bit_from_int(((x>>7) &1));

   return y;
}

struct bits8 bits8_add(struct bits8 x, struct bits8 y){
  struct bits8 z;
  struct bit c;
  z.b0=bit_xor(x.b0, y.b0);
  c=bit_and(x.b0,y.b0);//c=bit_from_int(bit_to_int(x.b0)& bit_to_int(y.b0));
  z.b1=bit_xor(bit_xor(x.b1, y.b1),c);
  c=bit_or(bit_and(x.b1, y.b1), bit_and(bit_or(x.b1, y.b1),c));
  z.b2=bit_xor(bit_xor(x.b2, y.b2),c);
  c=bit_or(bit_and(x.b2, y.b2), bit_and(bit_or(x.b2, y.b2),c));
  z.b3=bit_xor(bit_xor(x.b3, y.b3),c);
  c=bit_or(bit_and(x.b3, y.b3), bit_and(bit_or(x.b3, y.b3),c));
  z.b4=bit_xor(bit_xor(x.b4, y.b4),c);
  c=bit_or(bit_and(x.b4, y.b4), bit_and(bit_or(x.b4, y.b4),c));
  z.b5=bit_xor(bit_xor(x.b5, y.b5),c);
  c=bit_or(bit_and(x.b5, y.b5), bit_and(bit_or(x.b5, y.b5),c));
  z.b6=bit_xor(bit_xor(x.b6, y.b6),c);
  c=bit_or(bit_and(x.b6, y.b6), bit_and(bit_or(x.b6, y.b6),c));
  z.b7=bit_xor(bit_xor(x.b7, y.b7),c);
  c=bit_or(bit_and(x.b7, y.b7), bit_and(bit_or(x.b7, y.b7),c));

  return z;



 


}


 struct bits8 flip_bits(struct bits8 x){
  struct bits8 y;
  y.b0=bit_not(x.b0);
  y.b1=bit_not(x.b1);
  y.b2=bit_not(x.b2);
  y.b3=bit_not(x.b3);
  y.b4=bit_not(x.b4);
  y.b5=bit_not(x.b5);
  y.b6=bit_not(x.b6);
  y.b7=bit_not(x.b7);

  return y;

}

 struct bits8 constant_one(){
  struct bits8 x;
  x.b0=bit_from_int(1);
  x.b1=bit_from_int(0);
  x.b2=bit_from_int(0);
  x.b3=bit_from_int(0);
  x.b4=bit_from_int(0);
  x.b5=bit_from_int(0);
  x.b6=bit_from_int(0);
  x.b7=bit_from_int(0);

  return x;

}

struct bits8 bits8_negate(struct bits8 x){
  struct bits8 x_flipped=flip_bits(x);
  struct bits8 CONST_1=constant_one();
  
  return bits8_add(x_flipped,CONST_1);

}


int tc_to_int(struct bits8 x){

  int y=0;
  y=(bit_to_int(x.b0)<<0)+(bit_to_int(x.b1) <<1)+(bit_to_int(x.b2)<<2)
  +(bit_to_int(x.b3)<<3)+(bit_to_int(x.b4)<<4)+(bit_to_int(x.b5)<<5)
  +(bit_to_int(x.b6)<<6)
  -(bit_to_int(x.b7)<<7);

  return y;

}
 
struct bits8 bits8_from_tc(int x){
  struct bits8 y;
  if(x<0)
    y=bits8_from_int((unsigned)x);
  else
    y= bits8_negate(bits8_from_int((unsigned) abs(x)));

   return y;
}

struct bits8 bits8_and_bit(struct bits8 x, struct bit y){
  struct bits8 z;
  z.b0=bit_and(x.b0,y);
  z.b1=bit_and(x.b1,y);
  z.b2=bit_and(x.b2,y);
  z.b3=bit_and(x.b3,y);
  z.b4=bit_and(x.b4,y);
  z.b5=bit_and(x.b5,y);
  z.b6=bit_and(x.b6,y);
  z.b7=bit_and(x.b7,y);

  return z;


}


struct bits8 bits8_mul(struct bits8 x, struct bits8 y){
  struct bits8 z; 

  z=bits8_from_int( 
   (bits8_to_int(bits8_and_bit(x,  y.b0))<<0)
  +(bits8_to_int(bits8_and_bit(x,  y.b1))<<1)
  +(bits8_to_int(bits8_and_bit(x,  y.b2))<<2)
  +(bits8_to_int(bits8_and_bit(x,  y.b3))<<3)
  +(bits8_to_int(bits8_and_bit(x,  y.b4))<<4)
  +(bits8_to_int(bits8_and_bit(x,  y.b5))<<5)
  +(bits8_to_int(bits8_and_bit(x,  y.b6))<<6)
  +(bits8_to_int(bits8_and_bit(x,  y.b7))<<7)
  );
  
 

  return z;

}

 

int main() {
  // TODO
  struct bits8 x=random_bits8();
  struct bits8 y=flip_bits(x);
  unsigned int z= bits8_to_int(x);
  struct bits8 v=bits8_from_int(z);

  struct bits8 x2=random_bits8();
  unsigned int z2= bits8_to_int(x2);

  struct bits8 x12=bits8_add(x, x2);
  unsigned int z12= bits8_to_int(x12);

  struct bits8 m12= bits8_mul(x, x2);
  unsigned int n12= bits8_to_int(m12);
   
  
  printf("\n%5s%5s%5s%5s%5s%5s%5s%5s\n ", "b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7");
  printf("\n%5d%5d%5d%5d%5d%5d%5d%5d\n",bit_to_int(x.b0),bit_to_int(x.b1),bit_to_int(x.b2),bit_to_int(x.b3),bit_to_int(x.b4),bit_to_int(x.b5),bit_to_int(x.b6),bit_to_int(x.b7)  );
  printf("\n%5d%5d%5d%5d%5d%5d%5d%5d\n",bit_to_int(y.b0),bit_to_int(y.b1),bit_to_int(y.b2),bit_to_int(y.b3),bit_to_int(y.b4),bit_to_int(y.b5),bit_to_int(y.b6),bit_to_int(y.b7)  );
  printf("\n%5s\n","Bits2N(x)");
  printf("\n%5d\n",z);
  printf("\n%5s%5s%5s%5s%5s%5s%5s%5s\n ", "b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7");
  printf("\n%5d%5d%5d%5d%5d%5d%5d%5d\n",bit_to_int(v.b0),bit_to_int(v.b1),bit_to_int(v.b2), bit_to_int(v.b3),bit_to_int(v.b4),bit_to_int(v.b5),bit_to_int(v.b6),bit_to_int(v.b7)  );

  printf("\n%5s\n","Bits2N(x2)");
  printf("\n%5d\n",z2);
  printf("\n%5s%d\n","x+x2=",z12);

  printf("\n%5s%d\n","x*x2=",n12);

  // char c1,c2,c3;
  // int i1;
  // float f1;
  // printf("\n%s\n%s\n","Input three characters,", "An int and a float");
  // scanf("%c%c%c%d%f", &c1,&c2,&c3,&i1,&f1);
  // printf("Here is the data you typed in: \n");
  // printf("%3c%3c%3c%5d%17e\n\n", c1,c2,c3,i1,f1);

}


