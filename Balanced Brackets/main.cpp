//
//  main.cpp
//  Balanced Brackets
//
//  Created by Josh Collins on 10/18/17.
//  Copyright © 2017 Josh Collins. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

bool is_balanced(string expression) {
    
    /*
     This function works by pushing onto the stack
     the opposite of the character it reads from the string
     (which it read character by character). It then checks
     to see if when popped that there is something on the stack
     and that it is the same char, if not it returns false.
     */
    
    stack <char> s;
    for(char c : expression)   {
        switch(c)  {
            case '(': s.push(')');
                // DEBUG : cout << "PUSHED )" << endl;
                break;
            case '{': s.push('}');
                // DEBUG : cout << "PUSHED }" << endl;
                break;
            case '[': s.push(']');
                // DEBUG : cout << "PUSHED ]" << endl;
                break;
            default: if(s.size() == 0 || c != s.top())
                return false;
            else   {
                s.pop();
                // DEBUG : cout << "POPPED " << c << endl;
            }
        }
    }
    
    //Check if there's anything left
    if(s.size() == 0)
        return true;
    else
        return false;
    
}

int main(){
    
    /*
     This function reads a number from standard
     input for the number of lines, and then reads line by line
     and checks if the brackets in the lines are equal. Only checks for
     {, [, (, ), ], }, though more can be added later.
     */
    
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
