#include <iostream>
#include <sstream>
#include <boost/python.hpp>
#include <seqan/align.h>

using namespace seqan;
using namespace std;

typedef String<char> TSequence;
typedef Align<TSequence,ArrayGaps> TAlign;

struct AlignmentWrapper {
	TAlign* align;
	AlignmentWrapper() : align(new TAlign()) {}
	AlignmentWrapper(TAlign* align) : align(align) {}
	
	string toString() {
		ostringstream oss;
		oss << *align;
		return oss.str();
	}
};

boost::python::tuple align(string a, string b) {
	typedef Row<TAlign>::Type TRow;
	typedef Iterator<TRow>::Type TIterator;
	TSequence seq1 = a;
	TSequence seq2 = b;
	TAlign* align = new TAlign();
	resize(rows(*align), 2); 
	assignSource(row(*align,0),seq1);
	assignSource(row(*align,1),seq2);
	int score = globalAlignment(*align,Score<int>(1,-1,-1,-1), Hirschberg());
	AlignmentWrapper aw(align);
	return boost::python::make_tuple(score, aw);
}

BOOST_PYTHON_MODULE(pyseqan)
{
	using namespace boost::python;
	def("align", align);
	
	class_<AlignmentWrapper>("Alignment")
		.def("__str__", &AlignmentWrapper::toString)
	;
}
