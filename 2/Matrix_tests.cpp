// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(Matrix_init) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 3, 5);
    ASSERT_EQUAL(Matrix_width(mat), 3);
    ASSERT_EQUAL(Matrix_height(mat), 5);
     delete mat; // delete the Matrix
    
    Matrix *mat1 = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat1, 6, 13);
    ASSERT_EQUAL(Matrix_width(mat1), 6);
    ASSERT_EQUAL(Matrix_height(mat1), 13);
      delete mat1; // delete the Matrix
    
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat2, 1, 1);
    ASSERT_EQUAL(Matrix_width(mat2), 1);
    ASSERT_EQUAL(Matrix_height(mat2), 1);
      delete mat2; // delete the Matrix
    
    Matrix *mat3 = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat3, 500, 500);
    ASSERT_EQUAL(Matrix_width(mat3), 500);
    ASSERT_EQUAL(Matrix_height(mat3), 500);
      delete mat3; // delete the Matrix
    
    
}

TEST(test_matrix_print) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    ostringstream expected;
    expected << "3 4\n"
           << "42 5 6 \n"
           << "7 8 9 \n"
           << "10 11 12 \n"
           << "14 17 17 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    delete mat;
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 2, 2);
    *Matrix_at(mat2, 0, 0) = 42;
    *Matrix_at(mat2, 0, 1) = 5;
    *Matrix_at(mat2, 1, 0) = 7;
    *Matrix_at(mat2, 1, 1) = 8;
        ostringstream expected2;
        expected2 << "2 2\n"
                  << "42 5 \n"
                  << "7 8 \n";
        ostringstream actual2;
        Matrix_print(mat2, actual2);
        ASSERT_EQUAL(expected2.str(), actual2.str());
        delete mat2;
    
    Matrix *mat3 = new Matrix;
    Matrix_init(mat3, 1, 1);
    *Matrix_at(mat3, 0, 0) = 1;
        ostringstream expected3;
        expected3 << "1 1\n"
                  << "1 \n";
        ostringstream actual3;
        Matrix_print(mat3, actual3);
        ASSERT_EQUAL(expected3.str(), actual3.str());
        delete mat3;
    
    Matrix *mat4 = new Matrix;
    Matrix_init(mat4, 1, 3);
    *Matrix_at(mat4, 0, 0) = 1;
    *Matrix_at(mat4, 1, 0) = 2;
    *Matrix_at(mat4, 2, 0) = 3;
        ostringstream expected4;
        expected4 << "1 3\n"
                  << "1 \n"
                  << "2 \n"
                  << "3 \n";
        ostringstream actual4;
        Matrix_print(mat4, actual4);
        ASSERT_EQUAL(expected4.str(), actual4.str());
        delete mat4;
    
    Matrix *mat5 = new Matrix;
    Matrix_init(mat5, 3, 1);
    *Matrix_at(mat5, 0, 0) = 1;
    *Matrix_at(mat5, 0, 1) = 2;
    *Matrix_at(mat5, 0, 2) = 3;
        ostringstream expected5;
        expected5 << "3 1\n"
                  << "1 2 3 \n";
        ostringstream actual5;
        Matrix_print(mat5, actual5);
        ASSERT_EQUAL(expected5.str(), actual5.str());
        delete mat5;
}

TEST(test_Matrix_width) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);
    int i = Matrix_width(mat);
    ASSERT_EQUAL(i, 3);
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 18, 4);
    int u = Matrix_width(mat1);
    ASSERT_EQUAL(u, 18);
    delete mat1;
}

TEST(test_Matrix_height) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);
    int i = Matrix_height(mat);
    ASSERT_EQUAL(i, 4);
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 18, 59);
    int k = Matrix_height(mat1);
    ASSERT_EQUAL(k, 59);
    delete mat1;
}

TEST(test_Matrix_row){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    int rowNum = Matrix_row(mat, Matrix_at(mat, 1, 0));
    ASSERT_EQUAL(rowNum, 1);
    
    int rowNum1 = Matrix_row(mat, Matrix_at(mat, 3, 2));
    ASSERT_EQUAL(rowNum1, 3);
    
    int rowNum2 = Matrix_row(mat, Matrix_at(mat, 2, 2));
    ASSERT_EQUAL(rowNum2, 2);
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 500, 500);
    Matrix_fill(mat1, 66);
    int rowNum3 = Matrix_row(mat1, Matrix_at(mat1, 0, 0));
    ASSERT_EQUAL(rowNum3, 0);
    int rowNum4 = Matrix_row(mat1, Matrix_at(mat1, 0, 499));
    ASSERT_EQUAL(rowNum4, 0);
    int rowNum5 = Matrix_row(mat1, Matrix_at(mat1, 1, 0));
    ASSERT_EQUAL(rowNum5, 1);
    int rowNum6 = Matrix_row(mat1, Matrix_at(mat1, 499, 0));
    ASSERT_EQUAL(rowNum6, 499);
    int rowNum7 = Matrix_row(mat1, Matrix_at(mat1, 499, 499));
    ASSERT_EQUAL(rowNum7, 499);
    int rowNum8 = Matrix_row(mat1, Matrix_at(mat1, 200, 450));
    ASSERT_EQUAL(rowNum8, 200);
    delete mat1;
    
}

