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
Test1: Verification the type of 
Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors. 

Test2: Check that the variables u and v are the same size.

Test3: Verification of Simulation Accuracy with Zero Initial Values
This test confirms the mathematical correctness of the simulation when the initial concentrations of both chemicals u and v are set to zero. The testing process includes the steps such as initialisation, simulation execution and results verification. The third test in our simulation suite is designed to establish the mathematical accuracy of the Gray-Scott model under the condition that both chemicals u and v start with zero initial concentrations. It proceeds by initialising the entire grid to zero and then running the simulation for the designated number of iterations. After the simulation, the test checks for any non-zero values in ‘u’ to detect unexpected reactions, and verifies that ‘v’ maintains zero values throughout, thus ensuring that the simulation behaves as predicted when devoid of initial reactants.
