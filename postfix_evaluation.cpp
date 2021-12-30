#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

float power(float x, float y)
//power function for x^y where x is  base and y is its exponent
{
        float ans = 1;
        if (y-int(y)==0)
        {
            for (int i = 0; i < y; i++)
            {
                ans *= x;
            }
            return ans;
        }
        ans = pow(10, (y * log10(x)));
        return ans;
    }
    float make_number(stack<float> & s1tako, int num_count, int dot_count, bool num_is_negative)
    //make_number function takes  1 stack as argument which is filled with numbers each digit in perticuler manner
    //num_count for how many digits are used before dot ( ex 12.23  here num_count=2)
    //dot_count for how many digits are used after dot   ( ex 12.23  here dot_count=2)
    //bool num_is_negative is used to identify weather number is positive or negative.
    {
        float total = 0;
        if (dot_count)
        {
            for (int i = 0; i < dot_count; i++)
            {
                total += s1tako.top() * pow(10, -dot_count + i);
                s1tako.pop();
            }
        }
        for (int i = 0; i < num_count; i++)
        {
            total += power(10, i) * s1tako.top();

            s1tako.pop();
        }

        // if bool num_is_negative is true then it returns negative value otherwise positive
        if (num_is_negative)
            return total * -1;
        return total;
    }

    float postfix_evaluation(string s)
    {
        stack<float> stk_for_operand, stk_for_num;
        //here stk_for_operand is  to store operand for while
        int k = s.length();
        int num_count = 0, dot_count = 0;
        bool dot_bool = 0, num_is_negative = 0;
        for (int i = 0; i < k; i++)
        {
            float a, b; //for two binary operands
            if (s[i] == '+')
            {
                a = stk_for_operand.top();
                stk_for_operand.pop();
                b = stk_for_operand.top();
                stk_for_operand.pop();
                stk_for_operand.push(a + b);
            }
            else if (s[i] == '-')
            {

                if (s[i + 1] - 48 <= 9 && s[i + 1] - 48 >= 0)
                {

                    num_is_negative = 1;
                }
                else
                {

                    a = stk_for_operand.top();
                    stk_for_operand.pop();
                    if (stk_for_operand.empty())
                    {
                        stk_for_operand.push(a * -1);
                    }
                    else
                    {
                        b = stk_for_operand.top();
                        stk_for_operand.pop();
                        stk_for_operand.push(b - a);
                    }
                }
            }
            else if (s[i] == '*')
            {

                a = stk_for_operand.top();
                stk_for_operand.pop();
                b = stk_for_operand.top();
                stk_for_operand.pop();

                stk_for_operand.push(a * b);
            }
            else if (s[i] == '^')
            {
                a = stk_for_operand.top();
                stk_for_operand.pop();
                b = stk_for_operand.top();
                stk_for_operand.pop();

                stk_for_operand.push(power(b, a));
            }
            else if (s[i] == '/')
            {
                a = stk_for_operand.top();
                stk_for_operand.pop();
                b = stk_for_operand.top();
                stk_for_operand.pop();
                stk_for_operand.push(b / a);
            }
            else if (s[i] == ',')
            {
                if (num_count)
                {
                    stk_for_operand.push(make_number(stk_for_num, num_count, dot_count, num_is_negative));
                }
                num_count = dot_count = 0;
                dot_bool = 0;
                num_is_negative = 0;
                // cout<<"--------------------------------------------------------"<<endl;
            }
            else if (s[i] == '.')
            {

                dot_bool = 1;
            }

            else
            {
                //   cout<<"in num section"<<endl;
                stk_for_num.push(s[i] - 48);
                if (dot_bool)
                    dot_count++;
                else
                    num_count++;
            }
        }
        return stk_for_operand.top();
    }
    // int main()
    // {
    //     float ans;
    //    // ans=postfix_evaluation("1,2,-,"+to_string(i))+"*");
    //     ans=postfix_evaluation("0.001,0.5,^");
    //     cout<<" Answeer is "<<ans;
    //     return 0;
    // }
