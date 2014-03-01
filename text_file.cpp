#include "text_file.hpp"
#include "to_utf16.hpp"
#include "to_utf8.hpp"
#include <fstream>

TextFile::TextFile(std::string fileName):
    fileName_(fileName)
{
    std::ifstream f(fileName_);
    while (!f.eof())
    {
        std::string line;
        std::getline(f, line);
        buffer_.push_back(toUtf16(line));
    }
}

void TextFile::save()
{
    saveAs(fileName_);
}

void TextFile::saveAs(std::string fileName)
{
    fileName_ = fileName;
    std::ofstream f(fileName_);
    for (const auto &l: buffer_)
        f << toUtf8(l) << std::endl;
}