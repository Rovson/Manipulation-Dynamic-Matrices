# Manipulation-Dynamic-Matrices

## Introduction

This project explores advanced object-oriented programming (OOP) principles in C++, focusing on inheritance, templates, and dynamic memory management. The aim is to develop skills in structuring classes that handle dynamic matrices and various data types within a reusable and efficient framework.

## Project Structure

```
DietaryProject/
│
├── Ejercicio1/
│   ├── Ejercicio1.pro
│   ├── Ejercicio1.pro.user
│   ├── main.cpp
│   ├── Matriz.cpp
│   ├── Matriz.h
│   ├── MatrizA.cpp
│   ├── MatrizA.h
│   ├── MatrizC.cpp
│   ├── MatrizC.h
│   ├── MatrizP.cpp
│   ├── MatrizP.h
│   ├── MatrizS.cpp
│   ├── MatrizS.h
│
├── Ejercicio2/
│   ├── Capicua.cpp
│   ├── Ejercicio2.pro
│   ├── Ejercicio2.pro.user
│   ├── main.cpp
│   ├── Matriz.cpp
│   ├── Matriz.h
│   ├── MatrizA.cpp
│   ├── MatrizA.h
│   ├── MatrizC.cpp
│   ├── MatrizC.h
│   ├── MatrizP.cpp
│   ├── MatrizP.h
│   ├── MatrizS.cpp
│   ├── MatrizS.h
│
├── documentacion.pdf
├── README.md
└── .gitignore
```

## Objectives

- Implement advanced class designs in C++.
- Develop skills in managing dynamic matrices and various data types.
- Utilize inheritance and templates to enhance class functionalities.
- Demonstrate comprehensive testing and documentation practices.

## Tools and Technologies

- **Classes and Objects**: Defined base and derived classes for different matrix types.
- **Constructors and Destructors**: Proper memory management for dynamic matrices.
- **Operator Overloading**: Implemented for intuitive matrix operations.
- **Dynamic Memory**: Managed using pointers and dynamic allocation.
- **Inheritance**: Extended functionality of the base `Matriz` class.
- **Templates**: Enabled handling of various data types.

## Detailed Description

### Ejercicio1

Contains the implementation for handling different types of matrices:

- **Matriz**: Base class for dynamic integer matrices.
  - **Attributes**: Dynamic 2D array, dimensions.
  - **Methods**: Constructor, Destructor, Input/Output operations, etc.
- **MatrizA**: Derived class for antisymmetric matrices.
  - **Additional Attributes**: Specific constraints for antisymmetry.
  - **Additional Methods**: Overridden methods to ensure antisymmetry.
- **MatrizC**: Derived class for square matrices.
  - **Additional Attributes**: Constraints ensuring matrix is square.
  - **Additional Methods**: Specific operations for square matrices.
- **MatrizP**: Derived class for power matrices.
  - **Additional Attributes**: Characteristics unique to power matrices.
  - **Additional Methods**: Power-specific operations.
- **MatrizS**: Derived class for symmetric matrices.
  - **Additional Attributes**: Symmetry constraints.
  - **Additional Methods**: Methods ensuring symmetry.

### Ejercicio2

Extends functionality to handle matrices of different data types and special cases like capicua numbers:

- **Capicua**: Class for handling capicua numbers within matrix structures.
  - **Attributes**: Characteristics of capicua numbers.
  - **Methods**: Validation and manipulation of capicua numbers.
- **Templates and Inheritance**: Demonstrating advanced usage of templates combined with inheritance for various data types.

## Documentation

Refer to the `documentacion.pdf` for detailed insights into the project, including:

- **Introduction and Objectives**
- **Detailed Class Descriptions**
- **Code Examples and Explanations**
- **Testing and Validation Procedures**
- **Use Cases and Applications**

## Compilation and Execution

To compile and run the project, ensure you have a compatible C++ compiler installed. Use the following commands:

### Ejercicio1

```bash
# Navigate to Ejercicio1 directory
cd Ejercicio1

# Compile the main file
g++ main.cpp Matriz.cpp MatrizA.cpp MatrizC.cpp MatrizP.cpp MatrizS.cpp -o Ejercicio1

# Run the executable
./Ejercicio1
```

### Ejercicio2

```bash
# Navigate to Ejercicio2 directory
cd Ejercicio2

# Compile the main file
g++ main.cpp Capicua.cpp Matriz.cpp MatrizA.cpp MatrizC.cpp MatrizP.cpp MatrizS.cpp -o Ejercicio2

# Run the executable
./Ejercicio2
```

## Usage

### Ejercicio1

1. **Initialization**: Initialize matrices and input data.
2. **Operations**: Perform operations like addition, multiplication, etc.
3. **Output**: Display results.

### Ejercicio2

1. **Capicua Validation**: Validate and manipulate capicua numbers.
2. **Template Operations**: Perform operations on matrices of various data types.
3. **Extended Functionality**: Utilize advanced methods and operations provided by derived classes.

## Testing

Various test cases are provided in the documentation and within the source files to validate the functionality of the matrices and their operations. These include:

- **Unit Tests**: For individual class methods and operations.
- **Integration Tests**: For overall functionality and combined operations.
- **Edge Cases**: Handling special scenarios and inputs.

## Contributing

If you want to contribute to the project, please follow these steps:

1. **Fork the Repository**: Create a fork of the repository on GitHub.
2. **Clone the Repository**: Clone the forked repository to your local machine.
3. **Create a Branch**: Create a new branch for your feature or bugfix.
4. **Make Changes**: Implement your changes and improvements.
5. **Test**: Thoroughly test your changes.
6. **Commit and Push**: Commit your changes and push to your forked repository.
7. **Submit a Pull Request**: Create a pull request to the original repository.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.


