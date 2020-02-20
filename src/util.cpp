#include "../include/util.h"

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
    std::cout << p.Getplayer() << "s Turn! Please specify the Field you want to change! (0-8)" << std::endl;
    std::cin >> inp;
    if (inp <= 8 && board.CheckField(inp) == "-") {
        board.playboard[inp] = p.Getplayer();
        p.SethasTurned(true);
        system("clear");
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