#include <iostream>
#include <stack>
using namespace std;

int pr_onstack(char kr)     //it returns relative precedence 
//of operators which is on stack
{
    if (kr == '^')
        return 5;
    else if (kr == '*' || kr == '/')
        return 4;
    else if (kr == '-' || kr == '+')
        return 1;
    else
        return 0;
}
int pr_onstirng(char kr)  //it returns relative precedence 
//of operators which is on string(equation)
{
    if (kr == '^')
        return 6;
    else if (kr == '*' || kr == '/')
        return 3;
    else if (kr == '-' || kr == '+')
        return 2;
    else
        return 0;
}


string infix_to_postfix(string s) //function for convert infix equation to postfix equation
//string s for take input (infix equation)
{
    string ans;         //ans string for store and return postfix equation
    stack<char> sta;    //sta stack store operators for while
    int k = s.length();
    for (int i = 0; i < k; i++)
    {
        char ccc = s[i];
        if (ccc == '^' || ccc == '*' || ccc == '/' || ccc == '+' || ccc == '-')
        {
            if ((sta.empty() != 1) && (pr_onstack(sta.top())) > (pr_onstirng(ccc)))
            {
                ans += sta.top();
                ans +=',';
                sta.pop();
            }
            sta.push(ccc);
        }
        else if (ccc == '(')
        {
            sta.push(ccc);
        }
        else if (ccc == ')')
        {
            while (sta.top() != '(')
            {
                ans += sta.top();
                ans +=',';
                sta.pop();
            }
            sta.pop();
        }
        else if(ccc=='.')
        {
            ans +='.';
        }
        else
        {
            ans += ccc;
            if (!(s[i+1] - 48 <= 9 && s[i+1] - 48 >= 0)&& s[i+1]!='.')
            ans +=',';// , for saperate each operand 
        }
    }
    while (!sta.empty())
    {
        ans += sta.top();
        ans +=',';   // , for saperate each operator 
        sta.pop();
    }
  
    return ans;  //ans=> postfix equation 
}


// int main()
// {
//     string s=infix_to_postfix("0.001^0.5");
//     cout<<"postix conversion is"<<s<<endl;
// }