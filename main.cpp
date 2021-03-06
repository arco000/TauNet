/*
(c) Matthew Slocum 2015

main.cpp bootstraps the program.
    loads up all the comonents of the program
    links the components together
    starts the program in either the menu or messenger depending on command line options

DEPENDENCIES:
boost::asio  [sudo apt-get install libboost-all-dev]
*/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include "regComponent.h"
#include "uiComponent.h"
#include "msgComponent.h"
#include "secComponent.h"

using namespace std;

msgComponent * msg = new msgComponent();
regComponent * reg = new regComponent();
secComponent * sec = new secComponent();
uiComponent * ui = new uiComponent();

int main(int argc, char *argv[]) {   
    msg->bind_regComponent(reg); 
    msg->bind_secComponent(sec);
    reg->bind_msgComponent(msg);    
    ui->bind_regComponent(reg);
    
    if(argc > 1 && string(argv[1])=="-msg") {       
        msg->run();
    } else {
        ui->run();
    }     

    delete msg;
    delete reg;
    delete sec;
    delete ui;
    
    return 1;
}
