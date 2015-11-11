#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__
#include <iostream>
class tictactoe{
private:
    int *board_position;


public:
    int size_array;
    tictactoe(int user_specified_size){
        if((user_specified_size%2)==0 || user_specified_size==1){
            std::cout<<"\nEven sizes cannot be specified"<<std::endl;
            return;
        }
        board_position = new int(user_specified_size*user_specified_size);
        //player 0 gets to play first
        player_status=0;

        //initialize the positions
        size_array = user_specified_size*user_specified_size;
        for(int i = 0 ; i < size_array ; ++i){
            board_position[i] = -1; //-1 meaning not played yet
        }

    }
    ~tictactoe(){
        //clean up
    }
    bool player_status; //only two players so just 0-1 is enough
    bool check_if_winner();
    bool turn();

    bool display_board_status();
    bool check_if_tied();



};

#endif
