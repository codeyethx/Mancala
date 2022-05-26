/*
 * Description: Program that allows user to play Mancala
 * @file: Player.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: April 26, 2021
 */
#include <iostream>
#include "Player.h"

void Player::save_side(int end) {
    side = end;
}

int Player::pick_number() {
    std::cin >> pocket_number;
    return pocket_number;
}

int Player::get_side() const {
    return side;
}
