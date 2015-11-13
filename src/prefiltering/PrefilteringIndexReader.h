#ifndef PREFILTERINGINDEXREADER_H
#define PREFILTERINGINDEXREADER_H

#include "IndexTable.h"
#include "DBReader.h"
#include <string>


struct PrefilteringIndexData {
    int kmerSize;
    int alphabetSize;
    int skip;
    int split;
    int local;
    int spacedKmer;
};


class PrefilteringIndexReader {
public:
    static const char *CURRENT_VERSION;
    static const char *VERSION;
    static const char *ENTRIES;
    static const char *ENTRIESIZES;
    static const char *ENTRIESNUM;
    static const char *TABLESIZE;
    static const char *META;

    static bool checkIfIndexFile(DBReader *reader);

    static void createIndexFile(std::string outDb, std::string outDbIndex, DBReader *dbr, Sequence *seq, int split,
                                int alphabetSize, int kmerSize, int skip, bool hasSpacedKmer, int searchMode, bool mask);

    static DBReader *openNewReader(DBReader *dbr);

    static IndexTable *generateIndexTable(DBReader *dbr, int split);

    static PrefilteringIndexData getMetadata(DBReader *dbr);
};

#endif
