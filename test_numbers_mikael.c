#include <stdlib.h>
#include "numbers_mikael.h"
#include <stdio.h>
 



 

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


