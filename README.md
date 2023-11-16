# Ps_Group19_Assignment

##What Is Gray-Scott Model

The Gray-Scott model is a mathematical construct designed to elucidate the mechanisms underlying chemical reactions and diffusion processes. As a quintessential reduction of classical reaction-diffusion systems, this model is extensively employed to investigate the inherent mechanisms of spontaneous pattern generation within spatial systems. It excels in simulating pattern emergence in various realms, such as the patterning of animal fur. The objective of this project is to simulate the Gray-Scott model to thoroughly explore the fundamental principles of pattern formation in chemical and biological systems.

##Main Program

Program Initialisation:
The program requires the following five parameters upon execution:
Du: Diffusion rate of chemical u.
Dv: Diffusion rate of chemical v.
F: Feed rate.
k: Kill rate.
threshold: Threshold value for v concentration.

Output
Every ‘outputInterval’ iterations, the current state of the vector ‘v’ is written to a VTK file by the ‘writeVTKFile’ function. This output allows for the visualisation of the concentration of chemical V across the grid over time.

Simulation Loop
The simulation proceeds through ‘numIterations’ iterations, with each iteration representing a time step in the model. At every step, the ‘simulateStep’ function is called to compute the next concentration levels based on the diffusion rates, feeding rate, and killing rate. It utilises the Laplacian to determine the diffusion effect on each cell from its neighbours.

Post-Simulation Analysis
After the simulation is completed, the ‘countElementsAboveThreshold’ function calculates the proportion of grid cells where the concentration of V exceeds the specified ‘threshold’. This metric is crucial for understanding the distribution and intensity of the patterns formed during the simulation.

##Test Program

The test program is to prove that the main program is greatly complete the simulation and make sure the logic and data is correct, including three parts:

Test1: Verification the type of model parameters and vectors
Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors. Use the "typeid" function to obtain the data type of the first element of the v, u arrays, F and k and perform corresponding comparisons.

Test2: Verification the same size of vectors u and v
Check that the variables u and v are the same size. First, use the "array.size" function to calculate the number of rows of u and v arrays and compare them. Then, determine the columns of both u and v arrays, and compare them.


Test3: Verification of Simulation Accuracy with Zero Initial Values
This test confirms the mathematical correctness of the simulation when the initial concentrations of both chemicals u and v are set to zero. The testing process includes the steps such as initialisation, simulation execution and results verification. The third test in our simulation suite is designed to establish the mathematical accuracy of the Gray-Scott model under the condition that both chemicals u and v start with zero initial concentrations. It proceeds by initialising the entire grid to zero and then running the simulation for the designated number of iterations. After the simulation, the test checks for any non-zero values in ‘u’ to detect unexpected reactions, and verifies that ‘v’ maintains zero values throughout, thus ensuring that the simulation behaves as predicted when devoid of initial reactants.

The test project above selects the Acutest framework. To use Acutest, we don't need to install any additional libraries. We can simply download the source code of the Acutest framework from the official code library, which includes the header files, and then link it to our test project. By including the necessary header files in our test files, we can utilize the functionalities provided by Acutest. These functionalities include writing and running tests, creating test fixtures and test suites and parameterized testing.

##Build a System

In order to improve convenience in unit testing, ensure the correctness of the main function, enhance code readability, maintainability, and testability, and make the project clearer, more modular, and easier to develop and maintain, we have made changes to the "gs.cpp" file.

Firstly, we have created a new file called "main" in the main folder. The main function has been moved to this file for better organization.

Secondly, the remaining code from the "gs.cpp" file has been placed in the "lib" folder, which is located within the "test" folder. This separation allows for better isolation and testing of the code.

Additionally, we have created an "include" folder to store the Acutest header files. This folder contains a header file named "gs.h" which facilitates the calling of simulation parameters and functions required by the three tests.

Lastly, a new test file named "gs-test-1.cpp" has been created in the "test" folder. This file is used for testing the functionality of the code.

These changes ensure that unit testing is more convenient, the main function is correct, the code is easier to read, maintain, and test, and the project is clearer, more modular, and easier to develop and maintain.

##Continuous Integration

In order to implement GitHub Action, we have created two files: build_yaml and docker_yaml.The build_yaml file is a YAML format configuration file used to define the project's build rules and processes, including dependencies, build steps, and the required build environment. It is typically utilized to automate the build process, such as continuous integration and continuous deployment. On the other hand, the docker_yaml file is a YAML format configuration file used to define the configuration details of a Docker container, such as the container's base image, environment variables, and port mapping. It is commonly used to specify the running rules and configuration of Docker containers, as well as the process of building Docker images. Both files are frequently employed to containerize applications, facilitating deployment and execution in diverse environments.
