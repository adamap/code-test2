//
//An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations: 
//a) it -> it    (no abbreviation)
//
//     1
//     b) d|o|g   --> d1g
//
//                1    1  1
//       1---5----0----5--8
//  c) i|nternationalizatio|n  --> i18n
//
//                   1
//          1---5----0
//     d) l|ocalizatio|n          --> l10n
//
//
//  Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
//  Example: 
//
//  Given dictionary = [ "deer", "door", "cake", "card" ]
//
//        isUnique("dear") -> false
//        isUnique("cart") -> true
//        isUnique("cane") -> false
//        isUnique("make") -> true
//
//
//
class ValidWordAbbr {
    unordered_map<string, unordered_set<string>>hash_map;
public:
    ValidWordAbbr(vector<string> &dictionary) 
    {
        for ( int i = 0; i < dictionary.size(); i++)
        {
            string s = dictionary[i][0] + to_string(dictionary[i].length()-2)+dictionary[i].back();
            hash_map[s].insert(dictionary[i]);
        }
    }

    bool isUnique(string word) 
    {
        string s = word[0] + to_string(word.length()-2)+word.back();
        if ( hash_map.find(s) == hash_map.end())
        {
            return 1;
        }
        else
        {
            unordered_set<string>::iterator it;
            
            int same = 0, total = 0;
            for ( it = hash_map[s].begin(); it != hash_map[s].end(); it++)
            {
                total++;
                if (*it == word)
                {
                    same++;
                }
            }
            
            if ( total > same)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
