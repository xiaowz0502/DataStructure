// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "Image.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(Image_init_print){
    Image *img = new Image;
    string input = "P3 1 2\t255 255 0 0\n0\n255 0 \n";
    std::istringstream ss_input(input);
    Image_init(img, ss_input);

    // Should be well behaved when you print it though!
    string output_correct = "P3\n1 2\n255\n255 0 0 \n0 255 0 \n";
    std::ostringstream ss_output;
    Image_print(img, ss_output);
    string actual = ss_output.str();
    std::cout << actual << std::endl;
    ASSERT_EQUAL(actual, output_correct);
    delete img;
}
TEST(test_return) {
    Image *img = new Image;
    Image_init(img, 5, 6);
    ASSERT_EQUAL(Image_width(img), 5);
    ASSERT_EQUAL(Image_height(img), 6);
  delete img;
}

TEST(test_fill_get_set){
    Pixel red = {23, 4, 19};
    Pixel green = {0, 255, 0};
    Pixel Blue = {134, 18, 9};
    Pixel Gray = {3, 54, 119};
    Image *img = new Image;
    Image_init(img, 2, 2);

    ASSERT_EQUAL(Image_width(img), 2);
    ASSERT_EQUAL(Image_height(img), 2);

    Image_fill(img, red);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), red));
    Image_fill(img, Blue);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), Blue));
    Image_fill(img, Gray );
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), Gray));

    Image_set_pixel(img, 0, 0, green);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), green));
    
    Image_set_pixel(img, 1, 0, green);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), green));

    delete img;
}


// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
