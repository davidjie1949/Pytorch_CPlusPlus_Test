// #include <iostream>
// // #include "network.h"
// #include <memory>
// #include <stdio.h>
// // OPENCV
// #include <opencv2/core.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/opencv.hpp>
// #include <opencv2/videoio.hpp>

// // TORCH
// #include <torch/script.h>
// #include <torch/torch.h>

// #define DEFAULT_HEIGHT 720
// #define DEFAULT_WIDTH 1280
// #define IMG_SIZE 512

// // PROTOTYPES
// cv::Mat frame_prediction(cv::Mat frame, torch::jit::Module model);
// torch::jit::Module load_model(std::string model_name);

// // using namespace torch;
// // int main() {
// //     Net network(50,10);
// //     std::cout << network << std::endl;
// //     Tensor x, output;
// //     x = torch::randn({2,50});
// //     output = network->forward(x);
// //     std::cout << output << std::endl;
// //     return 0;
// // }

// int main() {
//   // set torch module
//   torch::jit::script::Module module;
//   // OPENCV
//   cv::VideoCapture cap;
//   cv::Mat frame;
//   cap.open("/home/jay/gitlab_workspace/Pytorch_CPlusPlus_Test/videos/driving.mp4");
//   if(!cap.isOpened()) {
//     std::cerr << "\nCannot open video" << std::endl;
//   }

//   std::cout << "Press spacebar to terminate" << std::endl;
//   try {
//     module = load_model("lanes_segnet.pt");
//     std::cout << "passed load_model" << std::endl;
//   } catch (const c10::Error &e) {
//     std::cerr <<"ERROR Model is not load" << std::endl;
//   }
//   return 0;
// }

// torch::jit::Module load_model(std::string model_name) {
// 	std::string directory = "/home/jay/gitlab_workspace/Pytorch_CPlusPlus_Test/models/lanes_segnet.pt";
// 	std::cout << "1" << std::endl;
// 	torch::jit::Module module = torch::jit::load(directory);
// 	std::cout << &module << std::endl;
// 	module.to(torch::kCUDA);
// 	std::cout << "3" << std::endl;
// 	module.eval();
// 	std::cout << "4" << std::endl;
// 	std::cout << "MODEL LOADED";
// 	return module;
// }

// #include <opencv2/core.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>

// #include <iostream>

// using namespace cv;
// int main() {
//   std::string image_path = samples::findFile("starry_night.jpg");
//   Mat img = imread(image_path, IMREAD_COLOR);

//   if(img.empty()) {
//     std::cout << "Could not read the image: " << image_path << std::endl;
//     return 1;
//   }

//   imshow("Display window", img);
//   int k = waitKey(0); // Wait for a keystroke in the window
//   if(k == 's') {
//       imwrite("starry_night.png", img);
//   }
//   return 0;
// }

#include "opencv2/opencv.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main(){
 
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  VideoCapture cap("sample.mp4"); 
    
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
   
  while(1){
 
    Mat frame;
    // Capture frame-by-frame
    cap >> frame;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
 
    // Display the resulting frame
    imshow( "Frame", frame );
 
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;
  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
   
  return 0;
}