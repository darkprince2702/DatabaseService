/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DatabaseModel.h
 * Author: ductn
 *
 * Created on June 16, 2016, 10:30 AM
 */

#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include "databaseservice_types.h"

class DatabaseModel {
public:
    virtual bool hasData(std::string key) = 0;
    virtual GetResult getData(std::string key) = 0;
    virtual bool setData(std::string key, std::string value) = 0;
    virtual bool removeData(std::string key) = 0;
};

#endif /* DATABASEMODEL_H */

