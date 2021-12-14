////
////  mazestack.cpp
////  HW 2
////
////  Created by Anica Wang on 1/28/21.
////
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//class Coord
//{
//  public:
////    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
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
//    stack<Coord> coordStack;
//    Coord start(sr, sc);
//    coordStack.push(start);
//    maze[sr][sc] = '*';
//
//    while (coordStack.empty() == false)
//    {
//        Coord coo = coordStack.top();
//        coordStack.pop();
//        //cout << coo.r() << ", " << coo.c() << endl;
//        if (coo.r() == er && coo.c() == ec)
//        {
//            return true;
//        }
//        //north
//        if (maze[coo.r() - 1][coo.c()] != '*' && maze[coo.r() - 1][coo.c()] != 'X')
//        {
//            coordStack.push(Coord(coo.r() - 1, coo.c()));
//            maze[coo.r() - 1][coo.c()] = '*';
//        }
//        //east
//        if (maze[coo.r()][coo.c() + 1] != '*' && maze[coo.r()][coo.c() + 1] != 'X')
//        {
//            coordStack.push(Coord(coo.r(), coo.c() + 1));
//            maze[coo.r()][coo.c() + 1] = '*';
//        }
//        //south
//        if (maze[coo.r() + 1][coo.c()] != '*' && maze[coo.r() + 1][coo.c()] != 'X')
//        {
//            coordStack.push(Coord(coo.r() + 1, coo.c()));
//            maze[coo.r() + 1][coo.c()] = '*';
//        }
//        //west
//        if (maze[coo.r()][coo.c() - 1] != '*' && maze[coo.r()][coo.c() - 1] != 'X')
//        {
//            coordStack.push(Coord(coo.r(), coo.c() - 1));
//            maze[coo.r()][coo.c() - 1] = '*';
//        }
//    }
//    return false;
//}
//
////int main()
////{
////   stack<Coord> coordStack;     // declare a stack of Coords
////
////   Coord a(5,6);
////   coordStack.push(a);          // push the coordinate (5,6)
////   coordStack.push(Coord(3,4)); // push the coordinate (3,4)
////   Coord b = coordStack.top();  // look at top item in the stack
////   coordStack.pop();            // remove the top item from stack
////   if (coordStack.empty())      // Is the stack empty?
////       cout << "empty!" << endl;
////   cout << coordStack.size() << endl;  // number of elements
////}
//
//int main()
//{
//    string maze[10] = {
//       //0123456789
//        "XXXXXXXXXX", //0
//        "X........X", //1
//        "XX.X.XXXXX", //2
//        "X..X.X...X", //3
//        "X..X...X.X", //4
//        "XXXX.XXX.X", //5
//        "X.X....XXX", //6
//        "X..XX.XX.X", //7
//        "X...X....X", //8
//        "XXXXXXXXXX"  //9
//       //0123456789
//    };
//
//    if (pathExists(maze, 10,10, 6,4, 1,1))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//}
