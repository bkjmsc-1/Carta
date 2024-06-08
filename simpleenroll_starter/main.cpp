/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 */

#include "utils.cpp"
#include <exception>
#include <iostream>
#include <string.h>
#include <system_error>
#include <vector>
#include <set>


void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);
void print_vector(std::vector<Course> vector_of_courses);
void parse_csv(std::string filename, std::vector<Course> &vector_of_courses);
void write_courses_offered(std::vector<Course> &vector_of_courses);
void write_courses_not_offered(std::vector<Course> &vector_of_courses);

std::string COURSES_PATH = "courses.csv";

bool structTest() {
  Course c = {"Standard C++ Programming", "1", "2023-2024 Winter"};
  return true;
}

int main() {
  std::vector<Course> vector_of_courses;

  std::cout << "Running tests..." << '\n';
  std::cout << "1. Testing struct..." << '\n';
  if (!structTest()) {
    std::cerr << " -- structTest Failed ";
    return -1;
  } else {
    std::cout << " --  structTest Passed! " << '\n';
  }
  
  parse_csv("courses.csv", vector_of_courses);

  // for(Course item : courseList){
  //   std::cout << item << std::endl;
  // }

  // print_vector(vector_of_courses);

    write_courses_offered(courseList);

    write_courses_not_offered(courseList);

  // write_courses_not_offered(vector_of_courses);

  // create a subprccess to run: pip install -r requirements.txt
  FILE *req_pipe = popen("pip install -r utils/requirements.txt", "r");
  if (!req_pipe)
    return -1;

  if (!req_pipe)
    return -1;

  char buffer[128];
  while (!feof(req_pipe)) {
    if (fgets(buffer, 128, req_pipe) != NULL)
      std::cout << buffer;
  }
  pclose(req_pipe);

  // clear buffer
  memset(buffer, 0, sizeof(buffer));

  FILE *pipe = popen("python utils/autograder.py", "r");
  if (!pipe)
    return -1;

  while (!feof(pipe)) {
    if (fgets(buffer, 128, pipe) != NULL)
      std::cout << buffer;
  }
  pclose(pipe);

  return 0;
}
