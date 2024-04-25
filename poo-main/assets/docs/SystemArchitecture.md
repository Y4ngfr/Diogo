# System's Architecture

### **Fundamental classes:**

1. **Vehicle**: Represents a vehicle used for transportation. Includes attributes such as chassis number, model, year, and maximum load capacity.

2. **Client**: Represents a client who requests transportation services. Includes attributes such as name, CPF, and client ID.
3. **Order**: Represents an order for transportation. Includes attributes such as order ID, client ID, description, type of transportation, collection address, delivery address, load weight, and load volume.


### Subclasses:

- **Car**, **Lorry**, and **PickupTruck** are subclasses of **Vehicle**, each representing a specific type of vehicle with potentially specialized behavior or attributes. Currently, there are no specific implementations for these subclasses.

### Intermediar classes:

- **Transport**: Represents a transportation instance, linking an order with a specific vehicle. Contains information such as transport ID, order ID, vehicle ID, collection address, delivery address, and receiver name.
  
### Management classes

- **Garage**: Manages the vehicles available for transportation. Allows adding and removing vehicles from the fleet.

- **TransportManager**: Manages the creation and assignment of transports for orders. Utilizes the Garage and GeoShell classes to allocate vehicles and obtain coordinates, respectively.

### Utility functions

- **GeoShell**: Provides functionality for retrieving geographic coordinates based on location names. Utilizes an external script for geocoding.
