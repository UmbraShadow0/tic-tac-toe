#include <iostream>
#include <vector>

//Display the grid
void display_grid(std::vector<std::vector<std::string>> grid) {
    // Iterate lines and collumns for each iteration
    std::cout << "\n\n";
    for (int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            std::cout << grid[i][j];
        }
    std::cout << "\n";
    }
    std::cout << "\n\n";
};

//Create the grid for the game
std::vector<std::vector<std::string>> grid() {
    return {{" ","|"," ","|"," "},
    {"-","|","-", "|","-"},
    {" ","|"," ","|"," "},
    {"-","|","-", "|","-"},
    {" ","|"," ","|"," "}};
};

std::vector<int> dialogue(int num){
    int row;
    int line;
    std::cout << "\nPlayer "<< num << " turn:\n";
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
        while ((grid[num1][num2] == "X" ) || (grid[num1][num2] == "O" ) || (num1 > 5) || (num2 > 5)){
            std::cout << "Invalid Input, repeat please\n\n";
            std::vector<int> vector = dialogue (num3);
            num1= vector[0] + (vector[0]-1)-1;
            num2= vector[1] + (vector[1]-1)-1;
        }
        grid[num1][num2] = "X";
        return grid;
    }
    else {
        while ((grid[num1][num2] == "X" ) || (grid[num1][num2] == "O" ) || (num1 > 5) || (num2 > 5)){
            std::cout << "Invalid Input, repeat please\n\n";
            std::vector<int> vector = dialogue (num3);
            num1= vector[0] + (vector[0]-1)-1;
            num2= vector[1] + (vector[1]-1)-1;
        }
        grid[num1][num2] = "O";
        return grid;
    }
};

bool check_winner(const std::vector<std::vector<std::string>>& grid, int num3) {
    // Horizontal, vertical, and diagonal checks for the player
    if (num3==1) {
    for (int i = 0; i < 3; ++i) {
        int j= i*2;
        if ((grid[j][0] == "X" && grid[j][2] == "X" && grid[j][4] == "X") ||
            (grid[0][j] == "X" && grid[2][j] == "X" && grid[4][j] == "X"))
            return true;
    }

    // Diagonal checks
    if ((grid[0][0] == "X" && grid[2][2] == "X" && grid[2][2] == "X") ||
        (grid[0][2] == "X" && grid[2][2] == "X" && grid[2][0] == "X"))
        return true;

    return false;
    }
    else {
        for (int i = 0; i < 3; ++i) {
            int j= i*2;
        if ((grid[j][0] == "O" && grid[j][2] == "O" && grid[j][4] == "O") ||
            (grid[0][j] == "O" && grid[2][j] == "O" && grid[4][j] == "O"))
            return true;
    }

    // Diagonal checks
    if ((grid[0][0] == "O" && grid[2][2] == "O" && grid[4][4] == "O") ||
        (grid[0][4] == "O" && grid[2][2] == "O" && grid[4][0] == "O"))
        return true;

    return false;
    }
}

bool winner_cases(int num3, const std::vector<std::vector<std::string>> grid, int turn) {
    if (check_winner(grid, num3)) {
        std::cout << "Player 1 wins!\n";
        return true;
    }
    if (check_winner(grid, num3)) {
        std::cout << "Player 2 wins!\n";
        return true;
    }
    if (turn > 9) {
        std::cout << "Draw!\n";
        return true;
    }
    return false;
}
