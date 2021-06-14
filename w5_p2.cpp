/******************************************
| Subject        : Workshop 5             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-25-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include<vector>
#include "Book.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "Collection.h"

using namespace std;
using namespace sdds;

// The observer function 
//void bookAddedObserver(const Collection<Book>& theCollection, const Book& theBook)
//{
//	std::cout << "Book \"" << theBook.title() << "\" added!\n";
//}
//// The observer function
//void movieAddedObserver(const Collection<Movie>& theCollection, const Movie& theMovie)
//{
//	std::cout << "Movie \"" << theMovie.title()
//		<< "\" added to collection \"" << theCollection.name()
//		<< "\" (" << theCollection.size() << " items).\n";
//}
//int main(int argc, char** argv)
//{
//	std::cout << "Command Line:\n";
//	std::cout << "--------------------------\n";
//	for (int i = 0; i < argc; i++)
//		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
//	std::cout << "--------------------------\n\n";
//
//	Book** ppBooks = nullptr;
//	size_t cnt = 0;
//	{
//		std::ifstream file(argv[1]);
//		std::string strBook;
//		do
//		{
//			std::getline(file, strBook);
//
//			if (file)
//			{
//				if (strBook[0] != '#')
//					++cnt;
//			}
//		} while (file);
//
//		ppBooks = new sdds::Book * [cnt];
//		cnt = 0;
//
//		file.clear();
//		file.seekg(std::ios::beg);
//		do
//		{
//			std::getline(file, strBook,'\n');
//			if (file)
//			{
//				if (strBook[0] != '#')
//				{
//					ppBooks[cnt] = new sdds::Book(strBook);
//					++cnt;
//				}
//			}
//		} while (file);
//		file.close();
//
//		///////{
//
//			//std::cout << "==========================\n";
//		sdds::Collection<Book> library("Bestsellers");
//
//		library += *ppBooks[4];
//		library += *ppBooks[5];
//		library += *ppBooks[6];
//
//		//library.setObserver(bookAddedObserver);
//		void(*p_fnc_book)(const Collection<Book>&, const Book&);
//		p_fnc_book = (void(*)(const Collection<Book>&, const Book&))bookAddedObserver;
//		for (size_t i = 4; i < 7; i++) (*p_fnc_book)(library, *ppBooks[i]);
//
//		std::cout << "-----------------------------------------\n";
//		std::cout << "The library content\n";
//		std::cout << "-----------------------------------------\n";
//
//		library -= *ppBooks[4];
//		library -= *ppBooks[5];
//		library -= *ppBooks[6];
//
//		std::cout << library;
//
//		for (auto i = 0u; i < 7; ++i)	std::cout << *ppBooks[i];
//
//		std::cout << "-----------------------------------------\n\n";
//
//		double usdToCadRate = 1.3;
//		double gbpToCadRate = 1.5;
//
//		// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to 
//		//the rules
//
//		std::cout << "-----------------------------------------\n";
//		std::cout << "The library content (updated prices)\n";
//		std::cout << "-----------------------------------------\n";
//		Collection<Book> theColl(ppBooks, usdToCadRate, gbpToCadRate);
//		for (auto i = 0u; i < 7; ++i)	std::cout << *ppBooks[i];
//		std::cout << "-----------------------------------------\n\n";
//
//		////////}
//		/*auto letter = [](string s_country, size_t t_year)
//		{
//		};*/
//
//		////////}
//		/////////////////////////////////////////////////////////////////
//		Movie** ppMovies = nullptr;
//		size_t cnt2 = 0;
//
//		/////////{
//		std::ifstream file2(argv[2]);
//		std::string strMovie;
//		do
//		{
//			std::getline(file2, strMovie);
//
//			if (file2)
//			{
//				// Check if this is a commented line.
//				//   In the input file, commented lines start with '#'
//				if (strMovie[0] != '#')
//					++cnt2;
//			}
//		} while (file2);
//		//cout <<"moviecnt2.."<< cnt2 << endl;
//		ppMovies = new Movie * [cnt2];
//		cnt2 = 0;
//
//		file2.clear();
//		file2.seekg(std::ios::beg);
//		Movie movies[5];
//		do
//		{
//			std::getline(file2, strMovie);
//
//			// if the previous operation failed, the "file" object is
//			//   in error mode
//			if (file2)
//			{
//				// Check if this is a commented line.
//				//   In the input file, commented lines start with '#'
//				if (strMovie[0] != '#')
//				{
//					ppMovies[cnt2] = new sdds::Movie(strMovie);
//					movies[cnt2] = *ppMovies[cnt2];
//
//					++cnt2;
//				}
//
//			}
//		} while (file2);
//		file2.close();
//
//		///////{
//
//		Collection<Movie> theCollection("Action Movies");
//		// Process the file
//		//Movie movies[5];
//		// TODO: load 5 movies from the file "argv[2]".
//		//       - read one line at a time, and pass it to the Movie constructor
//		//       - store each movie read into the array "movies"
//		//       - lines that start with "#" are considered comments and should be ignored
//
//
//		std::cout << "-----------------------------------------\n";
//		std::cout << "Testing addition and callback function\n";
//		std::cout << "-----------------------------------------\n";
//		// Add a few movies to collection; no observer is set
//		((theCollection += movies[0]) += movies[1]) += movies[2];
//		//-------temp remove
//		//theCollection += movies[1];
//
//		//--------temperally remove--may by dont need ---for testing
//		//std::cout << theCollection;
//
//		// add more movies; now we get a callback from the collection
//		for (size_t i = 3u; i < 5u; i++) {
//			theCollection.setObserver(movieAddedObserver, theCollection, movies[i]);
//			theCollection += movies[3];
//			theCollection += movies[4];
//		}
//
//
//		//--------temperally remove
//		//theCollection += movies[3];
//
//
//		//------------direct by call function poinster
//		/*void(*p_fnc_movie)(const Collection<Movie>&, const Movie&);
//		p_fnc_movie = (void(*)(const Collection<Movie>&, const Movie&))movieAddedObserver;
//		for (size_t i = 3u; i < 5u; i++) {
//			(*p_fnc_movie)(theCollection, *ppMovies[i]);
//		}*/
//
//
//		std::cout << "-----------------------------------------\n\n";
//		std::cout << "-----------------------------------------\n";
//		std::cout << "Testing exceptions and operator[]\n";
//		std::cout << "-----------------------------------------\n";
//
//		// TODO: The following loop can generate generate an exception
//		//         write code to handle the exception
//		//       If an exception occurs print a message in the following format
//		//EXCEPTION: ERROR_MESSAGE<endl>
//		//         where ERROR_MESSAGE is extracted from the exception object.
//
//		for (auto i = 0u; i < 6u; i++)
//		{
//			try {
//				cout << theCollection[i];
//			}
//			catch (std::out_of_range& e) {
//				std::cout << e.what() << std::endl;
//			}
//			//cout << theCollection[i];
//		}
//
//		std::cout << "-----------------------------------------\n\n";
//
//
//		std::cout << "-----------------------------------------\n";
//		std::cout << "Testing the functor\n";
//		std::cout << "-----------------------------------------\n";
//		
//			for (auto i = 3u; i <= 4u; ++i)
//			{
//				// TODO: The following statement can generate generate an exception
//				//         write code to handle the exception
//				//       If an exception occurs print a message in the following format
//				//EXCEPTION: ERROR_MESSAGE<endl>
//				//         where ERROR_MESSAGE is extracted from the exception object.
//				try {
//					SpellChecker sp(argv[i], i);
//					
//				
//				for (auto j = 0u; j < 5u; ++j) ppMovies[j]->fixSpelling(sp);//theCollection[j].fixSpelling(sp);
//				for (auto j = 0u; j < 7u; ++j) ppBooks[j]->fixSpelling(sp);//library[j].fixSpelling(sp);
//				}
//				catch (const std::exception& error)
//				{
//
//					cout << "aaaEXCEPTION: Bad file name!" << endl;
//					cerr << error.what() << endl;
//					
//				}
//				if (i == 4) {
//					cout << "EXCEPTION: Bad file name!" << endl;
//				}
//				
//			}
//
//		std::cout << "--------------- Movies ------------------\n";
//		for (auto i = 0u; i < 5; ++i) std::cout << *ppMovies[i];//std::cout << theCollection;
//		std::cout << "--------------- Books -------------------\n";
//		for (auto i = 0u; i < 7; ++i) std::cout << *ppBooks[i];//std::cout << library;
//		std::cout << "-----------------------------------------\n\n";
//
//		std::cout << "-----------------------------------------\n";
//		std::cout << "Testing operator[] (the other overload)\n";
//		std::cout << "-----------------------------------------\n";
//
//		Movie* aMovie = theCollection["Terminator 2"];
//
//		if (aMovie == nullptr)
//			std::cout << "Movie Terminator 2 not in collection.\n";
//
//		aMovie = theCollection["Dark Phoenix"];
//		if (aMovie != nullptr)
//		{
//			//SpellChecker sp1(argv[3]);
//			//aMovie->fixSpelling(sp1);
//			//aMovie->fixSpelling(sp1);
//			//aMovie->fixSpelling(aMovie->description());
//			//cout << "aMovie.." << aMovie->title() << "/" << *argv[i] << endl;
//			//for (auto j = 0u; j < 5; ++j) SpellChecker(aMovie[i]->fixSpelling(sp1);
//			//SpellChecker::SpellChecker(aMovie);
//			std::cout << "In collection:\n" << /**aMovie*/*ppMovies[2];
//			std::cout << "-----------------------------------------\n\n";
//		}
//
//
//
//		///////}
//	}
//	return 0;
//}

//array<string, 5> a2;
//a2 = { "Hello", "Seneca", "Course","OOP","345" };
//string* ip2 = a2.data();
//for (size_t i = 0; i < a2.size(); i++) {
//	if (i % 2 == 0) {
//		*ip2++ += "YY";
//	}
//}
//cout << a2.front();

//int a[] = { 5,1,12,13 };
//vector<int> v(a, a + 4);
//v.insert(v.begin() + 1, 115);
//for (auto e : v) {
//	cout << e;
//}
int a[] = { 45,10,50,40 };
vector<int> v1(a, a + (sizeof a / sizeof(a[0])));
vector<int> v2((sizeof a / sizeof(a[0])));
v1.swap(v2);
while (!v2.empty()) {
	cout << v2.front();
	v2.pop_back();
}
cout << v1.size();
