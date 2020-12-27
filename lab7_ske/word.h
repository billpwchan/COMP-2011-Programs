/* Word Structure */

/* Enum */
enum WordType {noun, verb, adjective, adverb};

/* Constants */
const int MAX_TEXT_LENGTH = 21;
const int MAX_MEANING_LENGTH = 101;
const int MAX_WORD_NUMBER = 50;
const char wordTypeMap[][20]={"noun","verb","adjective","adverb"};

/* Structure */
struct Word{
	char text[MAX_TEXT_LENGTH], meaning[MAX_MEANING_LENGTH];
	WordType type;
};
