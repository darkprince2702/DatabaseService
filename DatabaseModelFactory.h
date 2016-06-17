/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DatabaseModelFactory.h
 * Author: ductn
 *
 * Created on June 16, 2016, 2:06 PM
 */

#ifndef DATABASEMODELFACTORY_H
#define DATABASEMODELFACTORY_H

#include "DatabaseModel.h"
#include "LevelDBModel.h"

class DatabaseModelFactory {
public:
    DatabaseModel* getDatabaseModel(std::string dbModelType);
    
};

#endif /* DATABASEMODELFACTORY_H */

