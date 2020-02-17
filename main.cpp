#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "include/Player.h"
#include "include/Board.h"

void random_start(Player&, Player&);
void init_board(Board&);
void set_answer(Board &, Player &, std::vector<Player> &);
int check_if_end(Board &, Player &);

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
                    std::cout << p.Getplayer() << " won the Game!" << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}

void random_start(Player &p1, Player &p2) {
    std::srand(time(NULL));
    int sec = rand() % 10 + 1;
    if (sec > 4) {
        p1.SethasTurned(true);
        p2.SethasTurned(false);
    } else {
        p1.SethasTurned(false);
        p2.SethasTurned(true);
    }
}

void init_board(Board &b) {
    for (int i = 0; i < 9; ++i) {
        b.SetBoard(i, "-");
    }
}

void set_answer(Board &board, Player &p, std::vector<Player> &players) {
    int inp;
    std::cout << p.Getplayer() << "s Turn! Please specify the Field you want to change!" << std::endl;
    std::cin >> inp;
    if (inp <= 8 && board.CheckField(inp) == "-") {
        board.playboard[inp] = p.Getplayer();
        p.SethasTurned(true);
        board.draw();
        if (p.Getplayer() == "X") {
            players[1].SethasTurned(false);
        } else {
            players[0].SethasTurned(false);
        }
    } else {
        set_answer(board, p, players);
    }
}

int check_if_end(Board &board, Player &p) {
    if (board.CheckTie()) {
        return 1;
    } else if (board.CheckWin(p)) {
        return 2;
    }
    return 0;
}
