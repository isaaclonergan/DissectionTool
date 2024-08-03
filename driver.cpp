#include "driver.h"
#include <iostream>

std::string format_output(std::vector<int> initial, int idx) {
    /*
     * Format the output given the vector with the initial values and an index
    */

    std::string output;

    output.append("Dissect ");
    switch (initial[idx]) {
    case 1:
        output.append("Triangle ");
        break;
    case 2:
        output.append("Circle ");
        break;
    case 3:
        output.append("Square ");
        break;
    default:
        break;
    }
    output.append("From ");
    switch (idx) {
    case 0:
    case 1:
        output.append("Left.\n");
        break;
    case 2:
    case 3:
        output.append("Center.\n");
        break;
    case 4:
    case 5:
        output.append("Right.\n");
        break;
    }
    return output;
}

dissections::dissections() {
    for (int i = 0; i < 6; i++) {
        selected[i] = 0;
    }
    this->challengeMode = 0;
}
dissections::~dissections() {}

std::string dissections::find_swaps(std::vector<int> initial, std::vector<int> comparison) {
    std::string output;
    int tmp1;
    int start;
    int count = 0;


    for (int k = 0; k < 6; k++) {
        std::cout << comparison[k] << " ";
    }
    std::cout << std::endl;
    for (int k = 0; k < 6; k++) {
        std::cout << initial[k] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    if (initial[0] == comparison[0]
        && initial[1] == comparison[1]
        && initial[2] == comparison[2]
        && initial[3] == comparison[3]
        && initial[4] == comparison[4]
        && initial[5] == comparison[5]) {

        output.append("Solved.");
    }
    while ((initial[0] != comparison[0]
            && initial[1] != comparison[1]
            && initial[2] != comparison[2]
            && initial[3] != comparison[3]
            && initial[4] != comparison[4]
            && initial[5] != comparison[5])
            || count <= 15) {
        for (int i = 0; i < 6; i++) {
            if (initial[i] != comparison[i]) {

                for (int j = 0; j < 6; j++) {

                    if (initial[i] == comparison[j] && initial[j] == comparison[i] && i != j && initial[i] != initial[j]) {

                        output.append(format_output(initial, i));
                        output.append(format_output(initial, j));
                        output.append("\n");

                        tmp1 = initial[i];
                        initial[i] = initial[j];
                        initial[j] = tmp1;

                        for (int k = 0; k < 6; k++) {
                            std::cout << initial[k] << " ";
                        }
                        std::cout << std::endl;

                        break;
                    } else if (initial[i] == comparison[j] && i != j && initial[i] != initial[j]) {
                        output.append(format_output(initial, i));
                        output.append(format_output(initial, j));
                        output.append("\n");

                        tmp1 = initial[i];
                        initial[i] = initial[j];
                        initial[j] = tmp1;

                        for (int k = 0; k < 6; k++) {
                            std::cout << initial[k] << " ";
                        }
                        std::cout << std::endl;

                        break;

                    }
                }
            }
        }
        count++;
    }
    return output;
}

void dissections::write_val(int idx, int value) {
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
    this->selected[idx] = value;
}

int dissections::get_val(int idx) {
    return this->selected[idx];
}

void dissections::set_challengeMode(bool value) {
    this->challengeMode = value;
}

std::string dissections::dissection() {
    int shape_3d[6];
    std::vector<int> initial_values;
    for (int i = 0; i < 6; i++) {
        shape_3d[i] = 0;
        initial_values.push_back(0);
    }

    //sphere cylinder cone
    for (int i = 0; i < 3; i++) {
        switch(this->selected[3+i]) {
        case 4:
            shape_3d[0+(i*2)] = 2;
            shape_3d[1+(i*2)] = 2;
            break;
        case 5:
            shape_3d[0+(i*2)] = 3;
            shape_3d[1+(i*2)] = 3;
            break;
        case 6:
            shape_3d[0+(i*2)] = 1;
            shape_3d[1+(i*2)] = 1;
            break;
        case 7:
            shape_3d[0+(i*2)] = 2;
            shape_3d[1+(i*2)] = 3;
            break;
        case 8:
            shape_3d[0+(i*2)] = 1;
            shape_3d[1+(i*2)] = 3;
            break;
        case 9:
            shape_3d[0+(i*2)] = 2;
            shape_3d[1+(i*2)] = 1;
            break;
        }
    }

    for (int i = 0; i < 6; i++) {
        initial_values[i] = shape_3d[i];
    }

    std::vector<std::vector<int>> permutations;

    int n = sizeof(shape_3d) / sizeof(int);
    std::sort(shape_3d, shape_3d+n);
    do {
        if (shape_3d[0] != selected[0] && shape_3d[1] != selected[0] && shape_3d[2] != selected[1] && shape_3d[3] != selected[1] && shape_3d[4] != selected[2] && shape_3d[5] != selected[2]) {
            std::vector<int> temporary;
            for (int i = 0; i < 6; i++) {
                temporary.push_back(shape_3d[i]);
            }
            permutations.push_back(temporary);
        }
    } while (std::next_permutation(shape_3d,shape_3d+n));

    //filter out perfect shapes
    for (int i = 0; i < permutations.size(); i++) {
        if (permutations[i][0] == permutations[i][1] || permutations[i][2] == permutations[i][3] || permutations[i][4] == permutations[i][5]) {
            for (int j = 0; j < 6; j++) {
                permutations[i][j] = 0;
            }
        }
    }

    //assign similarity values
    std::vector<int> comparison_values;
    for (int i = 0; i < permutations.size(); i++) {
        int val = 0;
        for (int j = 0; j < 6; j++) {
            if (permutations[i][j] == initial_values[j]) {
                val++;
            }
        }
        comparison_values.push_back(val);
    }

    //find most similar
    int max_index = 0;
    int current_max = 0;
    for (int i = 0; i < comparison_values.size(); i++) {
        if (comparison_values[i] >= current_max) {
            max_index = i;
            current_max = comparison_values[i];
        }
    }

    std::string out = "";
    if (this->challengeMode == false) {
        if (current_max != 0) {
            std::cout << "Starting Swaps" << std::endl;
            out.append(find_swaps(initial_values, permutations[max_index]));
            std::cout << "Swaps Complete" << std::endl << std::endl;
        } else if (this->selected[3] != this->selected[4] && this->selected[4] != this->selected[5] && this->selected[3] != this->selected[5]) {
            out.append(format_output(initial_values, 0));
            out.append(format_output(initial_values, 2));
            out.append("\n");
            out.append(format_output(initial_values, 1));
            out.append(format_output(initial_values, 4));
            out.append("\n");
            out.append(format_output(initial_values, 3));
            out.append(format_output(initial_values, 5));
        } else {
            out.append("Unsupported Input");
        }
    } else {
        std::vector<int> solution;
        solution.push_back(this->selected[2]);
        solution.push_back(this->selected[2]);
        solution.push_back(this->selected[0]);
        solution.push_back(this->selected[0]);
        solution.push_back(this->selected[1]);
        solution.push_back(this->selected[1]);
        std::cout << "Starting Swaps -- Challenge" << std::endl;
        out.append(find_swaps(initial_values, solution));
        std::cout << "Swaps Complete" << std::endl << std::endl;
    }

    return out;
}
\
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

button_segment::button_segment() {
    shapes.reserve(0);
    selected = 0;
    start_index=0;
}

button_segment::button_segment(int size, int start) {
    shapes.reserve(size+1);
    selected = 0;
    start_index = 0;
}

void button_segment::add_shape(int idx, QPushButton* value) {
    this->shapes.insert(shapes.begin() + idx, value);
}

void button_segment::remove_shape(int idx) {
    this->shapes.erase(shapes.begin() + idx);
}

void button_segment::select(int idx, dissections* s) {
    this->selected = idx;

    for (int i = 0; i < this->shapes.size(); i++) {
        this->shapes[i]->setStyleSheet("");
    }
    if (idx-1 >= 0) {
        this->shapes[idx-1]->setStyleSheet("background-color: rgb(132,167,224)");
    }
}

int button_segment::get_selected() {
    return this->selected;
}
