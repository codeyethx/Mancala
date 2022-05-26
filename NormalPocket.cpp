/*
 * Description: Program that allows user to play Mancala
 * @file: NormalPocket.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: April 26, 2021
 */
#include "Pocket.h"
#include "MancalaPocket.h"
#include "NormalPocket.h"

void NormalPocket::set_marbles(int marbles) {
    pocket_amount = marbles;
}

int NormalPocket::get_marbles() const {
    return pocket_amount < 0? pocket_mancala->get_marbles(): pocket_amount;
}

void NormalPocket::send_pocket(int send) {
    if (send < 0) {
        pocket_mancala->set_marbles(pocket_amount);
        pocket_amount = -1;
    }
    else
        pocket_mancala->add(send);
}

void NormalPocket::add(int marble_amount) {}
