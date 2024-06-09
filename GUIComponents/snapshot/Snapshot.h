//
// Created by Jonas Mendoza on 4/26/24.
//

// Snapshot.h
#ifndef TEXT_INPUT_PROJECT_SNAPSHOT_H
#define TEXT_INPUT_PROJECT_SNAPSHOT_H
#include <string>
#include <map>
#include <any>

class Snapshot {
private:
    std::map<std::string, std::any> snapshot;
    int count;

public:
    Snapshot() : snapshot({}), count(0) {};

    Snapshot(const std::map<std::string, std::any>& snapshot);

    const std::any& getSnapshot(const std::string& snapshotName) const;

    void setSnapshot(const std::string& snapshotName, const std::any& value);

    int getCount();
};

#endif //TEXT_INPUT_PROJECT_SNAPSHOT_H
