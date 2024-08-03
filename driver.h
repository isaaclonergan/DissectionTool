#ifndef DRIVER_H
#define DRIVER_H

#include <QPushButton>
#include <string>
#include <bits/stdc++.h>

class dissections {
private:
    int selected[6];
    bool challengeMode;
public:
    dissections();
    ~dissections();
    /*
     * 0 : undefined
     * 1 : triangle
     * 2 : circle
     * 3 : square
     * 4 : sphere
     * 5 : cube
     * 6 : pyramid
     * 7 : cylinder
     * 8 : prism
     * 9 : cone
    */
    std::string find_swaps(std::vector<int>, std::vector<int>);
    void write_val(int, int);
    int get_val(int);
    std::string dissection();
    void set_challengeMode(bool);
};

class button_segment {
private:
    std::vector<QPushButton*> shapes;
    int selected;
    int start_index;
public:
    button_segment();
    button_segment(int, int);
    void add_shape(int, QPushButton*);
    void remove_shape(int);
    void select(int, dissections*);
    int get_selected();
};
#endif // DRIVER_H
