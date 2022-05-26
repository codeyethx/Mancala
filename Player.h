#ifndef PLAYER_H
#define PLAYER_H


class Player {
private:
    int pocket_number = -1;
    int side;
public:
    void save_side(int end);
    int get_side() const;
    int pick_number();
};

#endif // Player_H
