# <p style="text-align:center"> Work I | Creating a 3D Modeler

## Description

The goal of this work is to implement a simple 3D modeler, using OpenGL and C++. The modeler must allow the user to create a scenario with a certain level of detail (subjective evaluation considering complexity and creativity). The modeler must allow the user to save and load the scenario in a file. The modeler must also allow the user to move the camera through the scenario, make transformations, such as: translation, rotation and scale. 
___________________

## [`6.0 points`] Implement a modeler
- [`2.5 points`] Object-Oriented implementation (define a class Object)
  - [`1.0 point`] inheritance
    - define a draw method (virtual) to be implemented by more specific classes (inherit from the Object class), for example: Tree, ...
  - [`0.5 point`] Transformations
    - include attributes related to possible transformations: translation / rotation / scale
  - [`0.5 point`] Selection
    - include an attribute in the Object class to say whether the object is selected or not if it should or should not be painted with a highlight color (white, for example), use it as a test in the draw method
  - [`0.5 point`] Local Reference System
    - include an attribute in the Object class to switch between drawing or not the axes of the local system of the object. Use it as a test in the draw method.

- [`1.5 points`]  Manipulation of the Object vector
  - [`0.5 point`] Allow to include objects in this vector (using the keyboard)
    - Allow to include independent objects, including those of the same type (same child class). Each type of object must be associated with a different key
    - Objects must be included with their center coinciding with the origin of the local system; Its local system must initially be aligned with the global system; Use the modeler itself, during its execution, to position each object (selected) in the scenario
  - [`0.5 point`] Allow to switch / select the objects in this vector (one at a time, following the order of the vector)
    - Mark the selected object (paint with a highlight color, the whole object with the same color)
    - Define keys to advance and to return in the vector. Allow cyclic advance and return (going from the last to the first and vice versa)
  - [`0.5 point`] Allow to delete objects from this vector (using the keyboard)
    - Allow to delete the selected object
    - Allow to delete the last object in the vector.
- [`1.5 points`] Allow to modify the attributes of the selected object
  - [`1.2 points`] Translation / Rotation / Scale (using the mouse)
    - Force the user to model the scenario from the execution of the modeler (program), and not directly in the code
  - [`0.3 points`] Draw or not the axes of the local system (using some key)
- [`0.5 point`] Allow to save and load all objects (all their attributes) from the vector to / from a file

## [`1.0 point`] Cameras
- [`0.2 point`] Include ready-made implementation already available in the examples (class Camera [CameraDistante and / or CameraJogo])
  - That allows to move the camera through the scenario
- [`0.8 point`] Pre-establish positions / orientations (at least 6) of specific interesting cameras, according to the modeled scenario

## [`3.0 points`] Model, save and load a scenario with a certain level of detail (subjective evaluation considering complexity and creativity)
- Based on the exercises (in the dropbox) or suggestions given (do not model laboratory, nor classroom)
  - At least 5 different types of objects (some of them can use 3ds)
- At least 2 objects must be modeled using glBegin (...); ... glEnd ();
  - Define the glNormal3f (...); of the faces (composed by the vertices) properly
  - At least 2 inclined faces (that is, not aligned with the axes of the local coordinate system of the object)(Using fixed local transformations can facilitate)

***Suggestions:*** Use C ++, QtCreator, OpenGL, GLUT / Qt [easier using the GUI graphics layer]
___________________
***<p style='color:red;'>Score of the items depends on the explanation made by video!<p>***

