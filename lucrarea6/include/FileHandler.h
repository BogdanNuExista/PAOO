#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>

// Item 13: Use objects to manage resources (RAII pattern)
class FileHandler {
private:
    std::fstream file;
    std::string filename;
    bool isOpen;

public:
    FileHandler(const std::string& fname);
    ~FileHandler();  // Destructor automatically closes file
    
    // Prohibit copying (file handles shouldn't be copied)
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
    
    bool write(const std::string& content);
    std::string read();
    bool isFileOpen() const { return isOpen; }
};

#endif // FILEHANDLER_H
