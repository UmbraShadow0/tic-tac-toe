#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    int i = 1;
    bool win = false;
    //Display initial grid
    std::vector<std::vector<std::string>> matrix = grid();
    display_grid(matrix);
    while (win == false)
    {
        if (i%2==0){
            //Player 2 play
            std::vector<int> selec = dialogue(2);
            matrix = play(selec[0], selec[1], 2,  matrix);
            display_grid(matrix);
            i++;
            win = winner_cases(2, matrix, i); 
        }
        else{
            //Player 1 play
            std::vector<int> selec = dialogue(1);
            matrix = play(selec[0], selec[1],  1, matrix);
            display_grid(matrix);
            i++;
            win = winner_cases(1, matrix, i);
            
        }
    }
}