#include "tictactoe.hxx"
#include <iostream>
#include <math.h>
#include <istream>
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

bool tictactoe::check_if_winner(){

    //if both diagonals or straight rows or cols have the same player value then the player wins
    //diagonal check is required only if the value entered is at the center

    int temp1 = -1;
    int temp2 = -1;
    unsigned int count_rows=0;
    unsigned int count_cols=0;
    unsigned int count_pos_diag=0;
    unsigned int count_neg_diag=0;
    temp1 = this->board_position[0];
    int num_rows_cols = 0;
    num_rows_cols = sqrt(this->size_array);
    int current_val=-1;
    int r,c,d,j=0;
    for( j = 0 ; j < this->size_array ; j=j+num_rows_cols){
    current_val=this->board_position[j];
    for( r =j+1 ; r <j+num_rows_cols ; ++r){
            if(current_val!=-1 && this->board_position[j]  == this->board_position[r]){
                count_rows++;
                current_val = this->board_position[j];
            }else{
                count_rows=0;
                break;
            }

            //check if win by rows

            if(count_rows==num_rows_cols-1){
                //declare winner
                std::cout<<"\n Win by rows"<<std::endl;
                this->player_status = current_val;
                return 1;
            }

        }
    }
    for( j = 0; j<num_rows_cols;++j){
   current_val = this->board_position[j];
    for(c = j+num_rows_cols ; c<this->size_array ; c = c+num_rows_cols){

        if(current_val!=-1 && this->board_position[j]  == this->board_position[c]){
            count_cols++;
            current_val = this->board_position[j];
        }else{
            count_cols=0;
            break;
        }

        //check if win by cols

        if(count_cols==num_rows_cols-1){
            //declare winner
            std::cout<<"\n Win by cols"<<std::endl;
            this->player_status = current_val;
            return 1;
        }


    }
}
    //diagonals need to be checked only once
    current_val = this->board_position[0];
    for(d=num_rows_cols+1;d<this->size_array;d=d+num_rows_cols+1){
        if(current_val!=-1 && current_val == this->board_position[d]){
            count_pos_diag++;
            current_val=this->board_position[d];
        }else{
            count_pos_diag=0;
            break;
        }

        if(count_pos_diag==num_rows_cols-1){
            //declare winner
            std::cout<<"\n Win by diagonal"<<std::endl;
            this->player_status=current_val;
            return 1;
        }

    }

    current_val = this->board_position[num_rows_cols-1];
    for(d=((num_rows_cols)*2)-2;d<this->size_array-1; d = d+num_rows_cols-1){
            if(current_val!=-1 && current_val==this->board_position[d]){
                count_neg_diag++;
            }else{
                count_neg_diag=0;
               break;
            }
        }
        if(count_neg_diag==num_rows_cols-1){
            //declare winner
            std::cout<<"\n Win by cross diagonal"<<std::endl;
            this->player_status=current_val;
            return 1;
        }


    std::cout<<"\n"<<count_cols<<count_rows<<count_neg_diag<<count_pos_diag<<"\n";
    return 0;

}

bool tictactoe::check_if_tied(){
//simply count the number of -1s and if its 0 and after check for winner then report tied..
    unsigned int count_valid_places=0;
    for(int i = 0; i<this->size_array; ++i){
        if(this->board_position[i]==-1){
           count_valid_places++;
        }

}

    if(count_valid_places==0){
        return 1;
    }else{
        return 0;
    }
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


          do{
            if(tictactoe_session->check_if_tied()){
                std::cout<<"\nIts a tie!"<<std::endl;
               return 0;

            }
            tictactoe_session->turn();


            //display the status
            tictactoe_session->display_board_status();

            //continue till someone wins or if its a tie

            }while(!tictactoe_session->check_if_winner());

        std::cout<<"\n Player : "<<tictactoe_session->player_status<<"  Wins!!!!!!!!!!!!"<<std::endl;
    return 0;
}
