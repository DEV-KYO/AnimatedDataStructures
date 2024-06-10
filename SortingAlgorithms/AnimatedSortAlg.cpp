//
// Created by jnmen on 6/7/2024.
//

#include "AnimatedSortAlg.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <utility>

#include "../Settings.h"

AnimatedSortAlg::AnimatedSortAlg() {
    array = std::vector<SquareText>();
    data = std::vector<std::string>();
    view.setCenter(WINDOW_CENTER);
    view.setSize(WINDOW_SIZE);
}

AnimatedSortAlg::AnimatedSortAlg(std::vector<std::string> vector, sf::Vector2f dimmensions) {
    array = std::vector<SquareText>();
    data = std::vector<std::string>();
    sizeSquare = dimmensions;

}

void AnimatedSortAlg::update() {
    for(auto& square : array) {
        square.update();
    }
    if(sortState == EnumSortState::INPROGRESS) {
        switch(sortFunction) {
            case EnumSortFunctions::QUICKSORT:
                quickSortStep();
                break;
            case EnumSortFunctions::MERGESORT:
                if(sortState == EnumSortState::INPROGRESS) {
                    std::vector<int> arr;
                    for(auto& d : data) {
                        arr.push_back(std::stoi(d));
                    }
                    mergeSort(arr, 0, arr.size() - 1);
                    for(int i = 0; i < arr.size(); i++) {
                        data[i] = std::to_string(arr[i]);
                    }
                    sortState = EnumSortState::COMPLETED;
                    std::cout << "Merge Sorting completed\n";
                }
                break;
            default:
                std::cerr << "This is not a sorting function\n" << std::endl;
                break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(SLEEP_TIME)));
        setPosition(WINDOW_CENTER);
        // std::cout << "Sorting" << std::endl;
    }
}

void AnimatedSortAlg::draw(sf::RenderTarget& target, sf::RenderStates states) {
    target.setView(view);
    for(auto& square : array) {
        square.draw(target, states);
    }
}

void AnimatedSortAlg::eventHandler(sf::Window& window, sf::Event& event) {

    // Set the center of the view to the center of the window
    view.setCenter(WINDOW_CENTER);
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            zoom(0.9);
        } else {
            zoom(1.1);
        }
    }
}

void AnimatedSortAlg::zoom(float factor) {
    // Calculate the aspect ratio of the window
    float aspectRatio = WINDOW_SIZE.x / WINDOW_SIZE.y;

    // Calculate the new width and height of the view
    float newWidth = view.getSize().x * factor;
    float newHeight = newWidth / aspectRatio;

    // Set the new size of the view
    view.setSize(newWidth, newHeight);
}

void AnimatedSortAlg::setPosition(const sf::Vector2f& center) {
    float numSquares = array.size();

    float totalWidth = numSquares * sizeSquare.x;
    float startX = center.x - totalWidth / 2;

    float x = startX;
    float y = center.y;
    for (auto& square : array) {
        square.setPosition({x, y});
        x += sizeSquare.x;
    }
}

void AnimatedSortAlg::push_back(const std::string& data) {
    array.emplace_back(sizeSquare, data);
    this->data.push_back(data);
    setPosition(WINDOW_CENTER);
    sortState = EnumSortState::NOTSTARTED;
}

void AnimatedSortAlg::push_front(const std::string& data) {
    array.emplace(array.begin(), sizeSquare, data);
    this->data.insert(this->data.begin(), data);
    setPosition(WINDOW_CENTER);
    sortState = EnumSortState::NOTSTARTED;
}

void AnimatedSortAlg::pop_back() {
    if(array.size() > 1) {
        array.pop_back();
        data.pop_back();
        setPosition(WINDOW_CENTER);
        sortState = EnumSortState::NOTSTARTED;
    }
}

void AnimatedSortAlg::pop_front() {
    if(array.size() > 1) {
        array.erase(array.begin());
        data.erase(data.begin());
        setPosition(WINDOW_CENTER);
        sortState = EnumSortState::NOTSTARTED;
    }
}

void AnimatedSortAlg::clear() {
    array.clear();
    data.clear();
    sortState = EnumSortState::NOTSTARTED;
}

void AnimatedSortAlg::sort(EnumSortFunctions sortFunctions) {
    sortFunction = sortFunctions;
    switch(sortFunctions) {
        case EnumSortFunctions::QUICKSORT:
            if(sortState == EnumSortState::NOTSTARTED) {
                i = 0;
                j = data.size() - 1;
                sortStack.emplace(i, j);
                sortState = EnumSortState::INPROGRESS;
                std::cout << "Quick Sorting started\n";
            }

            if(sortState == EnumSortState::COMPLETED) {
                std::cout << "Quick Sorting completed\n";
            }
            break;

        case EnumSortFunctions::MERGESORT:
            if(sortState == EnumSortState::NOTSTARTED) {
                sortState = EnumSortState::INPROGRESS;
                std::cout << "Merge Sorting started\n";
            }

            if(sortState == EnumSortState::COMPLETED) {
                std::cout << "Merge Sorting completed\n";
            }

            break;
    }
}

void AnimatedSortAlg::quickSortStep() {
    if(sortState == EnumSortState::INPROGRESS && !sortStack.empty()) {
        auto [low, high] = sortStack.top();
        sortStack.pop();

        if(low < high) {
            int pivot = partition(low, high);
            sortStack.emplace(pivot + 1, high);
            sortStack.emplace(low, pivot - 1);
        }
    } else {
        sortState = EnumSortState::COMPLETED;
        std::cout << "Quick Sorting completed\n";
    }
}

int AnimatedSortAlg::partition(int low, int high) {
    int pivot = std::stoi(data[high]); // Convert pivot to integer
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        if(std::stoi(data[j]) < pivot) { // Convert data[j] to integer before comparing
            i++;
            std::swap(data[i], data[j]);
            std::swap(array[i], array[j]);
            //print out data
            for(auto& d : data) {
                std::cout << d << " ";
            }
            std::cout << " Partitioning " << std::endl;
        }
    }
    std::swap(data[i + 1], data[high]);
    std::swap(array[i + 1], array[high]);
    //print out data
    for(auto& d : data) {
        std::cout << d << " ";
    }
    std::cout << " Finished partition " << std::endl;

    return i + 1;
}

void AnimatedSortAlg::mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void AnimatedSortAlg::merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L;
    std::vector<int> R;
    std::vector<SquareText> L_square, R_square;

    for(int i = 0; i < n1; i++) {
        L.push_back(arr[l + i]);
        L_square.push_back(array[l + i]);
    }

    for(int j = 0; j < n2; j++) {
        R.push_back(arr[m + 1 + j]);
        R_square.push_back(array[m + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            array[k] = L_square[i];
            i++;
        } else {
            arr[k] = R[j];
            array[k] = R_square[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        array[k] = L_square[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        array[k] = R_square[j];
        j++;
        k++;
    }
}

