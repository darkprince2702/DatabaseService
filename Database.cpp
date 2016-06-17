/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Database.cpp
 * Author: ductn
 * 
 * Created on June 16, 2016, 10:25 AM
 */

#include "Database.h"

Database::Database() {
    DatabaseModelFactory factory;
    dbModel = factory.getDatabaseModel("LevelDB");
}

Database* Database::getInstance() {
    static std::mutex mutex;
    static Database* instance;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL)
            instance = new Database();
    }
    
    return instance;
}

bool Database::hasData(std::string key) {
     return dbModel->hasData(key);
}

GetResult Database::getData(std::string key) {
     return dbModel->getData(key);
}

bool Database::setData(std::string key, std::string value) {
     return dbModel->setData(key, value);
}

bool Database::removeData(std::string key) {
     return dbModel->removeData(key);
}

