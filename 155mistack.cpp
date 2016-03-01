//
//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. 
// push(x) -- Push element x onto stack. 
// pop() -- Removes the element on top of the stack. 
// top() -- Get the top element. 
// getMin() -- Retrieve the minimum element in the stack. 
//


class MinStack {
    stack<int>s1;
    stack<int>s2;
public:
    void push(int x) 
    {
        s1.push(x);
        if (s2.empty())
        {
            s2.push(x);
        }
        else
        {
            s2.push(min(x, s2.top()));
        }
    }

    void pop() 
    {
        s1.pop();
        s2.pop();
        
    }

    int top() 
    {
        return s1.top();
    }

    int getMin() 
    {
        return s2.top();
    }
};
