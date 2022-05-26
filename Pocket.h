#ifndef Pocket_H
#define Pocket_H

class Pocket {
public:
    virtual void set_marbles(int marbles) = 0;
    virtual int get_marbles() const = 0;
    virtual void add(int marble_amount) = 0;
    virtual void send_pocket(int send = -1) = 0;
};

#endif // Pocket_H
