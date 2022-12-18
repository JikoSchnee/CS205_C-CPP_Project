#include <iostream>
#include "JChannel.h"

bool abortIfError = true;
bool accuracyWarning = true;

////////constructor/////////////////////////////////////////////////////////////////////////////////////////////////////
JChannel::JChannel(size_t ROW, size_t COL, unsigned char *dataP) {
    rows = ROW;
    cols = COL;
    if (ROW == 0 || COL == 0) {
        std::cerr << "Error: Invalid size." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!dataP) {
        std::cerr << "Error: Input a nullptr data pointer." << std::endl;
        if (abortIfError)std::abort();
    }
    type = 1;
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
            if (abortIfError)std::abort();
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
    if (type == 1) {
        memcpy(ucP, dataP, ROW * COL * sizeof(unsigned char));
    } else if (type == 2) {
        memcpy(shortP, dataP, ROW * COL * sizeof(short));
    } else if (type == 3) {
        memcpy(intP, dataP, ROW * COL * sizeof(int));
    } else if (type == 4) {
        memcpy(floatP, dataP, ROW * COL * sizeof(float));
    } else if (type == 5) {
        memcpy(doubleP, dataP, ROW * COL * sizeof(double));
    } else {

    }
}

JChannel::JChannel(size_t ROW, size_t COL, short *dataP) {
    rows = ROW;
    cols = COL;
    if (ROW == 0 || COL == 0) {
        std::cerr << "Error: Invalid size." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!dataP) {
        std::cerr << "Error: Input a nullptr data pointer." << std::endl;
        if (abortIfError)std::abort();
    }
    type = 2;
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
    if (type == 1) {
        memcpy(ucP, dataP, ROW * COL * sizeof(unsigned char));
    } else if (type == 2) {
        memcpy(shortP, dataP, ROW * COL * sizeof(short));
    } else if (type == 3) {
        memcpy(intP, dataP, ROW * COL * sizeof(int));
    } else if (type == 4) {
        memcpy(floatP, dataP, ROW * COL * sizeof(float));
    } else if (type == 5) {
        memcpy(doubleP, dataP, ROW * COL * sizeof(double));
    } else {

    }
}

JChannel::JChannel(size_t ROW, size_t COL, int *dataP) {
    rows = ROW;
    cols = COL;
    if (ROW == 0 || COL == 0) {
        std::cerr << "Error: Invalid size." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!dataP) {
        std::cerr << "Error: Input a nullptr data pointer." << std::endl;
        if (abortIfError)std::abort();
    }
    type = 3;
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
            if (abortIfError)std::abort();
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
    if (type == 1) {
        memcpy(ucP, dataP, ROW * COL * sizeof(unsigned char));
    } else if (type == 2) {
        memcpy(shortP, dataP, ROW * COL * sizeof(short));
    } else if (type == 3) {
        memcpy(intP, dataP, ROW * COL * sizeof(int));
    } else if (type == 4) {
        memcpy(floatP, dataP, ROW * COL * sizeof(float));
    } else if (type == 5) {
        memcpy(doubleP, dataP, ROW * COL * sizeof(double));
    } else {

    }
}

JChannel::JChannel(size_t ROW, size_t COL, float *dataP) {
    rows = ROW;
    cols = COL;
    if (ROW == 0 || COL == 0) {
        std::cerr << "Error: Invalid size." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!dataP) {
        std::cerr << "Error: Input a nullptr data pointer." << std::endl;
        if (abortIfError)std::abort();
    }
    type = 4;
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
            if (abortIfError)std::abort();
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
    if (type == 1) {
        memcpy(ucP, dataP, ROW * COL * sizeof(unsigned char));
    } else if (type == 2) {
        memcpy(shortP, dataP, ROW * COL * sizeof(short));
    } else if (type == 3) {
        memcpy(intP, dataP, ROW * COL * sizeof(int));
    } else if (type == 4) {
        memcpy(floatP, dataP, ROW * COL * sizeof(float));
    } else if (type == 5) {
        memcpy(doubleP, dataP, ROW * COL * sizeof(double));
    } else {

    }
}

