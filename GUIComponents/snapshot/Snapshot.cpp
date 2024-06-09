//
// Created by Jonas Mendoza on 4/26/24.
//

// Snapshot.cpp
#include "Snapshot.h"


Snapshot::Snapshot(const std::map<std::string, std::any>& snapshot) : snapshot(snapshot), count(snapshot.size()) {}

const std::any& Snapshot::getSnapshot(const std::string& snapshotName) const {
    return snapshot.at(snapshotName);
}

void Snapshot::setSnapshot(const std::string& snapshotName, const std::any& value) {
    auto it = snapshot.find(snapshotName);
    if(it == snapshot.end()) {
        //If the key doesn't exist, add it to the map
        count++;
    }
    snapshot[snapshotName] = value;
}

int Snapshot::getCount() {
    return count;
}