## Design Pattern


Reference:
https://refactoring.guru/design-patterns/cpp <br>

Design patterns in C++ are reusable solutions to common problems in software design, providing templates to create maintainable, flexible, and scalable code.

Below are the design pattern in C++

	1. Creational Pattern (deal with process of object creation)
		a. Singleton - Ensures only one instance of a class exists 
			i. Implementation: static instance variable, static getInstance() method, private constructor 
			ii. Examples: Logger class (prevents multiple log files), Database connection (shared resource) 
		b. Factory - Creates objects without specifying exact classes 
			i. Problem: Client code shouldn't depend on concrete class names 
			ii. Solution: Factory hides object creation logic 
			iii. Examples: - 
				1) Vehicle factory (Car, Bike) - creates different types
				2) UI factory (WindowsButton, MacButton) - platform-specific creation
				3) Logistics (RoadTransport, SeaTransport) - delivery method hidden from client
		c. Builder - Constructs complex objects step-by-step 
			i. Problem: Too many constructor parameters, optional configurations 
			ii. Solution: Fluent interface for incremental object construction 
			iii. Examples: - 
				1) House (stone vs wooden) - same type, different configurations
				2) Pizza (size, toppings) - many optional parameters - 
				3) HTTP Request (headers, body, auth) - complex object assembly
	

    2. Structural Pattern -(deal with class or object composition to form complex and large structures while making it flexible and efficient) 
		a. Adapter - Act bridge or middle layer between two incompatible interfaces/classes to work together. 
			i. Example: In API integration, time format difference while storing in database and when shown on user interface, adapter is being used to show in readable format.
		b. Composite - Use the Composite pattern when you have to implement a tree-like object structure.


	3. Behavioral Pattern -(deal with communication between object and classes)
		a. Observer - it defines one to many dependency between object, so if one object changes state, all its dependents (observer) are notified and update automatically. 
			i. Example: stock update (all the investors as observers are updated)
		b. Strategy - it defines a family of algorithms, encapsulate each one, makes them interchangeable and it allows a client to choose an appropriate algorithm.
			i. Example: Payment method (UPI/Card/Cash)

<br>
Modern C++ Perspective
	• Modern C++ reduces need for some patterns but does not remove them.
	• Examples: 
		○ Singleton → Dependency Injection / scoped objects 
		○ Factory → std::make_unique, templates 
		○ Strategy → std::function, lambdas 
		○ Observer → call-backs 
	• Patterns still used when runtime flexibility is needed

