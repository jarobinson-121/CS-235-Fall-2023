#include <iostream>
#include <string>
#include <fstream>

#include "Grid.h"

using namespace std;

bool solveMaze(int maze[4][4], int r, int c) {
    // base case(s)
    if ((r < 0) || (r > 3) || (c < 0) || (c > 3))
        return false;

    if (maze[r][c] == 0)
        return false;

    if ((r == 3) && (c == 3))
        return true;

    maze[r][c] = 2;    

    if (maze[r][c] == 2) {
        return false;
    }
// recursive step
    if (solveMaze(maze, r+1, c) ||
        solveMaze(maze, r-1, c) ||
        solveMaze(maze, r, c+1) ||
        solveMaze(maze, r, c-1)) {
        return true;
    }
    else {
        //pop coordinates off the stack
    }

    return false;
}

int main(int argc, char** argv) {
    string ifile = argv[0];
    string ofile = argv[1];
    filebuf opener;
    Grid mymaze;
    ifstream in;

    opener.open(ifile, ios::in);

    if(!opener.is_open()) {
        cerr << "File is not opened." << endl;
        return 1;
    }

    istream infile(&opener);

    in >> mymaze;

    infile >> (infile, mymaze);

    int maze[4][4] = {{1,1,0,0},
                      {0,1,0,0},
                      {1,1,1,0},
                      {0,0,1,1}}; 

    solveMaze(maze, 0, 0);

    opener.close();

return 0;
}
