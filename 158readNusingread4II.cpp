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
// The read function may be called multiple times. 
//
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char internal_buf[4];
    int read_cnt = 0;
    int read_ptr = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) 
    {
        int total_read = 0;
        while(total_read < n)
        {
            if ( read_ptr == 0)
            {
                read_cnt = read4(internal_buf);
            }
            
            // read 0 so we reach to the end of file, break out of loop
            if ( read_cnt == 0)
            {
                break;
            }
            
            while(total_read < n && read_ptr < read_cnt)
            {
                buf[total_read++] = internal_buf[read_ptr++];
            }
            
            if ( read_ptr >= read_cnt)
            {
                read_ptr = read_cnt = 0;
            }
        }
        
        return total_read;
        
    }
};