TEST(test_Matrix_column){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    int rowNum = Matrix_column(mat, Matrix_at(mat, 1, 0));
    ASSERT_EQUAL(rowNum, 0);
    
    int rowNum1 = Matrix_column(mat, Matrix_at(mat, 2, 1));
    ASSERT_EQUAL(rowNum1, 1);
    
    int rowNum2 = Matrix_column(mat, Matrix_at(mat, 3, 2));
    ASSERT_EQUAL(rowNum2, 2);
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 500, 500);
    Matrix_fill(mat1, 66);
    int rowNum3 = Matrix_column(mat1, Matrix_at(mat1, 0, 0));
    ASSERT_EQUAL(rowNum3, 0);
    int rowNum4 = Matrix_column(mat1, Matrix_at(mat1, 0, 499));
    ASSERT_EQUAL(rowNum4, 499);
    int rowNum5 = Matrix_column(mat1, Matrix_at(mat1, 1, 0));
    ASSERT_EQUAL(rowNum5, 0);
    int rowNum6 = Matrix_column(mat1, Matrix_at(mat1, 499, 0));
    ASSERT_EQUAL(rowNum6, 0);
    int rowNum7 = Matrix_column(mat1, Matrix_at(mat1, 499, 499));
    ASSERT_EQUAL(rowNum7, 499);
    int rowNum8 = Matrix_column(mat1, Matrix_at(mat1, 450, 200));
    ASSERT_EQUAL(rowNum8, 200);
    delete mat1;
}

TEST(test_Matrix_at){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    int *ptr1 = Matrix_at(mat, 1, 0);
    ASSERT_EQUAL(*ptr1, 7);
    
    int *ptr3 = Matrix_at(mat, 2, 1);
    ASSERT_EQUAL(*ptr3, 11);
    
    int *ptr5 = Matrix_at(mat, 3, 2);
    ASSERT_EQUAL(*ptr5, 17);
    
    int *ptr6 = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(*ptr6, 42);
    
    int *ptr7 = Matrix_at(mat, 3, 2);
    ASSERT_EQUAL(*ptr7, 17);
    
    int *ptr8 = Matrix_at(mat, 0, 2);
    ASSERT_EQUAL(*ptr8, 6);
    
    int *ptr9 = Matrix_at(mat, 1, 2);
    ASSERT_EQUAL(*ptr9, 9);
    
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 2, 2);
    *Matrix_at(mat1, 0, 0) = 42;
    *Matrix_at(mat1, 0, 1) = 5;
    *Matrix_at(mat1, 1, 0) = 6;
    *Matrix_at(mat1, 1, 1) = 7;
    int *ptr10 = Matrix_at(mat1, 0, 0);
    ASSERT_EQUAL(*ptr10, 42);
    
    int *ptr11 = Matrix_at(mat1, 0, 1);
    ASSERT_EQUAL(*ptr11, 5);
    
    int *ptr12 = Matrix_at(mat1, 1, 0);
    ASSERT_EQUAL(*ptr12, 6);
    
    int *ptr13 = Matrix_at(mat1, 1, 1);
    ASSERT_EQUAL(*ptr13, 7);
    
    delete mat1;
}

TEST(test_fill_basic1) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 4;
  const int height = 4;
  const int value = 0;
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }
  delete mat; // delete the Matrix
    
    Matrix *mat1 = new Matrix;
    const int width1 = 5;
    const int height1 = 3;
    const int value1 = 2;
    Matrix_init(mat1, 5, 3);
    Matrix_fill(mat1, value1);
    for(int r = 0; r < height1; ++r){
      for(int c = 0; c < width1; ++c){
        ASSERT_EQUAL(*Matrix_at(mat1, r, c), value1);
      }
    }
    delete mat1;
    
    Matrix *mat2 = new Matrix;
    const int width2 = 1;
    const int height2 = 1;
    const int value2 = 2;
    Matrix_init(mat2, 1, 1);
    Matrix_fill(mat2, value2);
    for(int r = 0; r < height2; ++r){
      for(int c = 0; c < width2; ++c){
        ASSERT_EQUAL(*Matrix_at(mat2, r, c), value2);
      }
    }
    delete mat2;
    
    Matrix *mat3 = new Matrix;
    const int width3 = 500;
    const int height3 = 500;
    const int value3 = 2;
    Matrix_init(mat3, 500, 500);
    Matrix_fill(mat3, value3);
    for(int r = 0; r < height3; ++r){
      for(int c = 0; c < width3; ++c){
        ASSERT_EQUAL(*Matrix_at(mat3, r, c), value3);
      }
    }
    delete mat3;
}

TEST(test_fill_basic2) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 1;
  const int height = 1;
  const int value = 0;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }
  delete mat; // delete the Matrix
}

