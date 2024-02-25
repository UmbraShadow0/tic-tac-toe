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
std::vector<std::vector<std::string>> grid() {
    return {{" ","|"," ","|"," "},
    {"-","|","-", "|","-"},
    {" ","|"," ","|"," "},
    {"-","|","-", "|","-"},
    {" ","|"," ","|"," "}};
};

std::vector<int> dialogue(){
    int row;
    int line;
    std::cout << "\nPlayer 1 turn:\n";
    std::cout << "\nSelected Line\n";
    std::cin >> line;
    std::cout << "\nSelected Row\n";
    std::cin >> row;
    std::vector<int> selection = {line, row};
    return  selection;
};

std::vector<std::vector<std::string>> play(int num1, int num2, int num3, std::vector<std::vector<std::string>> grid) {
    num1= num1 + (num1-1)-1;
    num2= num2 + (num2-1)-1;
    if (num3 == 1){
        grid[num1][num2] += "x";
        return grid;
    }
    else {
        grid[num1][num2] += "O";
        return grid;
    }
};
