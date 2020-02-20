#include <string>
#include "../include/Player.h"

Player::Player(std::string player_char)
{
    player = player_char;
}
bool Player::GethasTurned() {
    return hasTurned;
}
void Player::SethasTurned(bool val) {
    hasTurned = val;
}
std::string Player::Getplayer() {
    return player;
}