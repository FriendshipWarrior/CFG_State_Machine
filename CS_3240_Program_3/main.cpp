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
 
 S --> aSa|bSb|X
 X --> aYb|bYa
 Y --> aY|bY|lambda
*/
#include <iostream>
#include <deque>
#include <ctime>

using namespace std;

enum State {START, X, Y};
void cfg();

int main() {
    srand(time(NULL));              /* reset random numbers */
    for (int i = 0; i < 5; i++)     /* 5 random strings from the cfg */
        cfg();
    return 0;
}

/* context-free grammar function */
void cfg(){
    State state = START;
    deque<char> mydeque;
    mydeque.clear();
    switch (state) {
        case START:
            for(int i = 0; i < rand() % 5; i++){    /* S aSa */
                mydeque.push_front('a');
                mydeque.push_back('a');
            }
            for(int j = 0; j < rand() % 5; j++){    /* S bSb */
                mydeque.push_front('b');
                mydeque.push_back('b');
            }
            state = X;
            //break;
        case X:
            for(int k = 0; k < rand() % 5; k++){    /* X aYb */
                mydeque.push_front('a');
                mydeque.push_back('b');
            }
            for(int l = 0; l < rand() % 5; l++){    /* X bYa */
                mydeque.push_front('b');
                mydeque.push_back('a');
            }
            state = Y;
            //break;
        case Y:
            for(int m = 0; m < rand() % 5; m++)     /* aY */
                mydeque.push_front('a');
            for(int n = 0; n < rand() % 5; n++)     /* bY */
                mydeque.push_front('b');
            for(int o = 0; o < mydeque.size(); o++)
                cout << mydeque[o];                 /* print contents of the deque */
            break;
        default:
            break;
    }
    cout << "\n";
}
