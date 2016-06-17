//
// Created by ductn on 14/06/2016.
//

#include "LevelDBModel.h"
#include <iostream>
LevelDBModel::LevelDBModel() {
    options.create_if_missing = true;
    status = leveldb::DB::Open(options, "/data/database", &db);
}

LevelDBModel* LevelDBModel::getInstance() {
    static std::mutex staticMutex;
    static LevelDBModel* instance;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(staticMutex);
        if (instance == NULL) // Double check
            instance = new LevelDBModel();
    }

    return instance;
}

bool LevelDBModel::hasData(std::string key) {
    std::lock_guard<std::mutex> guard(mutex);
    return true;
}

GetResult LevelDBModel::getData(std::string key) {
    std::string result;
    GetResult return_;
    // Lock before access db
    std::lock_guard<std::mutex> guard(mutex);
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &result);

    if (s.ok()) {
        return_.isNull = false;
        return_.value = result;
        return_.__isset.value =  true;
    } else {
        return_.isNull = true;
    }
    return return_;
}

bool LevelDBModel::setData(std::string key, std::string value) {
    // Lock before access db
    std::lock_guard<std::mutex> guard(mutex);

    leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
    return s.ok();
}

bool LevelDBModel::removeData(std::string key) {
    // Lock before access db
    std::lock_guard<std::mutex> guard(mutex);

    leveldb::Status s = db->Delete(leveldb::WriteOptions(), key);
    return s.ok();
}