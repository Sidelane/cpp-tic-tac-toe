#include <vector>
#include "Player.h"
#include "Board.h"

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

void random_start(Player&, Player&);
void init_board(Board&);
void set_answer(Board &, Player &, std::vector<Player> &);
int check_if_end(Board &, Player &);

#endif // UTIL_H_INCLUDED