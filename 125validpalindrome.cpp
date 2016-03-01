//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome. 
//
//
ass Solution {
public:
    bool isPalindrome(string s) 
    {
        string scopy;
        for ( int i = 0; i < s.size(); i++)
        {
            if ((s[i] >='a' && s[i] <= 'z') || ( s[i] >='A' && s[i] <= 'Z') || ( s[i] >='0' && s[i] <= '9'))
            {
                scopy.push_back(s[i]);
            }
        }
        
        int i = 0, j = scopy.size()-1;
        
        while( i < j)
        {
            char temp1;
            if ((scopy[i] >='a' && scopy[i] <= 'z'))
            {
                temp1 = scopy[i];
            }
            else if ((scopy[i] >='A' && scopy[i] <= 'Z'))
            {
                temp1 = scopy[i] - 'A' +'a';
            }
            else if ((scopy[i] >='0' && scopy[i] <= '9'))
            {
                temp1 = scopy[i] ;
            }
            
            
            char temp2;
            if ((scopy[j] >='a' && scopy[j] <= 'z'))
            {
                temp2 = scopy[j];
            }
            else if ((scopy[j] >='A' && scopy[j] <= 'Z'))
            {
                temp2 = scopy[j] - 'A' + 'a';
            }
            else if ((scopy[j] >='0' && scopy[j] <= '9'))
            {
                temp2 = scopy[j] ;
            }
            
            if ( temp1 == temp2)
            {
                i++;
                j--;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
};
