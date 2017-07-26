#include <map>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	using std::map;
	using std::string;
	using std::cout;
	using std::endl;
	using std::vector;
	using std::less;
	using std::allocator;
	using std::pair;
	
	map< string, string > trans_map;
	typedef map< string, string >::value_type valType;
	
	// 第一个权宜之计: 将转换对固定写在代码中
	trans_map.insert( valType( "gratz", "grateful" ));
	trans_map.insert( valType( "'em", "them" ));
	trans_map.insert( valType( "cuz", "because" ));
	trans_map.insert( valType( "nah", "no" ));
	trans_map.insert( valType( "sez", "says" ));
	trans_map.insert( valType( "tanx", "thanks" ));
	trans_map.insert( valType( "wuz", "was" ));
	trans_map.insert( valType( "pos", "suppose" ));
	
	// ok: 显示trans_map
	map< string,string >::iterator it;

	cout << "Here is our transformation map: \n\n";
	for ( it = trans_map.begin();
		it != trans_map.end(); ++it )
		cout << "key: " << (*it).first << "\t"
			<< "value: " << (*it).second << "\n";
	cout << "\n\n";
	
	// 第二个权宜之计: 固定写入文字.
	string textarray[14]={ "nah", "I", "sez", "tanx", "cuz", "I",
		"wuz", "pos", "to", "not", "cuz", "I", "wuz", "gratz" };

	vector< string > text( textarray, textarray+14 );
	vector< string >::iterator iter;
	
	// ok: 显示 text
	cout << "Here is our original string vector: \n\n";
	int cnt = 1;
	for ( iter = text.begin(); iter != text.end(); ++iter, ++cnt )
		cout << *iter << ( cnt % 8 ? " " : "\n" );
	cout << "\n\n\n";

	// 包含统计信息的map——动态生成
	map< string,int > stats;
	typedef map< string,int >::value_type statsValType;

	// ok: 真正的 map 工作——程序的核心
	for ( iter = text.begin(); iter != text.end(); ++iter )
		if (( it = trans_map.find( *iter )) != trans_map.end() )
		{
			if ( stats.count( *iter ))
				stats[ *iter ] += 1;
			else stats.insert( statsValType( *iter, 1 ));
				*iter = (*it).second;
		}
	
	// ok: 显示被转换后的 vector
	cout << "Here is our transformed string vector: \n\n";
	cnt = 1;
	for ( iter = text.begin(); iter != text.end(); ++iter, ++cnt )
		cout << *iter << ( cnt % 8 ? " " : "\n" );
	cout << "\n\n\n";
	
	// ok: 现在对统计 map 进行迭代
	cout << "Finally, here are our statistics:\n\n";
	map<string, int, less<string> , allocator< pair<const string, int> > >::iterator siter;
	for ( siter = stats.begin(); siter != stats.end(); ++siter )
		cout << (*siter).first << " "
			<< "was transformed "
			<< (*siter).second
			<< ((*siter).second == 1
				 ? " time\n" : " times\n" );
}
