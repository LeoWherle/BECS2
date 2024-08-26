# BECS2 - Basic Entity Component System v2

Second version of BECS that I did a few weeks ago, this time playing around with templates and trying to make it more efficient.

The core architecture is simple and easier to understand, with a bitfield array for each entity storing the components it has, and a table for each component storing the data of each entity that has it.

## Current Features

- [x] Entity creation
- [x] Component creation
- [x] Component data creation
- [x] Entity-Component mapping
- [x] Component-Table creation
- [x] Debugging
- [] Optimized data storage
- [] Assemblage creation
- [] Multithreading
- [] Networking
