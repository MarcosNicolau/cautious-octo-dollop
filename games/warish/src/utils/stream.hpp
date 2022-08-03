#ifndef STREAM_H
#define STREAM_H

#include <iostream>
#include <fstream>
#include "strings.hpp"
using namespace std;

/**
 * Reads data in the form VAR=VALUE
 *
 * @param file pass the file path from where to read the data
 * @param varToRead pass the variable name to get value
 */
string getDataFromFile(string file, string varToRead, string defaultValue = "")
{
    fstream fs;
    fs.open(file);
    string res;
    string value = defaultValue;
    while (getline(fs, res))
    {
        int equalSignPos = res.find("=");
        string varName = res.substr(0, equalSignPos);
        if (varName != toUpperCase(varToRead))
            continue;
        value = res.substr(equalSignPos + 1);
        break;
    }
    fs.close();
    return value;
}

/**
 * Deletes data in the form VAR=VALUE
 *
 * @param file pass the file path from where to read the data
 * @param varToDelete pass the variable name to get value
 */
void deleteDataFromFile(string file, string varToDelete)
{
    fstream fs;
    fs.open(file);
    fs.seekg(0, ios::beg);
    string res;
    while (getline(fs, res))
    {
        int equalSignPos = res.find("=");
        string varName = res.substr(0, equalSignPos);
        if (varName != toUpperCase(varToDelete))
            continue;
        res.replace(0, res.length(), "");
        fs << res;
        break;
    }
    fs.close();
}

struct LineSaveRes
{
    string line;
    bool hasChanged;
};

LineSaveRes lineSave(string line, string var, string value)
{
    int equalSignPos = line.find("=");
    string varName = line.substr(0, equalSignPos);
    if (varName != toUpperCase(var))
        return {line, false};
    line.replace(equalSignPos + 1, line.length(), value);
    return {line, true};
}

/**
 * Saves data in the form VAR=VALUE
 *
 */
void saveDataToFile(string file, string var, string value)
{
    fstream fs;
    // To replace the data, we will rewrite everything in a new file
    fstream fsNew;
    string newFileName = file + "random.txt";
    // We open and close the file with ios::out to auto create the file if they don't exist
    fs.open(file, ios::out);
    fsNew.open(newFileName, ios::out);
    fs.close();
    fsNew.close();

    fs.open(file);
    fsNew.open(newFileName);
    fs.seekg(0, ios::beg);
    bool varExists = false;
    string res;
    while (getline(fs, res))
    {
        LineSaveRes result = lineSave(res, var, value);
        fsNew << result.line;
        if (result.hasChanged)
        {
            varExists = true;
            break;
        }
    }
    // This means that the variable didn't exist
    // So there is no need to create the new file
    // So we delete it
    if (!varExists)
    {
        fs.clear();
        fs << toUpperCase(var) + "=" + value << endl;
        remove(newFileName.c_str());
    }
    // In this case, the variable value got replaced
    // So we just rename the file to overwrite the old file
    else
    {
        rename((newFileName).c_str(), file.c_str());
    }
    fs.close();
    fsNew.close();
}

struct BulkSave
{
    string var;
    string value;
};

/**
 * Saves data in the form VAR=VALUE
 *
 */
void bulkSave(string file, vector<BulkSave> data)
{
    // This function follows the same logic from the single save but does it in a loop
    fstream fs;
    fstream fsNew;
    string newFileName = file + "random.txt";
    fs.open(file, ios::out);
    fsNew.open(newFileName, ios::out);
    fs.close();
    fsNew.close();
    fs.open(file);
    fsNew.open(newFileName);
    string res;

    for (int i = 0; i < data.size(); i++)
    {
        fs.seekg(0, ios::beg);
        string var = data[i].var;
        string value = data[i].value;
        bool varExists = false;
        while (getline(fs, res))
        {
            cout << res << endl;
            LineSaveRes result = lineSave(res, var, value);
            fsNew << result.line << endl;
            if (result.hasChanged)
            {
                varExists = true;
                break;
            }
        };
        // This means that the variable didn't exist
        if (!varExists)
        {
            fsNew.clear();
            fsNew << toUpperCase(var) + "=" + value << endl;
        }
    };
    // Finally remove and rename the new file
    remove(file.c_str());
    rename((newFileName).c_str(), file.c_str());
    fs.close();
    fsNew.close();
};

#endif
