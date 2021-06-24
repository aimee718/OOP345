/******************************************
| Subject        : Workshop 7             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-15-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef SONGCOLLECTION_HEADER
#define SONGCOLLECTION_HEADER
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>
#include <array>

using namespace std;
namespace sdds {
	class SongCollection {
		string m_artist;
		string m_title;
		string m_album;

		string m_release_year;
		size_t m_length_song;

		size_t m_widthField = 1;
		char m_delim;
		vector<SongCollection*> v_songs;
		list<SongCollection> Vtmp;
		static size_t cnt;

	public:
		double m_price;

		SongCollection();
		SongCollection(const string&, const string&, const string&, const string&, const int&, const double&);
		SongCollection(const char* filename);

		SongCollection* loadFile(istream& file);
		void sort(const string&);
		static bool com_title(const SongCollection* a, const SongCollection* b);
		static bool com_length(const SongCollection* a, const SongCollection* b);
		bool operator<(const SongCollection*) const;
		void cleanAlbum();
		bool inCollection(const string&) const;
		std::list<SongCollection> getSongsForArtist(const string&);

		void setDelimiter(char);
		char getDelimiter();

		void setTitle(const string&);
		string getTitle() const;

		void display(std::ostream& os) const;
		void display2(std::ostream& os)const;

		friend ostream& operator<<(std::ostream&, const SongCollection&);
		SongCollection& operator+=(const SongCollection& rhs);
		string trim(string&);
	};
}
#endif

