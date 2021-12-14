////
////  mazequeue.cpp
////  HW 2
////
////  Created by Anica Wang on 1/28/21.
////
//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//class Coord
//{
//  public:
//    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
//    int r() const { return m_row; }
//    int c() const { return m_col; }
//  private:
//    int m_row;
//    int m_col;
//};
//
//bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
//          // Return true if there is a path from (sr,sc) to (er,ec)
//          // through the maze; return false otherwise
//{
//    queue<Coord> coordQueue;
//    Coord start(sr, sc);
//    coordQueue.push(start);
//    maze[sr][sc] = '*';
//    
//    while (coordQueue.empty() == false)
//    {
//        Coord coo = coordQueue.front();
//        coordQueue.pop();
//        if (coo.r() == er && coo.c() == ec)
//        {
//            return true;
//        }
//        //north
//        if (maze[coo.r() - 1][coo.c()] != '*' && maze[coo.r() - 1][coo.c()] != 'X')
//        {
//            coordQueue.push(Coord(coo.r() - 1, coo.c()));
//            maze[coo.r() - 1][coo.c()] = '*';
//        }
//        //east
//        if (maze[coo.r()][coo.c() + 1] != '*' && maze[coo.r()][coo.c() + 1] != 'X')
//        {
//            coordQueue.push(Coord(coo.r(), coo.c() + 1));
//            maze[coo.r()][coo.c() + 1] = '*';
//        }
//        //south
//        if (maze[coo.r() + 1][coo.c()] != '*' && maze[coo.r() + 1][coo.c()] != 'X')
//        {
//            coordQueue.push(Coord(coo.r() + 1, coo.c()));
//            maze[coo.r() + 1][coo.c()] = '*';
//        }
//        //west
//        if (maze[coo.r()][coo.c() - 1] != '*' && maze[coo.r()][coo.c() - 1] != 'X')
//        {
//            coordQueue.push(Coord(coo.r(), coo.c() - 1));
//            maze[coo.r()][coo.c() - 1] = '*';
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    string maze[10] = {
//        "XXXXXXXXXX",
//        "X........X",
//        "XX.X.XXXXX",
//        "X..X.X...X",
//        "X..X...X.X",
//        "XXXX.XXX.X",
//        "X.X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    if (pathExists(maze, 10,10, 6,4, 1,1))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//}
