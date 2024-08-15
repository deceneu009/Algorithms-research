#include "OpenFIle.h"

void OpenFileRandom(long int size, std::ifstream& inputFile, std::string &NameOfFile)
{
#if defined(__linux__)
    if (size == 10)
    {
        inputFile.open("filegenerators/sizefiles/random/size1random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size1.csv";
    }
    else if (size == 100)
    {
        inputFile.open("filegenerators/sizefiles/random/size2random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size2.csv";
    }
    else if (size == 1000)
    {
        inputFile.open("filegenerators/sizefiles/random/size3random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size3.csv";
    }
    else if (size == 10000)
    {
        inputFile.open("filegenerators/sizefiles/random/size4random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size4.csv";
    }
    else if (size == 100000)
    {
        inputFile.open("filegenerators/sizefiles/random/size5random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size5.csv";
    }
    else if (size == 1000000)
    {
        inputFile.open("filegenerators/sizefiles/random/size6random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size6.csv";
    }
    else if (size == 10000000)
    {
        inputFile.open("filegenerators/sizefiles/random/size7random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size7.csv";
    }
    else if (size == 100000000)
    {
        inputFile.open("filegenerators/sizefiles/random/size8random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size8.csv";
    }
    else if (size == 1000000000)
    {
        inputFile.open("filegenerators/sizefiles/random/size9random.txt");
        NameOfFile = "ResultsRandom/ResultsRandom_Size9.csv";
    }
#elif defined(_WIN32) || defined(_WIN64)
    if (size == 10)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size1random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size1.csv)";
    }
    else if (size == 100)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size2random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size2.csv)";
    }
    else if (size == 1000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size3random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size3.csv)";
    }
    else if (size == 10000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size4random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size4.csv)";
    }
    else if (size == 100000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size5random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size5.csv)";
    }
    else if (size == 1000000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size6random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size6.csv)";
    }
    else if (size == 10000000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size7random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size7.csv)";
    }
    else if (size == 100000000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size8random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size8.csv)";
    }
    else if (size == 1000000000)
    {
        inputFile.open(R"(filegenerators\sizefiles\random\size9random.txt)");
        NameOfFile = R"(ResultsRandom\ResultsRandom_Size9.csv)";
    }
#endif
}

void OpenFileAlmost(long int size, std::ifstream& inputFile, std::string &NameOfFile)
{
#if defined(__linux__)
    if (size == 10)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size1Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size1.csv";
    }
    else if (size == 100)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size2Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size2.csv";
    }
    else if (size == 1000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size3Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size3.csv";
    }
    else if (size == 10000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size4Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size4.csv";
    }
    else if (size == 100000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size5Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size5.csv";
    }
    else if (size == 1000000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size6Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size6.csv";
    }
    else if (size == 10000000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size7Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size7.csv";
    }
    else if (size == 100000000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size8Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size8.csv";
    }
    else if (size == 1000000000)
    {
        inputFile.open("filegenerators/sizefiles/almostSorted/size9Almost.txt");
        NameOfFile = "ResultsAlmost/ResultsAlmost_Size9.csv";
    }
#elif defined(_WIN32) || defined(_WIN64)
    // for almost sorted | opening the correct file
        if (size == 10)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size1Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size1.csv)";
        }
        else if (size == 100)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size2Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size2.csv)";
        }
        else if (size == 1000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size3Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size3.csv)";
        }
        else if (size == 10000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size4Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size4.csv)";
        }
        else if (size == 100000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size5Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size5.csv)";
        }
        else if (size == 1000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size6Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size6.csv)";
        }
        else if (size == 10000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size7Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size7.csv)";
        }
        else if (size == 100000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size8Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size8.csv)";
        }
        else if (size == 1000000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\almostSorted\size9Almost.txt)");
            NameOfFile = R"(ResultsAlmost\ResultsAlmost_Size9.csv)";
        }
#endif
}

void OpenFileReversed(long int size, std::ifstream& inputFile, std::string &NameOfFile)
{
#if defined(__linux__)
    if (size == 10)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size1rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size1.csv";
    }
    else if (size == 100)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size2rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size2.csv";
    }
    else if (size == 1000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size3rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size3.csv";
    }
    else if (size == 10000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size4rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size4.csv";
    }
    else if (size == 100000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size5rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size5.csv";
    }
    else if (size == 1000000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size6rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size6.csv";
    }
    else if (size == 10000000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size7rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size7.csv";
    }
    else if (size == 100000000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size8rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size8.csv";
    }
    else if (size == 1000000000)
    {
        inputFile.open("filegenerators/sizefiles/reverse/size9rev.txt");
        NameOfFile = "ResultsReverse/ResultsReverse_Size9.csv";
    }
#elif defined(_WIN32) || defined(_WIN64)
        // for reverse | Opening the correct file
        if (size == 10)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size1rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size1.csv)";
        }
        else if (size == 100)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size2rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size2.csv)";
        }
        else if (size == 1000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size3rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size3.csv)";
        }
        else if (size == 10000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size4rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size4.csv)";
        }
        else if (size == 100000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size5rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size5.csv)";
        }
        else if (size == 1000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size6rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size6.csv)";
        }
        else if (size == 10000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size7rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size7.csv)";
        }
        else if (size == 100000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size8rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size8.csv)";
        }
        else if (size == 1000000000)
        {
            inputFile.open(R"(filegenerators\sizefiles\reverse\size9rev.txt)");
            NameOfFile = R"(ResultsReverse\ResultsReverse_Size9.csv)";
        }
#endif
}