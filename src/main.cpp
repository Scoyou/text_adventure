#include <iostream>
#include "../include/player/PlayerCharacterUtils.h"

int main()
{
    while(true)
    {
        PlayerCharacter player;
        player = createCharacter();
        player.getStats();
        //run game
    }
    return 0;
}