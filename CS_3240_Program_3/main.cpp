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

using namespace std;

enum State {S, aSa, bSb, X, aYb, bYa, aY, bY, Y};
deque<char> mydeque;
void cfg();

int main(int argc, const char * argv[]) {
    srand(time(NULL));              /* reset random numbers */
    for (int i = 0; i < 5; i++)     /* 5 random strings from the cfg */
        cfg();
    return 0;
}

/* context-free grammar function */
void cfg(){
    State state = S;
    mydeque.clear();
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
                mydeque.push_front('a');
                mydeque.push_back('a');
                if(ran == 0)
                    state = aSa;
                else if(ran == 1)
                    state = bSb;
                else
                    state = X;
                break;
            case bSb:
                ran = rand() % 3;
                mydeque.push_front('b');
                mydeque.push_back('b');
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
                mydeque.push_front('a');
                mydeque.push_back('b');
                if(ran == 0)
                    state = aY;
                else if(ran == 1)
                    state = bY;
                else
                    state = Y;
                break;
            case aY:
                ran = rand() % 3;
                mydeque.push_front('a');
                if(ran == 0)
                    state = aY;
                else if(ran == 1)
                    state = bY;
                else
                    state = Y;
                break;
            case bY:
                ran = rand() % 3;
                mydeque.push_front('b');
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
    
    for(int i = 0; i <= mydeque.size(); i++)
        cout << mydeque[i];
    cout << "\n";
}
