/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Database.h
 * Author: ductn
 *
 * Created on June 16, 2016, 10:25 AM
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <leveldb/db.h>
#include "databaseservice_types.h"
#include "DatabaseModel.h"
#include "DatabaseModelFactory.h"
#include <mutex>

class Database {
public:
    static Database* getInstance();
    bool hasData(std::string key);
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
private:
    Database();
    DatabaseModel* dbModel;
};

#endif /* DATABASE_H */
