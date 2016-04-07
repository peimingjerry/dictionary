%{
// This is a example gperf input file.

#include <cstring>
#include "struct.h"

#undef TOTAL_KEYWORDS
#undef MIN_WORD_LENGTH
#undef MAX_WORD_LENGTH
#undef MIN_HASH_VALUE
#undef MAX_HASH_VALUE

%}

struct dictionaryInfo { const char *; const char *; };
%%
aa,   "AA"
bb,   "BB"
cc,   "CC"
%%
