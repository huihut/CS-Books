/* usehotel.c -- room rate program */
/* compile with  Listing 9.10      */
#include <stdio.h>
#include "hotel.h" /* defines constants, declares functions */

int main(void)
{
   int nights;
   double hotel_rate;
   int code;

   while ((code = menu()) != QUIT)
   {
      switch(code)
      {
      case 1 : hotel_rate = HOTEL1;
               break;
      case 2 : hotel_rate = HOTEL2;
               break;
      case 3 : hotel_rate = HOTEL3;
               break;
      case 4 : hotel_rate = HOTEL4;
               break;
      default: hotel_rate = 0.0;
               printf("Oops!\n");
               break;
      }
      nights = getnights();
      showprice(hotel_rate, nights);
   }
   printf("Thank you and goodbye.");
   
   return 0;
}
