#include "findallmovess.h"


findallmovess::findallmovess(int side, int **map)
{
    int sidecheck = 1 - side - side;
    for (int i=0; i<8; i++)
    {
        for (int j = 0; j <8;j++)
            {
                 if (sidecheck * map[i][j] > 0)
                     findMovesFor(i,j, map);
            }
    }
    this->side = side;
}

void findallmovess::findMovesFor(int x, int y, int **map)
{
    int type = map[x][y];
    if (type == 9 || type == -9)
        kingsmove(x,y,map);
    else if (type == 8 || type == -8)
        queensmove(x,y,map);
    else if (type == 7 || type == -7)
        rooksmove(x,y,map);
    else if (type == 6 || type == -6)
        knightsmove(x,y,map);
    else if (type == 5 || type == -5)
        bishopsmove(x,y,map);
    else if (type == 4 || type == -4)
        pawnsmove(x,y,map);
}

void findallmovess::kingsmove(int px, int py, int **map)
{
    int sidecheck;
    int P = map[px][py];
    if (P > 0)
        sidecheck = 1;
    else
        sidecheck = -1;
    int x =px-1;
    int y =py-1;
    if (x < 0)
        x++;
    if (y < 0)
        y++;
    for (; x < px+2; x++)
    {
        if (x == px +1 && x > 7)
            break;
        for(; y<py+2;y++)
        {
            if (y == py +1 && y > 7)
                break;
                if (map[x][y] == 0)
                {
                    moves* M = new moves(P, px, py, x, y, 0);
                    int **new_board=new int *[8];
                    for (int i=0; i<8; i++)
                    {
                        new_board[i] = new int[8];
                        for (int j = 0; j <8;j++)
                                 new_board[i][j] = map[i][j];
                    }
                    new_board[px][py] = 0;
                    new_board[x][y] = P;
                    allmoves.append(M);
                    allmaps.append(new_board);
                }
                else if (map[x][y]*sidecheck < 0)
                {
                    moves* M = new moves(P, px, py, x, y, map[x][y]);
                    int **new_board=new int *[8];
                    for (int i=0; i<8; i++)
                    {
                        new_board[i] = new int[8];
                        for (int j = 0; j <8;j++)
                                 new_board[i][j] = map[i][j];
                    }
                    new_board[px][py] = 0;
                    new_board[x][y] = P;
                    allmoves.append(M);
                    allmaps.append(new_board);
                }
        }
    }
}

void findallmovess::queensmove(int x, int y, int **map)
{
    rooksmove(x,y,map);
    bishopsmove(x,y,map);
}

void findallmovess::rooksmove(int px, int py, int **map)
{
    int sidecheck;
    int P = map[px][py];
    if (P > 0)
        sidecheck = 1;
    else
        sidecheck = -1;
    int x = px +1;
    int y = py;
    for (; x<8;x++)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
    }
    x = px -1;
    for (; x>=0;x--)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
    }
    x = px;
    y = py +1;
    for (; y<8;y++)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
    }
    y = py -1;
    for (; y>=0;y--)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
    }
}

void findallmovess::knightsmove(int px, int py, int **map)
{
    int sidecheck;
    int P = map[px][py];
    if (P > 0)
        sidecheck = 1;
    else
        sidecheck = -1;
    int x, y;
    if (px+1 < 8)
    {
        if (py+2 <8)
        {
            x = px+1;
            y = py+2;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
        else if (py - 2 >=0)
        {
            x = px+1;
            y = py-2;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
    }

    if (px-1 >= 0)
    {
        if (py+2 <8)
        {
            x = px-1;
            y = py+2;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
        else if (py - 2 >=0)
        {
            x = px-1;
            y = py-2;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
    }

    if (px+2 < 8)
    {
        if (py+1 <8)
        {
            x = px+2;
            y = py+1;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
        else if (py - 1 >=0)
        {
            x = px+2;
            y = py-1;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
    }

    if (px-2 >= 0)
    {
        if (py+1 <8)
        {
            x = px-2;
            y = py+1;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
        else if (py - 1 >=0)
        {
            x = px-2;
            y = py-1;
            if (map[x][y] == 0)
            {
                moves* M = new moves(P, px, py, x, y, 0);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
            else if (map[x][y]*sidecheck < 0)
            {
                moves* M = new moves(P, px, py, x, y, map[x][y]);
                int **new_board=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board[i][j] = map[i][j];
                }
                new_board[px][py] = 0;
                new_board[x][y] = P;
                allmoves.append(M);
                allmaps.append(new_board);
            }
        }
    }
}

void findallmovess::bishopsmove(int px, int py, int **map)
{
    int sidecheck;
    int P = map[px][py];
    if (P > 0)
        sidecheck = 1;
    else
        sidecheck = -1;
    int x = px +1;
    int y = py +1;
    for (; x<8 && y <8;x++)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
        y++;
    }
    x = px +1;
    y = py -1;
    for (; x<8 && y >=0;x++)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
        y--;
    }
    x = px -1;
    y = py +1;
    for (; x>=0 && y <8;x--)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
        y++;
    }
    x = px -1;
    y = py -1;
    for (; x>=0 && y >=0; x--)
    {
        if (map[x][y] == 0)
        {
            moves* M = new moves(P, px, py, x, y, 0);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
        else if (map[x][y]*sidecheck < 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
            break;
        }
        else
            break;
        y--;
    }
}

void findallmovess::pawnsmove(int px, int py, int **map)
{
    int P = map[px][py];
    int pace;
    if (P < 0)
        pace = 1;
    else
        pace = -1;
    int x = px;
    int y = py+pace;
    if (map[x][y] == 0)
    {
        moves* M = new moves(P, px, py, x, y, 0);
        int **new_board=new int *[8];
        for (int i=0; i<8; i++)
        {
            new_board[i] = new int[8];
            for (int j = 0; j <8;j++)
                     new_board[i][j] = map[i][j];
        }
        new_board[px][py] = 0;
        new_board[x][y] = P;
        allmoves.append(M);
        allmaps.append(new_board);
        if (side && py ==1)
        {
            y = py+pace+pace;
            if (map[x][y] == 0)
            {
                moves* M1 = new moves(P, px, py, x, y, 0);
                int **new_board1=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board1[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board1[i][j] = map[i][j];
                }
                new_board1[px][py] = 0;
                new_board1[x][y] = P;
                allmoves.append(M1);
                allmaps.append(new_board1);
            }
        }
        else if (!side && py ==6)
        {
            y = py+pace+pace;
            if (map[x][y] == 0)
            {
                moves* M1 = new moves(P, px, py, x, y, 0);
                int **new_board1=new int *[8];
                for (int i=0; i<8; i++)
                {
                    new_board1[i] = new int[8];
                    for (int j = 0; j <8;j++)
                             new_board1[i][j] = map[i][j];
                }
                new_board1[px][py] = 0;
                new_board1[x][y] = P;
                allmoves.append(M1);
                allmaps.append(new_board1);
            }
        }
    }
    y = py + pace;
    x = px + 1;
    if (x <8)
    {
        if (map[x][y] *pace > 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
    }
    y = py + pace;
    x = px - 1;
    if (x >=0)
    {
        if (map[x][y] *pace > 0)
        {
            moves* M = new moves(P, px, py, x, y, map[x][y]);
            int **new_board=new int *[8];
            for (int i=0; i<8; i++)
            {
                new_board[i] = new int[8];
                for (int j = 0; j <8;j++)
                         new_board[i][j] = map[i][j];
            }
            new_board[px][py] = 0;
            new_board[x][y] = P;
            allmoves.append(M);
            allmaps.append(new_board);
        }
    }
}
