#ifndef MANCALAPOCKET_H
#define MANCALAPOCKET_H
#include "Pocket.h"

class MancalaPocket : public Pocket {
private:
    int total_mancala = 0;
public:
    void set_marbles(int marbles);
    int get_marbles() const;
    void add(int marble_amount);
    void send_pocket(int send = -1);
};
#endif
