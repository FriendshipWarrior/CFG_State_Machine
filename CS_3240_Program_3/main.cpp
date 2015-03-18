//
//  main.cpp
//  CS_3240_Program_3
//
//  Created by Dustin Hurst on 3/17/15.
//  Copyright (c) 2015 Dustin Hurst. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>

using namespace std;

enum State {START, X, Y};
void cfg();

int main() {
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
        cfg();
    return 0;
}

void cfg(){
    State state = START;
    deque<char> mydeque;
    mydeque.clear();
    switch (state) {
        case START:
            for(int i = 0; i < rand() % 5; i++){
                mydeque.push_front('a');
                mydeque.push_back('a');
            }
            for(int j = 0; j < rand() % 5; j++){
                mydeque.push_front('b');
                mydeque.push_back('b');
            }
            state = X;
            //break;
        case X:
            for(int k = 0; k < rand() % 5; k++){
                mydeque.push_front('a');
                mydeque.push_back('b');
            }
            for(int l = 0; l < rand() % 5; l++){
                mydeque.push_front('b');
                mydeque.push_back('a');
            }
            state = Y;
            //break;
        case Y:
            for(int m = 0; m < rand() % 5; m++)
                mydeque.push_front('a');
            for(int n = 0; n < rand() % 5; n++)
                mydeque.push_front('b');
            for(int o = 0; o < mydeque.size(); o++)
                cout << mydeque[o];
            break;
        default:
            break;
    }
    cout << "\n";
}
