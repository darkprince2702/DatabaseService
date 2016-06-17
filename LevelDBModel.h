//
// Created by ductn on 14/06/2016.
//

#ifndef LEVELDBMODEL_H
#define LEVELDBMODEL_H

#include <leveldb/db.h>
#include <mutex>
#include "databaseservice_types.h"
#include "DatabaseModel.h"

class LevelDBModel : public DatabaseModel {
private:
    leveldb::DB *db;
    leveldb::Options options;
    leveldb::Status status;
    std::mutex mutex;
    LevelDBModel();
public:
    static LevelDBModel* getInstance();
    bool hasData(std::string key);
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
    ~LevelDBModel();
};


#endif //THRIFTSERVICECPP_LEVELDBMODEL_H
