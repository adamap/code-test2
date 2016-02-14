//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example, 
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".
//
class Solution {
public:
string fractionToDecimal(int numerator, int denominator) 
{
    long long num = numerator, denom = denominator;
    ostringstream ostr;
    int neg = 0;
    if (num < 0 && denom < 0)
    {
      num = -num;
      denom = -denom;
    }
    else if (num < 0 || denom < 0)
    {
      neg = 1;
      if (num < 0)
      {
        num = -num;
      }

     if (denom < 0)
     {
       denom = -denom;
     }
    if ( num > 0)
    {
      ostr << "-";
    }
  }

  ostr << (num / denom);
  long long remain = num%denom;
  if (remain == 0)
  {
    return ostr.str();
  }  
  ostr << ".";

  vector<long long>ret;
  unordered_map<long long, int>map;

  for (int i = 0; remain && map.find(remain) == map.end(); i++)
  {
    long long temp = (remain * 10) / denom;
    ret.push_back(temp);
    map[remain] = i;

    remain = (remain * 10) % denom;
  }

  if (remain == 0)
  {
    for (int i = 0; i < ret.size(); i++)
    {
      ostr << ret[i];
    }
  }
  else
  {
    int index = map[remain];
    for (int i = 0; i < index; i++)
    {
      ostr << ret[i];
    }   

    ostr << "(";
    for (int i = index; i < ret.size(); i++)
    {   
      ostr << ret[i];
    }
    ostr << ")";
  }
  return ostr.str();
  }
};
