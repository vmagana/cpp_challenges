// nice_strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	char strword[]="";
	string word="";
	
	size_t is_nice_count=0;
	size_t all_count=0;
	ifstream filein("nice.txt");
	if(filein.is_open()) {
		while(getline(filein,word)) {
			all_count++;
			//regex not_regex (".*ab.*|.*cd.*|.*pq.*|.*xy.*");
			//regex vowel_regex (".*[aeiou].*[aeiou].*.*[aeiou].*");
			//regex onepair_regex(".*aa.*|.*bb.*|.*cc.*|.*dd.*|.*ee.*|.*ff.*|.*gg.*|.*hh.*|.*ii.*|.*jj.*|.*kk.*|.*ll.*|.*mm.*|.*nn.*|.*oo.*|.*pp.*|.*qq.*|.*rr.*|.*ss.*|.*tt.*|.*uu.*|.*vv.*|.*ww.*|.*xx.*|.*yy.*|.*zz.*");
			//regex onepair_regex(".*([a-z])\\1.*");

			regex repeatwithwordbetween_regex(".*([a-z])[a-z]\\1.*");
			regex repeattwoletters_regex(".*([a-z][a-z]).*\\1.*");
			smatch base_match;
			if(regex_match (word,base_match,repeattwoletters_regex) && regex_match(word,base_match,repeatwithwordbetween_regex) ) {
			//cout<<base_match.str()<<endl;
			
			//if ( regex_match(word,pair_regex ) ) {
			//if ( !regex_search(word,not_regex) && regex_search(word,vowel_regex) && regex_search(word,pair_regex) ) {
			//if ( !regex_match(word,not_regex) && regex_match(word,vowel_regex) && regex_match(word,pair_regex) ) {
			//if(regex_match(str,repeat_regex)) {
				
				cout<<base_match.str()<<endl;
				is_nice_count++;
			}

			//if ( regex_match ( s.begin(), s.end(), regex ) )
				//std::cout << "range matched\n";
			
		}
	}
	cout<<"Count"<<is_nice_count<<endl;
	cout<<"ALL"<<all_count<<endl;
	return 0;
}

//42 Total
//458 with pairs of characters, leaves 542
//74 with at least 3 vowels, leaves 926
//88 with character that should not match, leaves 912