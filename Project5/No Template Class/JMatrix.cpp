
#include "JMatrix.h"
bool abortIfError = true;
unsigned char JMatrix::getUCData(size_t channel, size_t row, size_t col) {
    if (channel<1||channel>chans){
        std::cerr << "Error: Getting channel out of index." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!channels[channel-1]){
        std::cerr << "Error: Getting channel that is empty." << std::endl;
        if (abortIfError)std::abort();
    }
    return channels[channel-1].getUCData(row,col);
}

short JMatrix::getShortData(size_t channel, size_t row, size_t col) {
    if (channel<1||channel>chans){
        std::cerr << "Error: Getting channel out of index." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!channels[channel-1]){
        std::cerr << "Error: Getting channel that is empty." << std::endl;
        if (abortIfError)std::abort();
    }
    return channels[channel-1]->getShortData(row,col);
}

int JMatrix::getIntData(size_t channel, size_t row, size_t col) {
    if (channel<1||channel>chans){
        std::cerr << "Error: Getting channel out of index." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!channels[channel-1]){
        std::cerr << "Error: Getting channel that is empty." << std::endl;
        if (abortIfError)std::abort();
    }
    return channels[channel-1]->getIntData(row,col);
}

float JMatrix::getFloatData(size_t channel, size_t row, size_t col) {
    if (channel<1||channel>chans){
        std::cerr << "Error: Getting channel out of index." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!channels[channel-1]){
        std::cerr << "Error: Getting channel that is empty." << std::endl;
        if (abortIfError)std::abort();
    }
    return channels[channel-1]->getFloatData(row,col);
}

double JMatrix::getDoubleData(size_t channel, size_t row, size_t col) {
    if (channel<1||channel>chans){
        std::cerr << "Error: Getting channel out of index." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!channels[channel-1]){
        std::cerr << "Error: Getting channel that is empty." << std::endl;
        if (abortIfError)std::abort();
    }
    return channels[channel-1]->getDoubleData(row,col);
}


