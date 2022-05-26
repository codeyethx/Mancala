/*
 * Description: Program that allows user to play Mancala
 * @file: MancalaBoard.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: April 26, 2021
 */
#include <iostream>
#include "MancalaBoard.h"
#include "Pocket.h"
#include "NormalPocket.h"

using namespace std;

/**
 * Create an empty linked list
 */
MancalaBoard::MancalaBoard() {
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

/**
 * Delete any remaining Nodes in the linked list
 */
MancalaBoard::~MancalaBoard() {
    clear();
}

/**
 * Return the number of elements stored in the linked list
 */
size_t MancalaBoard::size() const {
    return _size;
}

/**
 * Get the Node at the given index of the linked list (a helper function)
 * @param index the index of the Node to return
 * @return (a pointer to) the Node at the given index.
 */
Node * MancalaBoard::get_node(const size_t index) const {
    Node * current_node = _head;
    for (size_t current_index = 0; current_index < index; current_index++) {
        current_node = current_node->next;
    }
    return current_node;
}

/**
 * Return the data stored at the given index
 * @param index the index of the data element
 * @return the data stored at the given index
 */
int MancalaBoard::get(const size_t index) const {
    return get_node(index)->pocket->get_marbles();
}

/**
 * Change the data stored at the given index to the provided data.
 * @param index the index of the data to change
 * @param data the new data
 */
void MancalaBoard::set(const size_t index, const int data) {
    get_node(index)->pocket->set_marbles(data);
}

/**
 * Add the given Node to the beginning of the linked list (a helper function)
 * @param baby The Node to add to the beginning of the linked list.
 */
void MancalaBoard::add_first(Node * baby) {
    baby->next = _head;
    _head = baby;
    if (_tail == nullptr)
        _tail = _head;
    _size++;
}

/**
 * Add the given Node to the linked list after the specified Node (a helper method).
 * @param previous_node The Node to precede the new Node in the linked list
 * @param baby The Node to add to the list.
 */
void MancalaBoard::add_after(Node * previous_node, Node * baby) {
    baby->next = previous_node->next;
    previous_node->next = baby;
    if (previous_node == _tail)
        _tail = baby;
    _size++;
}

/**
 * Add the given Node to the end of the linked list
 * @param baby The Node to add to the list.
 */
void MancalaBoard::add_last(Node * baby) {
    if (_tail == nullptr) {
        _tail = baby;
        _head = baby;
    } else {
        _tail->next = baby;
        _tail = baby;
    }
    _size++;
}

/**
 * Add the given data to the linked list so that it appears at the given index.
 * This displaces the nodes after it to be later in the linked list.
 * @param index The index to place the given data.
 * @param data The data to place at the index.
 */
void MancalaBoard::add(const size_t index, const int data) {
    Node * baby = new Node;
    baby->next = nullptr;
    baby->pocket->set_marbles(data);

    if (index == 0)
        add_first(baby);
    else if (index == _size)
        add_last(baby);
    else
        add_after(get_node(index - 1), baby);
}

/**
 * Remove the first Node from the linked list (a helper function)
 */
void MancalaBoard::remove_first() {
    Node * saved = _head;
    _head = _head->next;

    if (_head == nullptr)
        _tail = nullptr;

    _size--;
    delete saved;
}

/**
 * Remove the Node appearing after previous_node in the linked list (a helper function)
 * @param previous_node the Node appearing before the one we want to remove.
 */
void MancalaBoard::remove_after(Node * previous_node) {
    Node * removed = previous_node->next;
    previous_node->next = removed->next;

    if (removed == _tail)
        _tail = previous_node;

    _size--;
    delete removed;
}

/**
 * Remove the element stored in the given index of the linked list
 * @param index the index of the element we wish to remove.
 */
void MancalaBoard::remove(const size_t index) {
    if (index == 0) {
        remove_first();
        return;
    }
    remove_after(get_node(index - 1));
}

/**
 * link the tail node to the head node
 */
 void MancalaBoard::link_to_head() {
     _tail->next = nullptr;
 }

/**
 * Delete all of the Nodes in the linked list
 */
void MancalaBoard::clear() {
    while (_head != nullptr) {
        delete _head->pocket;
        remove_first();
    }
}

/**
 * Read the data into the linked list from the given input stream
 * @param input_stream the input stream to read from
 */
void MancalaBoard::read(istream & input_stream) {
    clear();
    while (input_stream.peek() != '\n') {
        int read_int = 0;
        input_stream >> read_int;
        add(_size, read_int);
    }
    link_to_head();
}

/**
 * Write the linked list data to the given output stream
 * @param output_stream the output stream to write to
 */
void MancalaBoard::write(ostream & output_stream) const {
    Node * current_node = _head;
    if (current_node != nullptr) {
        output_stream << current_node->pocket->get_marbles();
        current_node = current_node->next;
    }

    while (current_node != nullptr) {
        output_stream << " " << current_node->pocket->get_marbles();
        current_node = current_node->next;
    }
    output_stream << endl;
}

/**
 * A copy constructor for the linked list
 * @param other the linked list to copy from
 */
MancalaBoard::MancalaBoard(const MancalaBoard & other) {
    _head = nullptr;
    _tail = nullptr;
    _size = 0;

    Node * current_node = other._head;
    while (current_node != nullptr) {
        this->add(_size, current_node->pocket->get_marbles());
        current_node = current_node->next;
    }
}

/**
 * Distributes a marble in each pocket
 * @param index to the node
 * @param opp_mancala the opponent's mancala
 */
void MancalaBoard::distribution(size_t & index, Node * opp_mancala) {
    if (index == _size - 1)
        index = 0;
    else
        index++;
    if (get_node(index) != opp_mancala)
        set(index, get(index) + 1);
}

/**
 * Captures marbles in opposing each other and adds to player's mancala pocket
 * @param mancala_pocket the player's mancala pocket
 * @param opposite_index index of opponents pocket
 * @param index index of players pocket
 */
void MancalaBoard::capture(size_t mancala_pocket, size_t opposite_index, size_t index) {
    get_node(mancala_pocket)->pocket->send_pocket(get(opposite_index) + get(mancala_pocket - 1) + get(index));
    set(opposite_index, 0);
    set(index, 0);
}

/**
 * Moves the pockets in a counterclockwise direction
 * @param pocket_number the marbles inside pocket
 * @param my_mancala current players's mancala pocket
 * @param other_mancala opponent's mancala pocket
 */
bool MancalaBoard::move_marbles(size_t pocket_number, size_t my_mancala, size_t other_mancala) {
    get_node(other_mancala)->pocket->send_pocket();
    size_t marbles = get(pocket_number), index = pocket_number, opp_pocket_index;
    set(pocket_number, 0);
    opp_pocket_index = (_size - 2) - index;

    while (marbles > 0) {
      distribution(index, get_node(other_mancala));
      marbles--;
    }
    if (index == my_mancala - 1)
        return true;
    else if (get(index) == 1)
        capture(my_mancala, opp_pocket_index, index);
    return false;
}
