#include "tictactoe.hxx"
#include <iostream>
#include <math.h>
#include <limits>
bool tictactoe::display_board_status(){

    // display the board using the current status of the array
    //check size of array -- future proof
    int size_array =0;
    size_array=this->size_array;

    if(size_array>0){

    int num_cols_rows =sqrt(size_array);
    //std::cout<<"\n"<<num_cols_rows<<std::endl;

    for(int i = 0; i < size_array; ++i){
        if((i%(num_cols_rows))==0){
            std::cout<<"\n";
        }
        if(this->board_position[i]==0){
        std::cout<<" || "<<" X "<<" || ";
        }else if(this->board_position[i]==1){
            std::cout<<" || "<<" O "<<" || ";
        }else if(this->board_position[i]==-1){
            std::cout<<" || "<<" n/a "<<" || ";
        }
    }
    std::cout<<"\n";
    return 1;
    }else{
        return 0;
    }

}

bool tictactoe::turn(){
    int pos_value_entered=-1;
        //pos_value_entered=-1;

        //check all -1s and display those as the only possible inputs


        do{
        std::cout<<"\n Player : " <<this->player_status<<" : Please enter the position where you want to play (valid options are: ";
        for(int i = 0 ; i<this->size_array; ++i){
            if(this->board_position[i]==-1){
                std::cout<<" "<<i<<" ";
            }
        }
        std::cout<<")"<<std::endl;
        std::cin>>pos_value_entered;
        if(std::cin.fail()){
            pos_value_entered=-1;
            std::cin.clear();
            std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );

        }
    }while(pos_value_entered<0 || pos_value_entered>this->size_array-1 || this->board_position[pos_value_entered]!=-1);

    //valid input so place the value and then switch turns with the other player

    this->board_position[pos_value_entered] = this->player_status;
    this->player_status = !(this->player_status);

return 0;
}


int main(){


    //
        int specified_board_size;
        std::cout<<"\nYou are now playing tictactoe!... '-1's indicate that the position hasn't been played '0' is Player 1 and '1' is Player 2"<<std::endl;
        std::cout<<"\n Please specify the board size (needs to be an odd number and not 1)"<<std::endl;
        std::cin>>specified_board_size;
        tictactoe *tictactoe_session = (tictactoe *) new class tictactoe(specified_board_size);
        if(tictactoe_session==NULL){
            std::cout<<"\nCouldn't allocate memory"<<std::endl;
            return -1;
        }

        if (tictactoe_session->size_array!=specified_board_size*specified_board_size){
            std::cout<<"\nCouldn't allocate for given size"<<std::endl;
            return -1;
        }


        tictactoe_session->display_board_status();
    return 0;
}
