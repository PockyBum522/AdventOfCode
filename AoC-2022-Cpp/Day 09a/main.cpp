#include <list>

#include "Logic/ListProcessor.h"
#include "RawData/RawDataLoader/RawDataLoader.h"
#include "RawData/RawData.h"

int main()
{
    list<string> rawDataLines = RawDataLoader::LoadRawDataIntoList(RawData::INPUT_DATA_RAW);

    ListProcessor::ProcessList(rawDataLines);

    return 0;
}