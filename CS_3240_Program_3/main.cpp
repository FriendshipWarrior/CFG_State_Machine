//
//  main.cpp
//  CS_3240_Program_3
//
//  Created by Dustin Hurst on 3/17/15.
//  Copyright (c) 2015 Dustin Hurst. All rights reserved.
//

#include <iostream>
using namespace std;
void cfg();
int main(int argc, const char * argv[]) {
    cfg();
    return 0;
}

void cfg(){
    enum State {START, X, Y};
    State state = START;
    
    switch (state) {
        case START:
            
            break;
        case X:
            break;
        case Y:
            break;
        default:
            break;
    }
}