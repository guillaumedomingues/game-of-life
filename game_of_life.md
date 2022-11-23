# Game of life

## What is the game of life

The game of life is a simple algorithm create by John Conway that describes a cellular automaton

The premise is that you have a grid, and each cell of the grid as two states, dead or alive. After each iteration the following rules will be applied to each cell:

- Any live cell with two or three live neighbours survives.
- Any dead cell with three live neighbours becomes a live cell.
- All other live cells die in the next generation. Similarly, all other dead cells stay dead.

For more information please refer to [these docs](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life). If these docs are not tou your satisfaction there is plenty more information online.

## What is required for this problem

- The program should be written in a low level language (C/C++ for example).
- The grid can have arbitrary dimentions (the width and height of the grid sould be passed as parameters)
- The project needs to have a build system (CMake, make, or even a bash file will suffice)

This problem should not take too long to solve (aprox. 90 minutes) but you have until **monday (28/11/2022)** to do it.
Please create a github/gitlab reposotory with the code and send us the link after you finish the problem.

If you any questions feel free to contact us at francisco.torrinha@bisect.pt or nelson@bisect.pt