JChannel::JChannel(size_t ROW, size_t COL, double *dataP) {
    rows = ROW;
    cols = COL;
    if (ROW == 0 || COL == 0) {
        std::cerr << "Error: Invalid size." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!dataP) {
        std::cerr << "Error: Input a nullptr data pointer." << std::endl;
        if (abortIfError)std::abort();
    }
    type = 5;
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
            if (abortIfError)std::abort();
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
    try {
        if (type == 1) {
            memcpy(ucP, dataP, ROW * COL * sizeof(unsigned char));
        } else if (type == 2) {
            memcpy(shortP, dataP, ROW * COL * sizeof(short));
        } else if (type == 3) {
            memcpy(intP, dataP, ROW * COL * sizeof(int));
        } else if (type == 4) {
            memcpy(floatP, dataP, ROW * COL * sizeof(float));
        } else if (type == 5) {
            memcpy(doubleP, dataP, ROW * COL * sizeof(double));
        } else {

        }
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
        delete[] dataP;
    }
}

////////constructor/////////////////////////////////////////////////////////////////////////////////////////////////////
////////destructor//////////////////////////////////////////////////////////////////////////////////////////////////////
JChannel::~JChannel() {
//    if (type == 1) {
//        delete[] ucP;
//    } else if (type == 2) {
//        delete[] shortP;
//    } else if (type == 3) {
//        delete[] intP;
//    } else if (type == 4) {
//        delete[] floatP;
//    } else if (type == 5) {
//        delete[] doubleP;
//    } else {
//
//    }
}

////////destructor//////////////////////////////////////////////////////////////////////////////////////////////////////
////////Getter And Setter///////////////////////////////////////////////////////////////////////////////////////////////
size_t JChannel::getRow() {
    return rows;
}

size_t JChannel::getCol() {
    return cols;
}

char JChannel::getType() {
    if (type == 1) {
        return 'h';
    } else if (type == 2) {
        return 's';
    } else if (type == 3) {
        return 'i';
    } else if (type == 4) {
        return 'f';
    } else if (type == 5) {
        return 'd';
    } else {
        std::cerr << "Error: Getting unknown type data." << std::endl;
        if (abortIfError)std::abort();
        return '0';
    }
}

unsigned char JChannel::getUCData(const size_t row, const size_t col) {
    if (type != 1) {
        std::cerr << "Error: The matrix type is not unsigned char." << std::endl;
        if (abortIfError)std::abort();
        return 0;
    }
    return ucP[(row - 1) * cols + (col - 1)];
}

short JChannel::getShortData(size_t row, size_t col) {
    if (type != 2) {
        std::cerr << "Error: The matrix type is not short." << std::endl;
        if (abortIfError)std::abort();
        return 0;
    }
    return shortP[(row - 1) * cols + (col - 1)];
}

int JChannel::getIntData(size_t row, size_t col) {
    if (type != 3) {
        std::cerr << "Error: The matrix type is not integer." << std::endl;
        if (abortIfError)std::abort();
        return 0;
    }
    return intP[(row - 1) * cols + (col - 1)];
}

float JChannel::getFloatData(size_t row, size_t col) {
    if (type != 4) {
        std::cerr << "Error: The matrix type is not float." << std::endl;
        if (abortIfError)std::abort();
        return 0;
    }
    return floatP[(row - 1) * cols + (col - 1)];
}

double JChannel::getDoubleData(size_t row, size_t col) {
    if (type != 5) {
        std::cerr << "Error: The matrix type is not double." << std::endl;
        if (abortIfError)std::abort();
        return 0;
    }
    return doubleP[(row - 1) * cols + (col - 1)];
}

