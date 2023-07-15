import sys
import os

problem_path = f'problems/{sys.argv[1]}'

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