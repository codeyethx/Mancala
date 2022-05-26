#ifndef NORMALPOCKET_H
#define NORMALPOCKET_H
#include "Pocket.h"
#include "MancalaPocket.h"


class NormalPocket : public Pocket {
private:
    int pocket_amount = 0;
    Pocket * pocket_mancala = new MancalaPocket;
protected:
    void set_marbles(int marbles = -1);
    int get_marbles() const;
    void send_pocket(int send = -1);
    void add(int marble_amount);
};

#endif // NormalPocket_H
