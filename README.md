# PROG-simulacao-massas-molas

This is the final project for the programming course of the MEFT (integrated master's in physics engineering) degree in the 2015/2016 year.

This was a group project written in C with the GTK+ librariy to make windows with a representation of the system and with graphs of the objects coordinates in function of time, along with buttons, slider, etc to change the various parameters (masses, initial positions and velocities, sping constants...).

The system has two masses (m1 and m2) conected to each other and to a wall with three springs (K1, K2, K3). An image can be seen in the pdf within this repository. The masses of the springs are not considered.

The equations are:

- <img src="https://latex.codecogs.com/gif.latex?L=\frac{1}{2}m_1\dot{x}_1^2+\frac{1}{2}m_2\dot{x_2}_2^2-\frac{1}{2}K_1(x_1-l_1)^2-\frac{1}{2}K_2((x_2-x_1)-l_2)^2-\frac{1}{2}K_3(x_1-x_2+L-l_3)^2 " />

- <img src="https://latex.codecogs.com/gif.latex?\frac{d}{dt}\frac{\partial L}{\partial \dot{x_1}}-\frac{\partial L}{\partial x_1}=0 " /> 

- <img src="https://latex.codecogs.com/gif.latex?\frac{d}{dt}\frac{\partial L}{\partial \dot{x_2}}-\frac{\partial L}{\partial x_2}=0 " /> 


