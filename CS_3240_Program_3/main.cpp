//
//  main.cpp
//  CS_3240_Program_3
//
//  Created by Dustin Hurst on 3/17/15.
//  Copyright (c) 2015 Dustin Hurst. All rights reserved.
//
/*
 This program reads an arbitrary context-free grammar and derives strings from the grammar.
 We will use the following non-plaindrome for the input:
 
 S -> aSa|bSb|X
 X -> aYb|bYa
 Y -> aY|bY|lambda
*/

#include <iostream>
#include <deque>
#include <ctime>
#include <map>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

enum State {S, aSa, bSb, X, aYb, bYa, aY, bY, Y, A, B, Lambda};
vector<char> vec;
void cfg();
void cfg_129();

int main(int argc, const char * argv[]) {
    srand(time(NULL));              /* reset random numbers */
    
    cout << vec.size() << endl;
    for (int i = 0; i < 5; i++)      /* 5 random strings from the cfg */
        cfg();

    cfg_129();
    
    cout << endl;
    return 0;
}

/* context-free grammar function */
void cfg(){
    State state = S;
    vec.clear();
    int ran;
    do{
        switch (state) {
            case S:
                ran = rand() % 3;
                if(ran == 0)
                    state = aSa;
                else if(ran == 1)
                    state = bSb;
                else
                    state = X;
                break;
            case aSa:
                ran = rand() % 3;
                vec.push_back('a');
                vec.push_back('a');
                cout << vec.back();
                vec.pop_back();
                if(ran == 0)
                    state = aSa;
                else if(ran == 1)
                    state = bSb;
                else
                    state = X;
                break;
            case bSb:
                ran = rand() % 3;
                vec.push_back('b');
                vec.push_back('b');
                cout << vec.back();
                vec.pop_back();
                if(ran == 0)
                    state = aSa;
                else if(ran == 1)
                    state = bSb;
                else
                    state = X;
                break;
            case X:
                ran = rand() % 2;
                if(ran == 0)
                    state = aYb;
                else if(ran == 1)
                    state = bYa;
            case aYb:
                ran = rand() % 3;
                vec.push_back('a');
                vec.push_back('b');
                cout << vec.back();
                vec.pop_back();
                if(ran == 0)
                    state = aY;
                else if(ran == 1)
                    state = bY;
                else
                    state = Y;
                break;
            case aY:
                ran = rand() % 3;
                vec.push_back('a');
                cout << vec.back();
                vec.pop_back();
                if(ran == 0)
                    state = aY;
                else if(ran == 1)
                    state = bY;
                else
                    state = Y;
                break;
            case bY:
                ran = rand() % 3;
                vec.push_back('b');
                cout << vec.back();
                vec.pop_back();
                if(ran == 0)
                    state = aY;
                else if(ran == 1)
                    state = bY;
                else
                    state = Y;
                break;
            default:
                break;
        }
    }while(state != Y);
    
    for(int i = 0; i <= vec.size(); i++){
        cout << vec[i];
        vec.pop_back();
    }
    cout << "\n";
}

/* cfg on page 129 */
void cfg_129(){
    State state = A;
    vec.clear();
    int ran;
    do{
        switch (state) {
            case A:
                ran = rand() % 2;
                vec.push_back('a');
                vec.push_back('a');
                for (int i = 0; i <= vec.size(); i++) {
                    cout << vec.back();
                    vec.pop_back();
                }
                if(ran == 0)
                    state = A;
                else
                    state = B;
                    break;
            case B:
                ran = rand() % 2;
                vec.push_back('b');
                cout << vec.back();
                vec.pop_back();
                if(ran == 0)
                    state = B;
                else
                    state = Lambda;
                break;
            default:
                break;
        }
    }while(state != Lambda);
}