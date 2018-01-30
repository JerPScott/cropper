cropper: cropper.cpp QuadImage.cpp QuadImage.hpp
	g++ -o cropper.run \
		`Magick++-config --cppflags | sed 's/-fopenmp//g'` \
		`Magick++-config --cxxflags | sed 's/-fopenmp//g'` \
		`Magick++-config --ldflags | sed 's/-fopenmp//g'` \
		`Magick++-config --libs | sed 's/-fopenmp//g'` \
		QuadImage.cpp cropper.cpp