////////Getter And Setter///////////////////////////////////////////////////////////////////////////////////////////////
////////Operator////////////////////////////////////////////////////////////////////////////////////////////////////////
JChannel JChannel::operator+(const JChannel &Mat) const {
    if (rows != Mat.rows || cols != Mat.cols) {
        std::cerr << "Error: Adding two matrix whose rows and cols are not match." << std::endl;
        if (abortIfError)std::abort();
    }
    if (type != Mat.type && accuracyWarning) {
        std::cerr << "Warning: Adding two different types of matrix may cause accuracy loss." << std::endl;
    }
    size_t resultType = 0;
    resultType = type > Mat.type ? type : Mat.type;
    if (resultType == 0) {
        std::cerr << "Error: Adding result is an unknown type matrix." << std::endl;
        if (abortIfError)std::abort();
    }
    if (resultType == 1) {
        unsigned char *data = nullptr;
        try {
            data = new unsigned char[rows * cols * sizeof(unsigned char)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 2) {
        short *data = nullptr;
        try {
            data = new short[rows * cols * sizeof(short)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 3) {
        int *data = nullptr;
        try {
            data = new int[rows * cols * sizeof(int)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 4) {
        float *data = nullptr;
        try {
            data = new float[rows * cols * sizeof(float)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 5) {
        double *data = nullptr;
        try {
            data = new double[rows * cols * sizeof(double)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else {

    }
}

JChannel JChannel::operator-(const JChannel &Mat) const {
    if (rows != Mat.rows || cols != Mat.cols) {
        std::cerr << "Error: Subtracting two matrix whose rows and cols are not match." << std::endl;
        if (abortIfError)std::abort();
    }
    if (type != Mat.type && accuracyWarning) {
        std::cerr << "Warning: Subtracting two different types of matrix may cause accuracy loss." << std::endl;
    }
    size_t resultType = 0;
    resultType = type > Mat.type ? type : Mat.type;
    if (resultType == 0) {
        std::cerr << "Error: Subtracting result is an unknown type matrix." << std::endl;
        if (abortIfError)std::abort();
    }
    if (resultType == 1) {
        unsigned char *data = nullptr;
        try {
            data = new unsigned char[rows * cols * sizeof(unsigned char)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 2) {
        short *data = nullptr;
        try {
            data = new short[rows * cols * sizeof(short)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 3) {
        int *data = nullptr;
        try {
            data = new int[rows * cols * sizeof(int)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 4) {
        float *data = nullptr;
        try {
            data = new float[rows * cols * sizeof(float)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else if (resultType == 5) {
        double *data = nullptr;
        try {
            data = new double[rows * cols * sizeof(double)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else if (type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += shortP[i];
            }
        } else if (type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += intP[i];
            }
        } else if (type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += floatP[i];
            }
        } else if (type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += doubleP[i];
            }
        } else {

        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.ucP[i];
            }
        } else if (Mat.type == 2) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.shortP[i];
            }
        } else if (Mat.type == 3) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.intP[i];
            }
        } else if (Mat.type == 4) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.floatP[i];
            }
        } else if (Mat.type == 5) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] -= Mat.doubleP[i];
            }
        } else {

        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    } else {

    }
}

JChannel JChannel::operator*(const JChannel &Mat) const {
    if (rows != Mat.cols || cols != Mat.rows) {
        std::cerr << "Error: Invalid to multiply this two matrix." << std::endl;
        if (abortIfError)std::abort();
    }
    size_t r = rows;
    size_t c = Mat.cols;
    size_t resultType = type > Mat.type ? type : Mat.type;
    if (type == 1) {
        unsigned char *data = nullptr;
        try {
            data = new unsigned char[r * c * sizeof(unsigned char)];
        } catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
        }
        unsigned char tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->ucP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * Mat.ucP[k * r + j];
                }
            }
        }
        JChannel result = JChannel(r, c, data);
        delete[] data;
        return result;
    } else if (type == 2) {
        short *data = nullptr;
        try {
            data = new short[r * c * sizeof(short)];
        } catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
        }
        short tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->shortP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * Mat.shortP[k * r + j];
                }
            }
        }
        JChannel result = JChannel(r, c, data);
        delete[] data;
        return result;
    } else if (type == 3) {
        int *data = nullptr;
        try {
            data = new int[r * c * sizeof(int)];
        } catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
        }
        int tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->intP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * Mat.intP[k * r + j];
                }
            }
        }
        JChannel result = JChannel(r, c, data);
        delete[] data;
        return result;
    } else if (type == 4) {
        float *data = nullptr;
        try {
            data = new float[r * c * sizeof(float)];
        } catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
        }
        float tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->floatP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * Mat.floatP[k * r + j];
                }
            }
        }
        JChannel result = JChannel(r, c, data);
        delete[] data;
        return result;
    } else if (type == 5) {
        double *data = nullptr;
        try {
            data = new double[r * c * sizeof(double)];
        } catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
        }
        double tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->doubleP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * Mat.doubleP[k * r + j];
                }
            }
        }
        JChannel result = JChannel(r, c, data);
        delete[] data;
        return result;
    } else {
        std::cerr << "Error: Multiplying an unknown type matrix." << std::endl;
        if (abortIfError)std::abort();
    }
}

