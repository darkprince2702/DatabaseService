/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DatabaseModelFactory.cpp
 * Author: ductn
 *
 * Created on June 16, 2016, 2:06 PM
 */

#include "DatabaseModelFactory.h"

DatabaseModel* DatabaseModelFactory::getDatabaseModel(std::string dbModelType) {
    if (dbModelType == "LevelDB") {
        return LevelDBModel::getInstance();
    } else {
        return NULL;
    }
}
