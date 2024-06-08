from csv_utils import *
import os

def main():
  # fstream writing tests!
  
  # TODO: pwd
  PATH = "C:\\Users\\bkjms\\Downloads\\simpleenroll_starter\\simpleenroll_starter"
  
  '''
  !!!!!!!!! PLEASE DO NOT MODIFY THE CODE BELOW !!!!!!!!!
  '''
  
  binary_to_csv(PATH + "/utils/courses_not_offered.bin", PATH + "/utils/courses_not_offered.csv")
  binary_to_csv(PATH + "/utils/courses_offered.bin", PATH + "/utils/courses_offered.csv")

  try:  
    print("2. Testing write_courses_offered...")
    assert files_are_equal(PATH + "/utils/courses_offered.csv", PATH + "/student_output/courses_offered.csv"), " -- write_courses_offered test failed"
    print(" --  write_courses_offered test passed! ")
    print("3. Testing write_courses_not_offered... ")
    assert files_are_equal(PATH + "/utils/courses_not_offered.csv", PATH + "/student_output/courses_not_offered.csv"), " -- write_courses_not_offered test failed "
    print(" --  write_courses_not_offered test passed! ")
    # os.remove(PATH + "/utils/courses_not_offered.csv")
    # os.remove(PATH + "/utils/courses_offered.csv")
    print("Congratulations, your code passes all the autograder tests! ")
  except AssertionError as e:
    # os.remove(PATH + "/utils/courses_not_offered.csv")
    # os.remove(PATH + "/utils/courses_offered.csv")
    print(e)
  

main()
