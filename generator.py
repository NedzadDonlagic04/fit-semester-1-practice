import sys
import os

problem_folder_name = sys.argv[1]

os.mkdir(f'{problem_folder_name}')
os.mkdir(f'{problem_folder_name}/img')

with open(f'{problem_folder_name}/README.md', 'w') as readme:
    readme.writelines([f"# {problem_folder_name}\n\n", 'Description text goes here'])

with open(f'{problem_folder_name}/1.cpp', 'w') as task_file:
    task_file.write("""#include<iostream>

int main(int argv, char* argc[]) {
    std::cout<<"Hello World!\\n";

    return 0;
}
""")