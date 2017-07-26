// 标准库头文件
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <istream>
#include <cstddef>
#include <cctype>
#include <iterator>

using std::pair;
using std::vector;
using std::string;
using std::pair;
using std::map;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ios;
using std::make_pair;
using std::set;
using std::copy;


// typedefs 使声明更简单
typedef pair<short,short> location;
typedef vector<location> loc;
typedef vector<string> text;
typedef pair<text*,loc*> text_loc;

class TextQuery {
public:
	TextQuery() { memset( this, 0, sizeof( TextQuery )); }
	static void filter_elements( string felems ) { filt_elems = felems; }
	
	void query_text();
	void display_map_text();
	void display_text_locations();
	
	void doit() 
	{
		retrieve_text();
		separate_words();
		filter_text();
		suffix_text();
		strip_caps();
		build_word_map();
	}

private:
	void retrieve_text();
	void separate_words();
	void filter_text();
	void strip_caps();
	void suffix_text();
	void suffix_s( string& );
	void build_word_map();

private:
	vector<string> *lines_of_text;
	text_loc *text_locations;
	map< string, loc *> *word_map;
	static string filt_elems;
};

string TextQuery::filt_elems( "\",.;:!<<)(\\/" );

int main()
{
    TextQuery tq;
    tq.doit();
    tq.query_text();
    tq.display_map_text();
}

void TextQuery::retrieve_text()
{
    string file_name;

    cout << "please enter file name: ";
    cin >> file_name;

    ifstream infile( file_name.c_str(), ios::in );
    if ( !infile ) {
        cerr << "oops! unable to open file "
        << file_name << " -- bailing out!\n";
        exit( - 1 );
    }
    else cout << "\n";

    lines_of_text = new vector<string>;
    string textline;
    
    while ( getline( infile, textline, '\n' ))
        lines_of_text->push_back( textline );
}

void TextQuery::separate_words()
{
    vector<string> *words = new vector<string>;
    vector<location> *locations = new vector<location>;

    for ( short line_pos = 0; line_pos < lines_of_text->size(); line_pos++ ) {
        short word_pos = 0;
        string textline = (*lines_of_text)[ line_pos ];
    
        string::size_type eol = textline.length();
        string::size_type pos = 0, prev_pos = 0;
    
        while (( pos = textline.find_first_of( ' ', pos )) != string::npos ) {
            words->push_back(textline.substr( prev_pos, pos - prev_pos ));
            locations->push_back(make_pair( line_pos, word_pos ));
            word_pos++; pos++; prev_pos = pos;
        }
        words->push_back(textline.substr( prev_pos, pos - prev_pos ));
        locations ->push_back(make_pair(line_pos,word_pos));
    }
    
    text_locations = new text_loc( words, locations );
}

void TextQuery::filter_text()
{
    if ( filt_elems.empty() )
        return;
    vector<string> *words = text_locations->first;
    vector<string>::iterator iter = words->begin();
    vector<string>::iterator iter_end = words->end();

    while ( iter != iter_end ) {
        string::size_type pos = 0;
        while (( pos = (*iter).find_first_of( filt_elems, pos )) != string::npos ) 
            (*iter).erase(pos,1);
		++iter;
    }
}

void TextQuery::suffix_text()
{
    vector<string> *words = text_locations->first;
    vector<string>::iterator iter = words->begin();
    vector<string>::iterator iter_end = words->end();

    while ( iter != iter_end ) {
        if ( (*iter).size() <= 3 )
        { iter++; continue; }

        if ( (*iter)[ (*iter).size()- 1 ] == 's' )
            suffix_s( *iter );

    // 其他的后缀处理放在这里
    iter++;
    }
}

void TextQuery::suffix_s( string &word )
{
    string::size_type spos = 0;
    string::size_type pos3 = word.size()- 3;

    // "ous", "ss", "is", "ius"
    string suffixes( "oussisius" );
    if ( ! word.compare( pos3, 3, suffixes, spos, 3 ) ||
        ! word.compare( pos3, 3, suffixes, spos+6, 3 ) ||
        ! word.compare( pos3+1, 2, suffixes, spos+2, 2 ) ||
        ! word.compare( pos3+1, 2, suffixes, spos+4, 2 ))
        return;
        
    string ies( "ies" );
    if ( ! word.compare( pos3, 3, ies )) {
        word.replace( pos3, 3, 1, 'y' );
        return;
    }
    
    string ses( "ses" );
    if ( ! word.compare( pos3, 3, ses )) {
        word.erase( pos3+1, 2 );
        return;
    }
    
    // 去掉尾部的 's'
    word.erase( pos3+2 );
    
    // watch out for "'s"
    if ( word[ pos3+1 ] == '\'' )
        word.erase( pos3+1 );
}

void TextQuery::strip_caps()
{
    vector<string> *words = text_locations->first;
    vector<string>::iterator iter = words->begin();
    vector<string>::iterator iter_end = words->end();

    string caps( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );

    while ( iter != iter_end ) {
        string::size_type pos = 0;
        while (( pos = (*iter).find_first_of( caps, pos )) != string::npos )
            (*iter)[ pos ] = tolower( (*iter)[pos] );
        ++iter;
    }
}

