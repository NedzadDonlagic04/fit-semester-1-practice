# insertion-sort

This problem is a continuation of the sorting
algorithm line I'm doing, but this time I'm
adding a bit more work to it, instead of a dynamic
array with random integers you have to sort an array
filled with employee data (randomly generated ofc),

The sorting will be based on the employee's annual
wage, sorting from the lowest to highest.

Inside the header folder you will find a hpp file 
containing 2 important things, the special class 
and the function that returns a vector of instances
of this class with random data (ie the names are taken
from a random txt file I downloaded from the internet,
you can find it in the txt folder).

The class has getter methods for the ID, full name and
the annual wage of the employee, as well a method that
returns a string which has all of this data formatted
in a way more suited for an output of sorts.
The class also has a method called swap to swap the
value between a given Employee instance and the current
Employee instance, and the class has the operator= 
overridden.

Along with this class the header provides a getRandomWorkersData
function that will take a parameter for the amount of random data
to be generated.

Both of these are found in the custom namespace, an example of calling
both can be seen below:
```cpp
    std::vector<custom::Employee> employeeData {custom::getRandomWorkersData(100)}; 
```

An example of how to implement the insertion sort algorithm can be found
in the img folder with a flowchart.

Remember, the goal is to sort the given employees from lowest to highest
wage, the implementation of the insertion sort should be done manually by
you (since that's the point of the problem), other than that whatever path
you choose, it's important it works.

Good luck!