#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player(std::string player_char);
        bool GethasTurned() { return hasTurned; }
        void SethasTurned(bool val) { hasTurned = val; }
        std::string Getplayer() { return player; }

    private:
        bool hasTurned;
        std::string player;
};

#endif // PLAYER_H