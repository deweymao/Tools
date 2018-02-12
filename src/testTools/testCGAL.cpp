#include "stdafx.h"
#include "testCGAL.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/algorithm.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Alpha_shape_2.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::FT FT;
typedef K::Point_2  Point;
typedef K::Segment_2  Segment;
typedef CGAL::Alpha_shape_vertex_base_2<K> Vb;
typedef CGAL::Alpha_shape_face_base_2<K>  Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K, Tds> Triangulation_2;
typedef CGAL::Alpha_shape_2<Triangulation_2>  Alpha_shape_2;
typedef Alpha_shape_2::Alpha_shape_edges_iterator Alpha_shape_edges_iterator;

template <class OutputIterator>
void alpha_edges(const Alpha_shape_2&  A, OutputIterator out) {
	for (Alpha_shape_edges_iterator it = A.alpha_shape_edges_begin();
		it != A.alpha_shape_edges_end();
		++it) {
		*out++ = A.segment(*it);
	}
}

bool TEST_CGAL::testCGALByAlphaShapes2D() {
	double alpha = 5.0;
	std::vector<Point> pts;
	
	pts.emplace_back(Point(5, 5));
	pts.emplace_back(Point(-5, 5));
	pts.emplace_back(Point(-5, -5));
	pts.emplace_back(Point(5,-5));
	pts.emplace_back(Point(3, 1));
	pts.emplace_back(Point(1, 4));
	pts.emplace_back(Point(-2, 2));
	pts.emplace_back(Point(1, -1));

	Alpha_shape_2 A(pts.begin(), pts.end(), FT(alpha), Alpha_shape_2::GENERAL);
	std::vector<Segment> segments;
	alpha_edges(A, std::back_inserter(segments));

	for (auto& itr : segments) {
		std::cout << "(" << itr.start().x() << "," << itr.start().y() << "), (" << itr.end().x() << ", " << itr.end().y() << ")" << std::endl;
	}

	return true;
}
