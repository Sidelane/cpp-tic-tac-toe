#include "../include/Board.h"

Board::Board()
{
    //ctor
}
std::string Board::SetBoard(int index, std::string val) {
    this->playboard[index] = val;
}
void Board::draw() {
    std::cout << "\n";
    std::cout << " | " << this->playboard[0] << " | " << this->playboard[1] << " | " << this->playboard[2] << " | " << "\n";
    std::cout << "  -----------" << "\n";
    std::cout << " | " << this->playboard[3] << " | " << this->playboard[4] << " | " << this->playboard[5] << " | " << "\n";
    std::cout << "  -----------" << "\n";
    std::cout << " | " << this->playboard[6] << " | " << this->playboard[7] << " | " << this->playboard[8] << " | " << "\n";
    std::cout << "\n";
}
std::string Board::CheckField(int index) { 
    return playboard[index]; 
}
bool Board::CheckTie() {
    if (std::find(std::begin(playboard), std::end(playboard), "-") != std::end(playboard)) {
        return false;
    } else {
        return true;
    }
}
bool Board::CheckWin(Player p) {
    if (playboard[0] == p.Getplayer() && playboard[1] == p.Getplayer() && playboard[2] == p.Getplayer()) {
        return true;
    } else if (playboard[3] == p.Getplayer() && playboard[4] == p.Getplayer() && playboard[5] == p.Getplayer()) {
        return true;
    } else if (playboard[6] == p.Getplayer() && playboard[7] == p.Getplayer() && playboard[8] == p.Getplayer()) {
        return true;
    } else if (playboard[0] == p.Getplayer() && playboard[4] == p.Getplayer() && playboard[8] == p.Getplayer()) {
        return true;
    } else if (playboard[2] == p.Getplayer() && playboard[4] == p.Getplayer() && playboard[6] == p.Getplayer()) {
        return true;
    } else if (playboard[1] == p.Getplayer() && playboard[4] == p.Getplayer() && playboard[7] == p.Getplayer()) {
        return true;
    } else if (playboard[0] == p.Getplayer() && playboard[3] == p.Getplayer() && playboard[6] == p.Getplayer()) {
        return true;
    } else if (playboard[2] == p.Getplayer() && playboard[5] == p.Getplayer() && playboard[8] == p.Getplayer()) {
        return true;
    }
    return false;
}