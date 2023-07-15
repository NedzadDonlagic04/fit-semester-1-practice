import sys
import os

"""
    CREATE PROBLEM DIRECTORY
"""

problem_name = sys.argv[1]
problem_path = f'problems/{problem_name}'

os.mkdir(f'{problem_path}')
os.mkdir(f'{problem_path}/img')

with open(f'{problem_path}/README.md', 'w') as readme:
    readme.writelines([f"# {problem_path}\n\n", 'Description text goes here'])

with open(f'{problem_path}/1.cpp', 'w') as task_file:
    task_file.write("""#include<iostream>

int main(int argv, char* argc[]) {
    std::cout<<"Hello World!\\n";

    return 0;
}
""")


"""
    UPDATE README CODE 
"""

# This part for getting the last line of the file
# will need to be refactored in the future due to
# this not being very optimal for big file sizes
last_line = None
with open('README.md') as f:
    for line in f:
        pass
    last_line = line

# take the last line and split it based on the . and the first
# member of the given list will be a number
# increment it by one so it continues the order
problem_number = int(last_line.split('.')[0]) + 1

with open('README.md', 'a') as f:
    f.write(f'\n{problem_number}. {problem_name}')