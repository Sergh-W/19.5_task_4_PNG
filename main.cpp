#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string filePath;
    std::string fileExt = ".png";
    std::cout << "Enter the path to the file:" << std::endl;
    std::cin >> filePath;                                                                
    /*
     * unsigned end = filePath.length() - fileExt.length();
     * if(!filePath.substr(end,fileExt.length()) == fileExt) {};
     */
    if (!filePath.ends_with(fileExt))
    {
        std::cerr << "Invalid file path or file extension does not match!" << std::endl;
    }
    else
    {
        std::ifstream image;
        char header[4];
        image.open(filePath, std::ios::binary);
        image.read(header, 4);
        if (header[0] == -119 && header[1] == 'P' && header[2] == 'N' && header[3] == 'G') {
            std::cout << "This file is a PNG image." << std::endl;
        } else {
            std::cerr << "This file is not a PNG image!" << std::endl;
        }
        image.close();
        return 0;
    }
}
