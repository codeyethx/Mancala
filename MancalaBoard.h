#ifndef MancalaBoard_H
#define MancalaBoard_H
#include <iostream>
#include "Pocket.h"
#include "NormalPocket.h"


struct Node {
    Pocket * pocket = new NormalPocket();
    Node * next;
};
class MancalaBoard {
private:
    Node * _head;
    Node * _tail;
    size_t _size;
public:
     // lifecycle methods
    MancalaBoard();
    MancalaBoard(const MancalaBoard & other);
    ~MancalaBoard();
    // methods from the List interface
    size_t size() const;
    int get(const size_t index) const;
    void set(const size_t index, const int data);
    void add(const size_t index, const int data);
    void remove(const size_t index);
    void read(std::istream & input_stream);
    void write(std::ostream & output_stream) const;
    bool move_marbles(size_t pocket_number, size_t my_mancala, size_t other_mancala);
private:
    // helper methods
    Node * get_node(const size_t index) const;
    void add_first(Node * baby);
    void add_last(Node * baby);
    void add_after(Node * previous_node, Node * baby);
    void remove_first();
    void remove_after(Node * previous_node);
    void link_to_head();
    void distribution(size_t & index, Node * opp_mancala);
    void capture(size_t mancala_pocket, size_t opposite_index, size_t index);
    void clear();
};

#endif // MancalaBoard_H
