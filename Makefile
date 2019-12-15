CXX = g++
opencvlibs = $(shell pkg-config --cflags --libs opencv4)
CXXFLAGS = -Wall -Wextra -std=c++11 -lpthread $(opencvlibs)


pipeline: main.o multiply.o add.o pipeline.o stage.o open_file.o save_file.o blur_img.o rotate_img.o
	$(CXX) -o pipeline main.o pipeline.o multiply.o add.o stage.o open_file.o save_file.o blur_img.o rotate_img.o $(CXXFLAGS)

multiply.o: multiply.cpp
	$(CXX) -c multiply.cpp $(CXXFLAGS)

pipeline.o: pipeline.cpp
	$(CXX) -c pipeline.cpp $(CXXFLAGS)

open_file.o: open_file.cpp
	$(CXX) $(CXXFLAGS) open_file.cpp -c

save_file.o: save_file.cpp
	$(CXX) $(CXXFLAGS) save_file.cpp -c

blur_img.o: blur_img.cpp
	$(CXX) $(CXXFLAGS) blur_img.cpp -c

rotate_img.o: rotate_img.cpp
	$(CXX) $(CXXFLAGS) rotate_img.cpp -c

add.o: add.cpp
	$(CXX) -c add.cpp $(CXXFLAGS)
	
main.o: main.cpp
	$(CXX) -c main.cpp $(CXXFLAGS)

stage.o: stage.cpp
	$(CXX) -c stage.cpp $(CXXFLAGS)

run: pipeline
	./pipeline

stats: 
	cloc --exclude-lang=XML --git .

oldschool:
	clang++-8 -pthread -o OldSchool/main OldSchool/basic_pipeline.cpp OldSchool/main.cpp OldSchool/stage.cpp

clean:
	rm *.o pipeline image_blur ./output/*

imgblr:
	# g++ -I/usr/local/Cellar/opencv/4.1.2/include/opencv4/opencv -I/usr/local/Cellar/opencv/4.1.2/include/opencv4 -L/usr/local/Cellar/opencv/4.1.2/lib -lopencv_gapi -lopencv_stitching -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_highgui -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_quality -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_video -lopencv_videoio -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core -std=c++11  image_blur.cpp -o image_blur
	$(CXX) $(opencvlibs) -std=c++11  image_blur.cpp -o image_blur