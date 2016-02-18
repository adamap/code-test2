//Implement pow(x, n).
class Solution {
public:
double myPow(double x, int n) 
{
  if (n == 0)
  {
    return 1;
  }
  if (n == 1)
  {
    return x;
  }
  long long ratio = 1;
  double result = 1; 

   int neg = 0;
   long long power_factor = n;
   if (n < 0)
   {
     neg = 1;
     power_factor = -power_factor;
   } 

   while (ratio * 2 < power_factor)
   {
     double temp = x;

     while (ratio * 2 < power_factor)
     {
       temp = temp*temp;
       ratio = ratio * 2;
     }
     result *= temp;
     power_factor = power_factor - ratio;
     ratio = 1;
   }  

   if (power_factor == 1)
   {
     result = result*x;
   }
   if (power_factor == 2)
   {
     result = result*x*x;
   }

   if (neg == 1)
   { 
     return 1.0f / result;
   }
   return result;
 }
}; 
