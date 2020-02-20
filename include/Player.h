#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player(std::string player_char);
        bool GethasTurned();
        void SethasTurned(bool val);
        std::string Getplayer();

    private:
        bool hasTurned;
        std::string player;
};

#endif // PLAYER_H