void TextQuery::build_word_map()
{
    word_map = new map< string, loc* >;
    typedef map<string,loc*>::value_type value_type;
    typedef set<string>::difference_type diff_type;
    set<string> exclusion_set;
    
    ifstream infile( "exclusion_set" );
    if ( !infile ) {
        static string default_excluded_words[25] = {
            "the","and","but","that","then","are","been",
            "can","can't","cannot","could","did","for",
            "had","have","him","his","her","its","into",
            "were","which","when","with","would"
        };
        
    cerr << "warning! unable to open word exclusion file! -- "
        << "using default set\n";
    
    copy( default_excluded_words, default_excluded_words+25,
        inserter( exclusion_set, exclusion_set.begin() ));
    } else {
        istream_iterator< string > input_set( infile ), eos;
        copy( input_set, eos, inserter( exclusion_set, exclusion_set.begin() ));
    }
    
    // 遍历单词, 输入键/值对
    vector<string> *text_words = text_locations->first;
    vector<location> *text_locs = text_locations->second;
    register int elem_cnt = text_words->size();
    
    for ( int ix = 0; ix < elem_cnt; ++ix ) {
        string textword = ( *text_words )[ ix ];
        if ( textword.size() < 3 || exclusion_set.count( textword ))
            continue;
        if ( ! word_map->count((*text_words)[ix] )) { // 没有, 添加:
            loc *ploc = new vector<location>;
            ploc->push_back( (*text_locs)[ix] );
            word_map->insert( value_type( (*text_words)[ix], ploc ));
        } else 
            (*word_map)[(*text_words)[ix]]->push_back( (*text_locs)[ix] );
    }
}

void TextQuery::query_text()
{
    string query_text;
    do {
        cout << "enter a word against which to search the text.\n"
            << "to quit, enter a single character ==> ";
        cin >> query_text;
        if ( query_text.size() < 2 ) break;

        string caps( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
        string::size_type pos = 0;
        while (( pos = query_text.find_first_of( caps, pos )) != string::npos )
            query_text[ pos ] = tolower( query_text[pos] )
            ;

        // 如果对map 索引, 输入query_text, 如无
        // 说明没有要找的词
        if ( !word_map->count( query_text )) {
            cout << "\nSorry. There are no entries for "
                << query_text << ".\n\n";
            continue;
        }
    
        loc *ploc = (*word_map)[ query_text ];

        set<short> occurrence_lines;
        loc::iterator liter = ploc->begin(), liter_end = ploc->end();
        while ( liter != liter_end ) {
            occurrence_lines.insert(
            occurrence_lines.end(), (*liter).first);
            ++liter;
        }

        register int size = occurrence_lines.size();
        cout << "\n" << query_text
            << " occurs " << size
            << (size == 1 ? " time:" : " times:")
            << "\n\n";

        set<short>::iterator it=occurrence_lines.begin();
        for ( ; it != occurrence_lines.end(); ++it ) {
            int line = *it;
            cout << "\t( line "
                // 不要用从 0 开始有
                // 文本行把用户弄迷糊了
                << line + 1 << " ) "
                << (*lines_of_text)[line] << endl;
        }
        cout << endl;
    }
    
    while ( ! query_text.empty() )
        ;
    cout << "Ok, bye!\n";
}

void TextQuery::display_map_text()
{
    typedef map<string,loc*> map_text;
    map_text::iterator iter = word_map->begin(),
    iter_end = word_map->end();
    while ( iter != iter_end ) {
        cout << "word: " << (*iter).first << " (";

        int loc_cnt = 0;
        loc *text_locs = (*iter).second;
        loc::iterator liter = text_locs->begin(), liter_end = text_locs->end();

        while ( liter != liter_end ) {
            if ( loc_cnt )
                cout << ",";
            else 
                ++loc_cnt;
            cout << "(" << (*liter).first
                << "," << (*liter).second << ")";
            ++liter;
        }
        
        cout << ")\n";
        ++iter;
    }
    
    cout << endl;
}

void TextQuery::display_text_locations()
{
    vector<string> *text_words = text_locations->first;
    vector<location> *text_locs = text_locations->second;
    register int elem_cnt = text_words ->size();

    if ( elem_cnt != text_locs->size() ) {
        cerr << "oops! internal error: word and position vectors "
            << "are of unequal size \n"
            << "words: " << elem_cnt << " "
            << "locs: " << text_locs->size()
            << " -- bailing out!\n";
            exit( - 2 );
    }
    
    for ( int ix = 0; ix < elem_cnt; ix++ ) {
        cout << "word: " << (*text_words)[ ix ] << "\t"
        << "location: ("
        << (*text_locs)[ix].first << ","
        << (*text_locs)[ix].second << ")"
        << "\n";
    }
    
    cout << endl;
}
