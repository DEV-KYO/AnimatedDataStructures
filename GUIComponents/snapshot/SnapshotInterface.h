//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_SNAPSHOTINTERFACE_H
#define TEXT_INPUT_PROJECT_SNAPSHOTINTERFACE_H

#include "Snapshot.h"

class SnapshotInterface {
public:
    //function returns a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;

    //function will apply a snapshot to the object
    //this will revert the object to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;

};


#endif //TEXT_INPUT_PROJECT_SNAPSHOTINTERFACE_H
