//
//
//
//The API: int read4(char *buf) reads 4 characters at a time from a file. 
//
//The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file. 
//
//By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file. 
//
//Note:
// The read function will only be called once for each test case. 
//
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) 
    {
        if ( n == 0)
        {
            return 0;
        }
 
        int readnum = n/4 + ((n%4) > 0);
        int total_read = 0;
        
        for ( int i = 0; i < readnum; i++)
        {
            int act_read = read4(buf);
            
            total_read += act_read;
            
            if ( act_read < 4)
            {
                break;
            }
            
            buf = buf+act_read;
        }
        
        return min(n, total_read);
        
    }
};
