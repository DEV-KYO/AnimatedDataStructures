//
// Created by jnmen on 6/7/2024.
//

#ifndef ANIMATEDSORTALG_H
#define ANIMATEDSORTALG_H
#include <string>
#include <stack>
#include <vector>
#include <utility>
#include "EnumSortFunctions.h"
#include "../Drawables/NodeShape/NodeShape.h"
#include "../Drawables/SquareText/SquareText.h"
#include "EnumSortState.h"

//This class will animate Quicksort and Mergesort algorithms
class AnimatedSortAlg {
private:
    //Use Square as the shape of the array
    std::vector<SquareText> array;
    std::vector <std::string> data;
    EnumSortState sortState = EnumSortState::NOTSTARTED;
    EnumSortFunctions sortFunction;
    std::stack<std::pair<int,int>> sortStack;
    int i = 0;
    int j = data.size() - 1;



    //Sizes
    sf::Vector2f sizeSquare = sf::Vector2f(50, 50);
    void setPosition(const sf::Vector2f& position);


public:
    AnimatedSortAlg();
    AnimatedSortAlg(std::vector<std::string> vector, sf::Vector2f size);

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) ;


    void push_back(const std::string& data);
    void push_front(const std::string& data);
    void pop_back();
    void pop_front();
    void clear();

    void sort(EnumSortFunctions sortFunctions);

    void quickSortStep();

    int partition(int low, int high);

    void mergeSort(std::vector<int>& arr, int l, int r);
    void merge(std::vector<int>& arr, int l, int m, int r);


};



#endif //ANIMATEDSORTALG_H
