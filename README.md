# Object-Oriented Hashmap in C

## Key Concepts and OOP Principles Used

1. **Encapsulation**:
   - The `Map` structure acts as an "object," combining:
     - **Data**: The `hashmap` array for storing key-value pairs.
     - **Behavior**: Methods like `put`, `get`, `remove`, and `print` as function pointers.

2. **Abstraction**:
   - Provides a clean API with functions (`put`, `get`, `remove`, etc.) that abstract away the complexities of hashing and collision handling.

3. **Polymorphism (Simulated)**:
   - Function pointers in the `Map` structure simulate methods:
     ```c
     map->put = map_put;
     map->get = map_get;
     ```

4. **Collision Handling**:
   - Resolves hash collisions using **chaining** (a linked list for each bucket).

5. **Generic Design**:
   - Uses `void *` for values, making it possible to store data of any type.

6. **Dynamic Memory Management**:
   - The use of `malloc` and `free` for dynamic memory allocation ensures flexibility, allowing storage of variable-sized data.

## Why This Is Object-Oriented
While C lacks native OOP constructs like classes or inheritance, this implementation achieves similar functionality:
- The `Map` structure functions like a class, encapsulating both data and methods.
- Function pointers simulate method calls.
- The `create_map` function acts as a constructor, initializing the "object" with its data and methods.

## Commands 

1. **Clean the Project**:
   ```bash
   make clean
   ```

2. **Build the Project**:
   ```bash
   make 
   ```

3. **Run the tests**:
   ```bash
   make run
   ```