TEST(test_Matrix_fill_border){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    Matrix_fill_border(mat, 0);
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 3, 4);
    *Matrix_at(mat1, 0, 0) = 0;
    *Matrix_at(mat1, 0, 1) = 0;
    *Matrix_at(mat1, 0, 2) = 0;
    *Matrix_at(mat1, 1, 0) = 0;
    *Matrix_at(mat1, 1, 1) = 8;
    *Matrix_at(mat1, 1, 2) = 0;
    *Matrix_at(mat1, 2, 0) = 0;
    *Matrix_at(mat1, 2, 1) = 11;
    *Matrix_at(mat1, 2, 2) = 0;
    *Matrix_at(mat1, 3, 0) = 0;
    *Matrix_at(mat1, 3, 1) = 0;
    *Matrix_at(mat1, 3, 2) = 0;
    ASSERT_TRUE(Matrix_equal(mat, mat1));
    delete mat;
    delete mat1;
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 1, 1);
    *Matrix_at(mat2, 0, 0) = 42;
    Matrix_fill_border(mat2, 5);
    *Matrix_at(mat2, 0, 0) = 5;
    delete mat2;
    
    Matrix *mat3 = new Matrix;
    Matrix_init(mat3, 2, 2);
    *Matrix_at(mat3, 0, 0) = 5;
    *Matrix_at(mat3, 0, 1) = 4;
    *Matrix_at(mat3, 1, 0) = 37;
    *Matrix_at(mat3, 1, 1) = 21;
    Matrix_fill_border(mat3, 12);
    Matrix *mat4 = new Matrix;
    Matrix_init(mat4, 2, 2);
    Matrix_fill_border(mat4, 12);
    ASSERT_TRUE(Matrix_equal(mat3, mat4));
    delete mat3;
    delete mat4;
}

TEST(Matrix_column_of_min_value_in_row){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    
    int i = Matrix_column_of_min_value_in_row(mat, 2, 0, 2);
    ASSERT_EQUAL(i, 0);
    int m = Matrix_column_of_min_value_in_row(mat, 0, 0, 1);
    ASSERT_EQUAL(m, 0);
    int n = Matrix_column_of_min_value_in_row(mat, 0, 2, 3);
    ASSERT_EQUAL(n, 2);
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 1, 1);
    *Matrix_at(mat1, 0, 0) = 42;
    int j = Matrix_column_of_min_value_in_row(mat1, 0, 0, 1);
    ASSERT_EQUAL(j, 0);
    delete mat1;
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 3, 1);
    *Matrix_at(mat2, 0, 0) = 42;
    *Matrix_at(mat2, 0, 1) = 42;
    *Matrix_at(mat2, 0, 2) = 43;
    int k = Matrix_column_of_min_value_in_row(mat2, 0, 0, 2);
    ASSERT_EQUAL(k, 0);
    delete mat2;
    
}

TEST(Matrix_min_value_in_row){
    
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 10;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    int i = Matrix_min_value_in_row(mat, 2, 0, 2);
    ASSERT_EQUAL(i, 10);
    int m = Matrix_min_value_in_row(mat, 0, 0, 1);
    ASSERT_EQUAL(m, 42);
    int n = Matrix_min_value_in_row(mat, 0, 2, 3);
    ASSERT_EQUAL(n, 6);
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 1, 1);
    *Matrix_at(mat1, 0, 0) = 42;
    int j = Matrix_min_value_in_row(mat1, 0, 0, 1);
    ASSERT_EQUAL(j, 42);
    delete mat1;
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 3, 1);
    *Matrix_at(mat2, 0, 0) = 42;
    *Matrix_at(mat2, 0, 1) = 42;
    *Matrix_at(mat2, 0, 2) = 43;
    int k = Matrix_min_value_in_row(mat2, 0, 0, 2);
    ASSERT_EQUAL(k, 42);
    delete mat2;
    
    delete mat;
    
    
}

TEST(test_Matrix_max){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);

    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 5;
    *Matrix_at(mat, 0, 2) = 6;
    *Matrix_at(mat, 1, 0) = 7;
    *Matrix_at(mat, 1, 1) = 8;
    *Matrix_at(mat, 1, 2) = 9;
    *Matrix_at(mat, 2, 0) = 570;
    *Matrix_at(mat, 2, 1) = 11;
    *Matrix_at(mat, 2, 2) = 12;
    *Matrix_at(mat, 3, 0) = 14;
    *Matrix_at(mat, 3, 1) = 17;
    *Matrix_at(mat, 3, 2) = 17;
    int i = Matrix_max(mat);
    ASSERT_EQUAL(i, 570);
    delete mat;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 500, 500);
    Matrix_fill(mat1, 38);
    int n = Matrix_max(mat1);
    ASSERT_EQUAL(n, 38);
    delete mat1;
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 1, 1);
    Matrix_fill(mat2, 52);
    int j = Matrix_max(mat2);
    ASSERT_EQUAL(j, 52);
    delete mat2;
}



// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
