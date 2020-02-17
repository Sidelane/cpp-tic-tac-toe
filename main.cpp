#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Player.h"
#include "Board.h"
#include "util.h"

int main()
{
    bool Game = true;

    Board board;
    Player player1("X");
    Player player2("O");

    random_start(player1, player2);
    init_board(board);

    std::vector<Player> players { player1, player2 };

    board.draw();

    while (Game) {
        for (Player p : players) {
            if (p.GethasTurned() == false) {
                set_answer(board, p, players);
                if (check_if_end(board, p) == 1) {
                    Game = false;
                    std::cout << "Tie!" << std::endl;
                    break;
                } else if (check_if_end(board, p) == 2) {
                    Game = false;
                    std::cout << p.GetPlayer() << " won the Game!" << std::endl;
                    break;
                }
            }
        }
    }
    return 0;
}
