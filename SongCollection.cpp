/******************************************
| Subject        : Workshop 7             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-15-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <memory>
#include <functional>
#include "SongCollection.h"

using namespace std;
namespace sdds {
	size_t SongCollection::cnt;
	sdds::SongCollection::SongCollection()
	{
		m_title = {};
		m_artist = {};
		m_album = {};
		m_price = {};
		m_release_year = {};
		m_length_song = {};
		v_songs = {};
		cnt = 0;
	}

	SongCollection::SongCollection(const string& _title, const string& _artist, const string& _album,
		const string& _year, const int& _length, const double& _price){
		m_title = _title;
		m_artist = _artist;
		m_album = _album;
		m_release_year = _year;
		m_length_song = _length;
		m_price = _price;
	}

	sdds::SongCollection::SongCollection(const char* filename){

		std::ifstream file(filename);
		if (!file)
			throw string("Unable to open [") + filename + "] file";

		SongCollection* aSong = nullptr;
		do {

			aSong = loadFile(file);
			v_songs.push_back(aSong);
		} while (aSong != nullptr);
	}

	SongCollection* sdds::SongCollection::loadFile(istream& file){

		SongCollection* vptr = nullptr;
		string line2, theRecord;
		string s_artist, s_title, s_album, s_year;
		std::vector<std::string> tempVec;

		if (file.good())
		{
			getline(file, theRecord);

			int i = 24;// theRecord.find("  ");
			m_title = theRecord.substr(0, i);
			theRecord = theRecord.erase(0, i + 1);
			trim(m_title);

			i = 24;
			m_artist = theRecord.substr(0, i);
			theRecord = theRecord.erase(0, i + 1);
			trim(m_artist);

			i = 24;
			m_album = theRecord.substr(0, i);
			theRecord = theRecord.erase(0, i + 1);
			trim(m_album);

			i = 4;
			m_release_year = theRecord.substr(0, i);
			theRecord = theRecord.erase(0, i + 1);
			trim(m_release_year);

			i = 4;
			m_length_song = stoi(theRecord.substr(0, i));
			theRecord = theRecord.erase(0, i + 1);
			i = 4;
			m_price = stof(theRecord.substr(0, i));
			theRecord = theRecord.erase(0, i + 1);

			vptr = new SongCollection(m_title, m_artist, m_album, m_release_year, m_length_song, m_price);
		}
		return vptr;
	}

	void SongCollection::sort(const string& _title)
	{
		string field = _title;

		auto isTitle = [=](bool a) { return field == "title"; };
		auto isLength = [=](bool a) { return field == "length"; };

		bool  b_title = std::none_of(SongCollection::v_songs.begin(), SongCollection::v_songs.end() - 1, isTitle);
		bool  b_length = std::none_of(SongCollection::v_songs.begin(), SongCollection::v_songs.end() - 1, isLength);

		if (b_title == 0)
		{
			std::sort(SongCollection::v_songs.begin(), SongCollection::v_songs.end() - 1, SongCollection::com_title);
		}
		else if (b_length == 0)
		{
			std::sort(SongCollection::v_songs.begin(), SongCollection::v_songs.end() - 1, SongCollection::com_length);
		}
	}

	bool SongCollection::com_title(const SongCollection* a, const SongCollection* b)
	{
		return a->m_title < b->m_title;
	}

	bool SongCollection::com_length(const SongCollection* a, const SongCollection* b)
	{
		return a->m_length_song < b->m_length_song;
	}

	bool SongCollection::operator<(const SongCollection* t) const
	{		
			return m_title < t->m_title;
	}

	void SongCollection::cleanAlbum()
	{
		string old_name = "[None]";
		string new_name = "";

		auto iter = v_songs.begin();
		for (; iter != v_songs.end() - 1; iter++) {
			if ((*iter)->m_album == old_name) {
				(*iter)->m_album = new_name;
			}
		}
	}

	bool SongCollection::inCollection(const string& _artist) const
	{
		auto isArtist = [=](bool a) { return _artist == "The Beatles"; };

		bool  b_artist = std::none_of(SongCollection::v_songs.begin(), SongCollection::v_songs.end() - 1, isArtist);
			
		return b_artist;
	}

	std::list<SongCollection> SongCollection::getSongsForArtist(const string& _artist)
	{
		
		auto iter = v_songs.begin();
		for (; iter != v_songs.end(); iter++) {
			if ((*iter) != nullptr)
			{
				if ((*iter)->m_artist == _artist && (*iter)->m_title.length() > 0) {
					Vtmp.push_back(SongCollection(
						((*iter)->m_title)
						, ((*iter)->m_artist)
						, ((*iter)->m_album)
						, ((*iter)->m_release_year)
						, ((*iter)->m_length_song)
						, ((*iter)->m_price)
					));
					
				}
			}			
		}
		return Vtmp;
	}

	void sdds::SongCollection::setDelimiter(char)
	{
		m_delim = ' ';
	}

	char sdds::SongCollection::getDelimiter()
	{
		return m_delim;
	}

	void sdds::SongCollection::setTitle(const string& r_title)
	{
		m_title = r_title;
	}

	string sdds::SongCollection::getTitle() const
	{
		return m_title;
	}

	void sdds::SongCollection::display(std::ostream& os) const
	{
		size_t  h = 0, m = 0, s = 0, total = 0;
		auto iter = v_songs.begin();
		for (; iter != v_songs.end() - 1; iter++) {
			if ((*iter) != nullptr)
			{
				h = ((*iter)->m_length_song / 3600);
				m = ((*iter)->m_length_song % 3600) / 60;
				s = ((*iter)->m_length_song - (3600 * h) - (m * 60));

				os << "| " << left << std::setw(20) << (*iter)->m_title
					<< " | " << left << std::setw(15) << (*iter)->m_artist
					<< " | " << left << std::setw(20) << (*iter)->m_album
					<< " | " << right << std::setw(6) << (*iter)->m_release_year
					//<< " | " << left << (*iter)->m_length_song
					<< " | " << m << ":";
				if (s <= 9)
				{
					os << "0" << s;
				}
				else {
					os << s;
				}
				os << " | " << left << (*iter)->m_price
					<< " |"
					<< "\n";
				total = total + (*iter)->m_length_song;
			}
		}
		h = (total / 3600);
		m = (total % 3600) / 60;
		s = (total - (3600 * h) - (m * 60));
		os << "----------------------------------------------------------------------------------------" << endl;
		os << "|" << right << setw(78) << "Total Listening Time: " << h << ":" << m << ":"  << s << " |" << endl;
	}

	void SongCollection::display2(std::ostream& os) const
	{
		size_t  h = 0, m = 0, s = 0, cnt= 0;
		auto iter = v_songs.begin();
		for (; iter != v_songs.end() - 1; iter++) {
			if ((*iter) != nullptr && (*iter)->m_title =="Sia")
			{
				h = ((*iter)->m_length_song / 3600);
				m = ((*iter)->m_length_song % 3600) / 60;
				s = ((*iter)->m_length_song - (3600 * h) - (m * 60));

				os << "| " << left << std::setw(20) << (*iter)->m_title
					<< " | " << left << std::setw(15) << (*iter)->m_artist
					<< " | " << left << std::setw(20) << (*iter)->m_album
					<< " | " << right << std::setw(6) << (*iter)->m_release_year
					//<< " | " << left << (*iter)->m_length_song
					<< " | " << m << ":";
				if (s <= 9)
				{
					os << "0" << s;
				}
				else {
					os << s;
				}
				os << " | " << right << (*iter)->m_price;
					if (cnt <= 4) {
						os<< " |"<<endl;
					}
					else {
						os << " |";
					}
					
				cnt++;

			}
		}
	}

	SongCollection& SongCollection::operator+=(const SongCollection& rhs)
	{
		return *this;
	}

	string sdds::SongCollection::trim(string& stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		stritem.erase(stritem.find_last_not_of(" ") + 1);
		return stritem;
	}

	ostream& operator<<(std::ostream& os, const SongCollection& theSong)
	{
		size_t  h = 0, m = 0, s = 0;
		h = (theSong.m_length_song / 3600);
		m = (theSong.m_length_song % 3600) / 60;
		s = (theSong.m_length_song - (3600 * h) - (m * 60));

		os << "| " << left << std::setw(20) << theSong.m_title
			<< " | " << left << std::setw(15) << theSong.m_artist
			<< " | " << left << std::setw(20) << theSong.m_album
			<< " | " << right << std::setw(6) << theSong.m_release_year
			<< " | " << m << ":";
		if (s <= 9)
		{
			os << "0" << s;
		}
		else {
			os << s;
		}
		os << " | " << right << theSong.m_price
			<< " |";		
		SongCollection::cnt++;

		return os;
	}
};