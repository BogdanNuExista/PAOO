#include "../include/FileHandler.h"
#include <iostream>

// Item 13: RAII - Resource acquired in constructor
FileHandler::FileHandler(const std::string& fname) 
    : filename(fname), isOpen(false) {
    file.open(filename, std::ios::in | std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        isOpen = true;
        std::cout << "FileHandler: File '" << filename << "' opened\n";
    } else {
        std::cout << "FileHandler: Failed to open file '" << filename << "'\n";
    }
}

// Item 13: RAII - Resource released in destructor
FileHandler::~FileHandler() {
    if (file.is_open()) {
        file.close();
        std::cout << "FileHandler: File '" << filename << "' closed\n";
    }
}

bool FileHandler::write(const std::string& content) {
    if (!isOpen) return false;
    file << content;
    file.flush();
    return true;
}

std::string FileHandler::read() {
    if (!isOpen) return "";
    file.seekg(0);
    std::string content;
    std::getline(file, content);
    return content;
}