JChannel &JChannel::operator=(const JChannel &Mat) {
    if (type == 1) {
        delete[] ucP;
    } else if (type == 2) {
        delete[] shortP;
    } else if (type == 3) {
        delete[] intP;
    } else if (type == 4) {
        delete[] floatP;
    } else if (type == 5) {
        delete[] doubleP;
    } else {
        std::cerr << "Error: Origin matrix is an unknown type." << std::endl;
        if (abortIfError)std::abort();
    }
    type = Mat.type;
    rows = Mat.rows;
    cols = Mat.cols;
    if (type == 1) {
        memcpy(ucP, Mat.ucP, rows * cols * sizeof(unsigned char));
    } else if (type == 2) {
        memcpy(shortP, Mat.shortP, rows * cols * sizeof(short));
    } else if (type == 3) {
        memcpy(intP, Mat.intP, rows * cols * sizeof(int));
    } else if (type == 4) {
        memcpy(floatP, Mat.floatP, rows * cols * sizeof(float));
    } else if (type == 5) {
        memcpy(doubleP, Mat.doubleP, rows * cols * sizeof(double));
    } else {
        std::cerr << "Error: Object matrix is an unknown type." << std::endl;
        if (abortIfError)std::abort();
    }
    return *this;
}

bool JChannel::operator==(const JChannel &Mat) const {
    if (rows != Mat.rows || cols != Mat.cols) {
        return false;
    }
    if (type != Mat.type) {
        return false;
    }
    if (type == 1) {
        for (int i = 0; i < rows * cols; ++i) {
            if (ucP[i] != Mat.ucP[i])return false;
        }
    } else if (type == 2) {
        for (int i = 0; i < rows * cols; ++i) {
            if (shortP[i] != Mat.shortP[i])return false;
        }
    } else if (type == 3) {
        for (int i = 0; i < rows * cols; ++i) {
            if (intP[i] != Mat.intP[i])return false;
        }
    } else if (type == 4) {
        for (int i = 0; i < rows * cols; ++i) {
            if (floatP[i] != Mat.floatP[i])return false;
        }
    } else if (type == 5) {
        for (int i = 0; i < rows * cols; ++i) {
            if (doubleP[i] != Mat.doubleP[i])return false;
        }
    } else {
        std::cerr << "Error: An unknown type occurred." << std::endl;
        if (abortIfError)std::abort();
    }
    return true;
}
////////Operator////////////////////////////////////////////////////////////////////////////////////////////////////////