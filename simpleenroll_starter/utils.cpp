/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <string>


// STUDENT TODO: add paths
std::string COURSES_OFFERED_CSV_PATH = "student_output/courses_offered.csv";

std::string COURSES_NOT_OFFERED_CSV_PATH =
    "student_output/courses_not_offered.csv";

struct Course {
  std::string title;
  std::string number_of_units;
  std::string quarter;

  // ignore this!
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

std::ostream &operator<<(std::ostream &os, const Course &course) {
  os << course.title << "," << course.number_of_units << ","
     << course.quarter;
  return os;
}

// forward declarations
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);
void print_vector(std::vector<Course> vector_of_courses);
void parse_csv(std::string filename, std::vector<Course> &vector_of_courses);
void write_courses_offered(std::vector<Course> &vector_of_courses);
void write_courses_not_offered(std::vector<Course> &vector_of_courses);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */

//GLOBAL VARIABLES

//This vector stores all the courses from the courses.csv file
std::vector<Course> courseList;
//This vector stores all the courses that are not offered. 
//CAUTION: THIS VECTOR WILL ONLY BE POPULATED AFTER CALLING write_courses_offered
std::vector<Course> classesToRemove;

void parse_csv(std::string filename, std::vector<Course> &vector_of_courses) {
  std::ifstream myStream(filename);
  std::string row; 

  if(!myStream.is_open()){
    std::cerr << "The file did not open successfully." << std::endl;
  } else {
    std::cout << "The file has been successfully opened." << std::endl;
  }
  
  while(true){
    Course course;
    std::getline(myStream, row);
    std::vector<std::string> result = split(row, ',');

    for(int i = 0; i < result.size(); i++){
      course = {
        result[0], 
        result[1], 
        result[2]
        };
    }
    courseList.push_back(course);

    if(myStream.fail()) break;

  }
}

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
void write_courses_offered(std::vector<Course>& vector_of_courses) {

    std::ofstream out(COURSES_OFFERED_CSV_PATH);

    if(!out.is_open()){
      std::cerr << "The file failed to open" << std::endl;
      return;
    } 
    
    //Check if the data has written to the file or not
    if(out.eof()){
        std::cerr << "Failed to write the data to the file." << std::endl;
        return;
      }

    //Check if the vector is empty or no
    if(vector_of_courses.empty()){
        std::cerr << "The vector is empty" << std::endl;
        return;
      }

      for(Course item : vector_of_courses){

        if(item.quarter == "null"){
          classesToRemove.push_back(item);
        }
      }

      for(Course noClass : classesToRemove){
        
        std::cout << noClass << std::endl;
        delete_elem_from_vector(vector_of_courses, noClass);
      }
 
      for(Course remaining : vector_of_courses){
        out<< remaining << std::endl;
      }

    out.flush();
    out.close();
}

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
void write_courses_not_offered(std::vector<Course>& vector_of_courses) {
  
  std::ofstream out(COURSES_NOT_OFFERED_CSV_PATH);

  if(!out.is_open()){
    std::cerr << "The file failed to open" << std::endl;
    return;
  }
  
  for(Course item : classesToRemove){
    out << item << std::endl;
  }

  out.flush();
  out.close();
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

void print_vector(std::vector<Course> vector_of_courses) {
  for (Course course : vector_of_courses) {
    std::cout << course << std::endl;
  }
}
void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
  std::vector<Course>::iterator it = std::find(v.begin(), v.end(), elem);
  v.erase(it);
}

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, delim)) {
    return_vec.push_back(token);
  }
  return return_vec;
}
