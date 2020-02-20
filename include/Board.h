#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "Player.h"

class Board
{
    public:
        Board();
        std::string playboard[9];
        std::string SetBoard(int index, std::string val);
        void draw();
        std::string CheckField(int index);
        bool CheckTie();
        bool CheckWin(Player p);
};

#endif // BOARD_H