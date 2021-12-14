//
//  eval.cpp
//  HW 2
//
//  Created by Anica Wang on 1/28/21.
//

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

bool isValid(string &infix);

int precedence(char c);

string convert(string &infix);

int evaluate(string infix, const bool values[], string& postfix, bool& result)
      // Evaluates a boolean expression
      //   If infix is a syntactically valid infix boolean expression,
      //   then set postfix to the postfix form of that expression, set
      //   result to the value of the expression (where in that expression,
      //   each digit k represents element k of the values array), and
      //   return zero.  If infix is not a syntactically valid expression,
      //   return 1.  (In that case, postfix may or may not be changed, but
      //   result must be unchanged.)
{
    if (isValid(infix) == false)
    {
        return 1;
    }

    postfix = convert(infix);
    stack<bool> myStack;
    
    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' ||
            ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
        {
            int index = ch - '0';
            myStack.push(values[index]);
            result = values[index];
        }
        else if (ch == '!')
        {
            char operand = myStack.top();
            myStack.pop();
            result = !operand;
            myStack.push(result);
        }
        else if (ch == '&' || ch == '|')
        {
            char operand2 = myStack.top();
            myStack.pop();
            char operand1 = myStack.top();
            myStack.pop();
            if (ch == '&')
            {
                result = operand1 & operand2;
                myStack.push(result);
            }
            else if (ch == '|')
            {
                result = operand1 | operand2;
                myStack.push(result);
            }
        }
    }
    return 0;
}

string convert(string &infix)
{
    string post = "";
    stack<char> myStack;
    
    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];
        switch(ch)
        {
            //case operand
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                post += ch;
                break;
            }
            //open paren
            case '(':
            {
                myStack.push(ch);
                break;
            }
            //close paren
            case ')':
            {
                while (myStack.top() != '(')
                {
                    post += myStack.top();
                    myStack.pop();
                }
                myStack.pop();
                break;
            }
            case '&':
            case '|':
            case '!':
            {
                while (myStack.empty() == false && myStack.top() != '(' && precedence(ch) <= precedence(myStack.top()))
                {
                    post += myStack.top();
                    myStack.pop();
                }
                myStack.push(ch);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    while (myStack.empty() == false)
    {
        post += myStack.top();
        myStack.pop();
    }
    return post;
}

bool isValid(string &infix)
{
    //remove all spaces
    string temp = "";
    for (int a = 0; a < infix.size(); a++)
    {
        if (!isspace(infix[a]))
        {
            temp += infix[a];
        }
    }
    infix = temp;
    
    int nums = 0;
    int operators = 0;
    int openParens = 0;
    int closeParens = 0;
    
    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]) == true)
        {
            nums++;
        }
        else if (infix[i] == '&' || infix[i] == '|')
        {
            operators++;
        }
        else if (infix[i] == '(')
        {
            openParens++;
        }
        else if (infix[i] == ')')
        {
            closeParens++;
        }
        else if (infix[i] != '&' && infix[i] != '!' && infix[i] != '|' && isdigit(infix[i]) == false)
        {
            return false;
        }
        if (openParens < closeParens)
        {
            return false;
        }
    }
    //check number of operators and parens are correct
    if (((nums != operators + 1) || openParens != closeParens) || nums == 0)
    {
        return false;
    }
    
    if (infix[0] == ')' || infix[0] == '&' || infix[0] == '|')
    {
        return false;
    }
    if (infix[infix.size() - 1] == '!' || infix[infix.size() - 1] == '|' ||
        infix[infix.size() - 1] == '&' || infix[infix.size() - 1] == '(')
    {
        return false;
    }
    
    for (int j = 0; j < infix.size(); j++)
    {
        if (!isdigit(infix[j]) && (infix[j] != '!' && infix[j] != '|' && infix[j] != '&' && infix[j] != '(' && infix[j] != ')'))
        {
            return false;
        }
        
        if (isdigit(infix[j]) && isdigit(infix[j + 1]))
        {
            return false;
        }
        
        if (infix[j] == '(')
        {
            if (infix[j + 1] != '!' && !isdigit(infix[j + 1]) && infix[j + 1] != '(')
            {
                return false;
            }
        }
        
        if (infix[j + 1] == ')')
        {
            if (!isdigit(infix[j]) && infix[j] != ')')
            {
                return false;
            }
        }
        
        if (infix[j] == '!')
        {
            if (infix[j + 1] != '(' && !isdigit(infix[j + 1]) && infix[j + 1] != '!')
            {
                return false;
            }
        }
        
        if (infix[j] == '&')
        {
            if (infix[j + 1] == '&' || infix[j + 1] == '|')
            {
                return false;
            }
        }
        
        if (infix[j] == '|')
        {
            if (infix[j + 1] == '&' || infix[j + 1] == '|')
            {
                return false;
            }
        }
        
        if (infix.size() == 1)
        {
            if (isdigit(infix[0]))
            {
                return true;
            }
        }
    }
    return true;
}

int precedence(char c)
//binary boolean infix operators & (meaning and) and | (meaning inclusive or), the unary boolean prefix operator ! (meaning not), parentheses, and operands (with blanks allowed for readability). Following convention, ! has higher precedence than &, which has higher precedence than |, and operators of equal precedence associate left to right.
{
    int p = 0;
    if (c == '|')
    {
        p = 1;
    }
    else if (c == '&')
    {
        p = 2;
    }
    else if (c == '!')
    {
        p = 3;
    }
    return p;
}

int main()
{
    bool ba[10] = {
      //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    string pf;
    bool answer;
    assert(evaluate(")9(", ba, pf, answer) == 1);
    assert(evaluate("1&!(9|1&1|9) | !!!(9&1&9)", ba, pf, answer) == 0 && answer);
    assert(evaluate("2 & !(!3)", ba, pf, answer) == 0 && !answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
    assert(evaluate("8|", ba, pf, answer) == 1);
    assert(evaluate(" &6", ba, pf, answer) == 1);
    assert(evaluate("4 5", ba, pf, answer) == 1);
    assert(evaluate("01", ba, pf, answer) == 1);
    assert(evaluate("()", ba, pf, answer) == 1);
    assert(evaluate("()4", ba, pf, answer) == 1);
    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
    assert(evaluate("2(&8)", ba, pf, answer) == 1);
    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
    assert(evaluate("x+5", ba, pf, answer) == 1);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(evaluate("2|3|4", ba, pf, answer) == 0
                           &&  pf == "23|4|"  &&  answer);
    assert(evaluate("2|(3|4)", ba, pf, answer) == 0
                           &&  pf == "234||"  &&  answer);
    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
                           &&  pf == "43!03&&|"  &&  !answer);
    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
    ba[2] = false;
    ba[9] = true;
    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
    cout << "Passed all tests" << endl;
}
