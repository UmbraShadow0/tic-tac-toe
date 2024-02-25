#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    bool conclusion = false;
    int i = 1;
    bool win = false;
    //Display initial grid
    std::vector<std::vector<std::string>> matrix = grid();
    display_grid(matrix);
    while (conclusion == false)
    {
  
        if (i%2==0){
            //Player 2 play
            std::vector<int> selec = dialogue();
            matrix = play(selec[0], selec[1], 2,  matrix);
            display_grid(matrix);
            if (win == true){
                std::cout<< "Winner\n";
               
            }
            else {
                conclusion = true;
                i++;
            }
        }
        else{
            //Player 1 play
            std::vector<int> selec = dialogue();
            matrix = play(selec[0], selec[1],  1, matrix);
            display_grid(matrix);
            if (win == true){
                std::cout<< "Winner\n";
            }
              else {
                i++;
            }
            
        }
    }
    std::cout << "Test7\n";
}