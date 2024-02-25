#include <iostream>
#include <vector>

//Display the grid
void display_grid(std::vector<std::vector<std::string>> grid) {
    // Iterate lines and collumns for each iteration
    for (int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            std::cout << grid[i][j];
        }
    std::cout << "\n";
}
};

//Create the grid for the game
void grid() {
    std::vector<std::vector<std::string>> matrix={{" ","|"," ","|"," "},
    {"-","|","-", "|","-"},
    {" ","|"," ","|"," "},
    {"-","|","-", "|","-"},
    {" ","|"," ","|"," "}};

    //Call the display function
    display_grid(matrix);
};

