#include <stdlib.h>
#include <iostream>
#include <string>


void print_grid(int* curr_grid_ptr, int x_dim_size, int y_dim_size){

  for(int i = 0; i < x_dim_size; i++){
    std::cout << "[|";
    for(int j = 0; j < y_dim_size; j++){
      std::cout << *(curr_grid_ptr + i*x_dim_size + j) << "|";
    }
    std::cout << "]\n";
  }


}


void game_loop(int* curr_grid_ptr, int* next_grid_ptr, int x_dim_size, int y_dim_size){
  //Iterates through the current generation's game grid, counts each cell's neighbours and
  //stores the result in the next generation's game grid.
  int neighbour_count = 0;
  int j= 0;
  int i= 0;

  for (int i = 0; i < x_dim_size; i++){
    for (int j = 0; j < y_dim_size; j++){
      neighbour_count = 0;
      //Upper-bound check
      if(i == 0){
        //Left-bound check
        if(j == 0){

          neighbour_count += *(curr_grid_ptr + 1);
          neighbour_count += *(curr_grid_ptr + x_dim_size);
          neighbour_count += *(curr_grid_ptr + x_dim_size + 1);

        }
        //Right-bound check
        else if(j == y_dim_size - 1){

          neighbour_count += *(curr_grid_ptr + i*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j - 1);


        }
        else{

          neighbour_count += *(curr_grid_ptr + i*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + i*x_dim_size + j + 1);

          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j - 1);

        }

      }
      //Lower-bound check
      else if(i == x_dim_size - 1){
        //Left-bound check
        if(j == 0){
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j + 1);
        }
        //Right-bound check
        else if(j == y_dim_size - 1){
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j - 1);
        }
        else{
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j + 1);
        }
      }
      //Cell isn't upper/lower, right/left bound.
      else{
        if(j == 0){

          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j);


        }
        else if(j == y_dim_size - 1){

          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j);

        }
        else{
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i-1)*x_dim_size + j);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j - 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j + 1);
          neighbour_count += *(curr_grid_ptr + (i+1)*x_dim_size + j);

        }
      }

      //If cell is alive and has 2/3 neighbours it stays alive, otherwise it dies
      if(*(curr_grid_ptr + i*x_dim_size + j) == 1){
        if(neighbour_count == 2 | neighbour_count == 3){
          continue;
          //*(curr_grid_ptr + i*x_dim_size + j) = 1;
        }
        else{
          *(next_grid_ptr + i*x_dim_size + j) = 0;
        }
      }
      //If cell is dead and has 3 neighbours it revives.
      else{
        if(neighbour_count == 3){
          *(next_grid_ptr + i*x_dim_size + j) = 1;
        }

      }
    }
  }

}

void update_grid(int* curr_grid_ptr, int* next_grid_ptr, int x_dim_size, int y_dim_size){


  for(int i = 0; i < x_dim_size; i++){
    for(int j = 0; j < y_dim_size; j++){
      *(curr_grid_ptr + i*x_dim_size + j) = *(next_grid_ptr + i*x_dim_size + j);
    }
  }
}

int main(int argc, char *argv[]){

  //Default grid sizes and default number of generations
  int x = 10;
  int y = 10;
  int max_generation = 10;
  srand(time(NULL)); //Initialize seed to populate the starting grid.

  if(argc==1){

    std::cout << "No arguments passed, initializing grid as 10x10, doing 10 generations.\n"
    << "Example usage : './game_of_life 10 10 100' creates a 10x10 grid and iterates through 100 generations.\n";

  }
  else if(argc > 4){
    std::cout << "Too many arguments passed. Program must have to arguments:\n 'x y generations'\nWhere 'x,y, and generations' are integers and separated by whitespace.";
    return 0;
  }
  else if(argc < 3){
    std::cout << "Not enough arguments passed. Program must have to arguments:\n 'x y generations'\n'x,y, and generations' are integers and separated by whitespace.\n"
    << "Example usage : './game_of_life 10 10 100' creates a 10x10 grid and iterates through 100 generations.\n";
    return 0;
  }
  else{
    try{
      //Convert arguments from string to integer.
      x = std::stoi(argv[1]);
      y = std::stoi(argv[2]);
      max_generation = std::stoi(argv[3]);

      std::cout << "x is " << argv[1] << '\n' <<
                   "y is " << argv[2] << '\n' <<
                   "Iterating until " << argv[3] << " generations.\n";
    }
    catch(std::invalid_argument){
      std::cout << "Invalid input for x,y arguments. \n";
      return 0;
    }
    catch(std::out_of_range){
      std::cout << "Input parameters too large. Try with a smaller grid.\n";
    }
  }

  //Create grid with size x,y
  int game_grid[x][y];
  int next_game_grid[x][y];


  //Populate the starting grid with 1 or 0.
  //1 == cell is alive; 0 == cell is dead
  for (int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      int cell_value = std::rand()  % 2; //Generate a value for the cell's state
      //Store the cell's state in both grid arrays.
      game_grid[i][j] = cell_value;
      next_game_grid[i][j] = cell_value;

    }
  }
  //Print the starting grid
  std::cout << "1st generation grid :\n";
  print_grid(&game_grid[0][0],x,y);


  /*Game loop.
  Every generation the function 'game_loop' iterates through all cells and counts
  their respective neighbours, calculates the result for the next state and stores it in next_game_grid.

  'update_grid' copies the next_game_grid's values into game_grid*/
  int generation = 0;
  while(generation < max_generation){

    game_loop(&game_grid[0][0], &next_game_grid[0][0], x, y);
    update_grid(&game_grid[0][0], &next_game_grid[0][0], x, y);

    generation++;
  }

  //Print the final grid.
  std::cout << "After " << generation << " generations :\n";
  print_grid(&game_grid[0][0],x,y);


 return 0;

}
