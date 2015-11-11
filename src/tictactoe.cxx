#include "tictactoe.hxx"
#include <iostream>
#include <math.h>
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


int main(){
    return 0;
}
