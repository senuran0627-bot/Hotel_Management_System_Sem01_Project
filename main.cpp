/*
    HOTEL MANAGEMENT SYSTEM
    ------------------------
    This console application covers the eight components in the project
    requirements. Data is kept in memory while the program is running.

    Default administrator login:
        Username: hotelstaff@1234
        Password: staff1234hotel

    The program uses simple structs, vectors, functions, loops, and menus so
    each part can be understood and improved later.
*/

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const double TAX_RATE = 0.10;
const double SERVICE_CHARGE_RATE = 0.05;

enum RoomStatus { AVAILABLE, OCCUPIED, RESERVED, CLEANING, MAINTENANCE };

struct User { string username, password, role, phone; };
struct Customer { int id; string name, nic, phone, email, address, feedback; int rating; };
struct Room { int number, capacity; string type; double price; RoomStatus status; string maintenanceNote; };
struct Booking { int id, customerId, roomNumber, nights; string checkIn, checkOut, status; double discount; bool paid; string paymentMethod, paymentDate; };
struct FoodItem { int id; string name, category; double price; bool available; };
struct OrderLine { int foodId, quantity; };
struct FoodOrder { int id, bookingId; vector<OrderLine> lines; string status; };
struct TableReservation { int id, tableNumber, customerId; string date, time, status; };
struct Staff { int id; string name, position, department, phone, address; double salary; };
struct Attendance { int staffId; string date, status; };

vector<User> users;
vector<Customer> customers;
vector<Room> rooms;
vector<Booking> bookings;
vector<FoodItem> menuItems;
vector<FoodOrder> foodOrders;
vector<TableReservation> tableReservations;
vector<Staff> staffMembers;
vector<Attendance> attendanceRecords;

int nextCustomerId = 1001, nextBookingId = 5001, nextFoodId = 1;
int nextOrderId = 1, nextTableReservationId = 1, nextStaffId = 1;

// These input helpers keep invalid input from breaking the menu loop.
void clearInput() { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) { cin.ignore(numeric_limits<streamsize>::max(), '\n'); return value; }
        cout << "Please enter a valid number.\n"; clearInput();
    }
}

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) { cin.ignore(numeric_limits<streamsize>::max(), '\n'); return value; }
        cout << "Please enter a valid positive number.\n"; clearInput();
    }
}

string readLine(const string& prompt) { string value; cout << prompt; getline(cin, value); return value; }

bool yesNo(const string& prompt) {
    string answer = readLine(prompt + " (y/n): ");
    return !answer.empty() && (answer[0] == 'y' || answer[0] == 'Y');
}

string currentDate() {
    time_t now = time(0); tm* localTime = localtime(&now); stringstream result;
    result << setfill('0') << (1900 + localTime->tm_year) << "-" << setw(2)
           << (1 + localTime->tm_mon) << "-" << setw(2) << localTime->tm_mday;
    return result.str();
}

string roomStatusName(RoomStatus status) {
    switch (status) {
        case AVAILABLE: return "Available"; case OCCUPIED: return "Occupied";
        case RESERVED: return "Reserved"; case CLEANING: return "Cleaning";
        case MAINTENANCE: return "Maintenance";
    }
    return "Unknown";
}

// Search functions return a pointer to the matching record, or 0 when absent.
User* findUser(const string& username) { for (size_t i = 0; i < users.size(); i++) if (users[i].username == username) return &users[i]; return 0; }
Customer* findCustomer(int id) { for (size_t i = 0; i < customers.size(); i++) if (customers[i].id == id) return &customers[i]; return 0; }
Room* findRoom(int number) { for (size_t i = 0; i < rooms.size(); i++) if (rooms[i].number == number) return &rooms[i]; return 0; }
Booking* findBooking(int id) { for (size_t i = 0; i < bookings.size(); i++) if (bookings[i].id == id) return &bookings[i]; return 0; }
FoodItem* findFood(int id) { for (size_t i = 0; i < menuItems.size(); i++) if (menuItems[i].id == id) return &menuItems[i]; return 0; }
Staff* findStaff(int id) { for (size_t i = 0; i < staffMembers.size(); i++) if (staffMembers[i].id == id) return &staffMembers[i]; return 0; }

void printCustomer(const Customer& customer) {
    cout << "ID: " << customer.id << "\nName: " << customer.name
         << "\nNIC/Passport: " << customer.nic << "\nPhone: " << customer.phone
         << "\nEmail: " << customer.email << "\nAddress: " << customer.address << '\n';
}

void printRoom(const Room& room) {
    cout << "Room " << room.number << " | " << room.type << " | Capacity: " << room.capacity
         << " | $" << fixed << setprecision(2) << room.price << " | " << roomStatusName(room.status) << '\n';
}

void printBooking(const Booking& booking) {
    Customer* customer = findCustomer(booking.customerId); Room* room = findRoom(booking.roomNumber);
    cout << "Booking ID: " << booking.id << "\nCustomer: " << (customer ? customer->name : "Unknown")
         << " (ID " << booking.customerId << ")\nRoom: " << booking.roomNumber << " ("
         << (room ? room->type : "Unknown") << ")\nCheck-in: " << booking.checkIn
         << "\nCheck-out: " << booking.checkOut << "\nNights: " << booking.nights
         << "\nStatus: " << booking.status << '\n';
}

void seedData() {
    users.push_back((User){"hotelstaff@1234", "staff1234hotel", "Administrator", "0000000000"});
    rooms.push_back((Room){101, 1, "Single", 50.00, AVAILABLE, ""});
    rooms.push_back((Room){102, 1, "Single", 50.00, AVAILABLE, ""});
    rooms.push_back((Room){201, 2, "Double", 80.00, AVAILABLE, ""});
    rooms.push_back((Room){202, 2, "Double", 80.00, AVAILABLE, ""});
    rooms.push_back((Room){301, 4, "Suite", 150.00, AVAILABLE, ""});
    menuItems.push_back((FoodItem){1, "Rice and Curry", "Main Course", 8.00, true});
    menuItems.push_back((FoodItem){2, "Chicken Burger", "Main Course", 10.00, true});
    menuItems.push_back((FoodItem){3, "Fresh Juice", "Beverage", 4.00, true});
    menuItems.push_back((FoodItem){4, "Coffee", "Beverage", 3.00, true});
    staffMembers.push_back((Staff){1, "Hotel Administrator", "Manager", "Administration", "0000000000", "Hotel", 2500.00});
    nextStaffId = 2;
}

// ---------------- COMPONENT 1: AUTHENTICATION ----------------
bool login(User*& loggedInUser) {
    cout << "\n==============================================\n          HOTEL MANAGEMENT SYSTEM\n==============================================\n";
    for (int attempt = 1; attempt <= 3; attempt++) {
        string username = readLine("Username: "); string password = readLine("Password: "); User* user = findUser(username);
        if (user && user->password == password) { loggedInUser = user; cout << "Login successful. Welcome, " << user->role << ".\n"; return true; }
        cout << "Invalid username or password. Attempts left: " << 3 - attempt << '\n';
    }
    return false;
}

void registerUser() {
    string username = readLine("New username: "); if (findUser(username)) { cout << "Username already exists.\n"; return; }
    User user = {username, readLine("Password: "), readLine("Role: "), readLine("Phone: ")}; users.push_back(user); cout << "User registered successfully.\n";
}

void updateUser() {
    User* user = findUser(readLine("Username to update: ")); if (!user) { cout << "User not found.\n"; return; }
    user->role = readLine("New role: "); user->phone = readLine("New phone: "); cout << "User updated successfully.\n";
}

void deleteUser() {
    string username = readLine("Username to delete: "); if (username == "hotelstaff@1234") { cout << "The default administrator cannot be deleted.\n"; return; }
    for (vector<User>::iterator it = users.begin(); it != users.end(); ++it) if (it->username == username) {
        if (yesNo("Delete this user")) { users.erase(it); cout << "User deleted successfully.\n"; } return;
    }
    cout << "User not found.\n";
}

void changePassword(User* user) {
    if (readLine("Current password: ") != user->password) { cout << "Incorrect current password.\n"; return; }
    string password = readLine("New password: "); if (password.empty() || password != readLine("Confirm new password: ")) { cout << "Passwords do not match.\n"; return; }
    user->password = password; cout << "Password changed successfully.\n";
}

void userManagement(User* currentUser) {
    int choice; do {
        cout << "\n--- USER ADMINISTRATION ---\n1. Register user\n2. Update user\n3. Delete user\n4. Change my password\n5. List users\n6. Back\n"; choice = readInt("Choice: ");
        if (choice == 1) registerUser(); else if (choice == 2) updateUser(); else if (choice == 3) deleteUser(); else if (choice == 4) changePassword(currentUser);
        else if (choice == 5) for (size_t i = 0; i < users.size(); i++) cout << users[i].username << " - " << users[i].role << '\n';
    } while (choice != 6);
}

// ---------------- COMPONENT 3: CUSTOMERS ----------------
void registerCustomer() {
    Customer customer; customer.id = nextCustomerId++; customer.name = readLine("Name: "); customer.nic = readLine("NIC/Passport: ");
    for (size_t i = 0; i < customers.size(); i++) if (customers[i].nic == customer.nic) { cout << "Customer already registered.\n"; return; }
    customer.phone = readLine("Phone: "); customer.email = readLine("Email: "); customer.address = readLine("Address: "); customer.feedback = ""; customer.rating = 0; customers.push_back(customer);
    cout << "Customer registered successfully. Customer ID: " << customer.id << '\n';
}
void searchCustomer() { Customer* customer = findCustomer(readInt("Customer ID: ")); if (customer) printCustomer(*customer); else cout << "Customer not found.\n"; }
void updateCustomer() { Customer* c = findCustomer(readInt("Customer ID: ")); if (!c) { cout << "Customer not found.\n"; return; } printCustomer(*c); c->name = readLine("New name: "); c->phone = readLine("New phone: "); c->email = readLine("New email: "); c->address = readLine("New address: "); cout << "Customer details updated successfully.\n"; }
void deleteCustomer() { int id = readInt("Customer ID: "); for (vector<Customer>::iterator it = customers.begin(); it != customers.end(); ++it) if (it->id == id) { if (yesNo("Delete this customer")) { customers.erase(it); cout << "Customer record deleted successfully.\n"; } return; } cout << "Customer not found.\n"; }
void customerHistory() { int id = readInt("Customer ID: "); Customer* c = findCustomer(id); if (!c) { cout << "Customer history not available.\n"; return; } printCustomer(*c); bool found = false; for (size_t i = 0; i < bookings.size(); i++) if (bookings[i].customerId == id) { printBooking(bookings[i]); found = true; } if (!found) cout << "No bookings yet.\n"; }
void currentCustomers() { bool found = false; for (size_t i = 0; i < bookings.size(); i++) if (bookings[i].status == "Checked-in") { Customer* c = findCustomer(bookings[i].customerId); cout << c->name << " - room " << bookings[i].roomNumber << " - check-in " << bookings[i].checkIn << '\n'; found = true; } if (!found) cout << "No current customers.\n"; }
void feedback() { Customer* c = findCustomer(readInt("Customer ID: ")); if (!c) { cout << "Customer not found.\n"; return; } c->feedback = readLine("Feedback: "); c->rating = readInt("Rating (1-5): "); cout << "Feedback submitted successfully.\n"; }

void customerManagement() {
    int choice; do { cout << "\n--- CUSTOMER MANAGEMENT ---\n1. Register customer\n2. Search customer\n3. Update customer\n4. Delete customer\n5. Customer history\n6. Current customers\n7. Feedback\n8. Back\n"; choice = readInt("Choice: ");
        if (choice == 1) registerCustomer(); else if (choice == 2) searchCustomer(); else if (choice == 3) updateCustomer(); else if (choice == 4) deleteCustomer(); else if (choice == 5) customerHistory(); else if (choice == 6) currentCustomers(); else if (choice == 7) feedback();
    } while (choice != 8);
}

// ---------------- COMPONENT 4: ROOMS ----------------
void addRoom() { int number = readInt("Room number: "); if (findRoom(number)) { cout << "Room already exists.\n"; return; } Room room = {number, readInt("Capacity: "), readLine("Type: "), readDouble("Price per night: "), AVAILABLE, ""}; rooms.push_back(room); cout << "Room added successfully.\n"; }
void updateRoom() { Room* r = findRoom(readInt("Room number: ")); if (!r) { cout << "Room not found.\n"; return; } printRoom(*r); r->type = readLine("New type: "); r->capacity = readInt("New capacity: "); r->price = readDouble("New price: "); cout << "Room information updated successfully.\n"; }
void deleteRoom() { int number = readInt("Room number: "); for (vector<Room>::iterator it = rooms.begin(); it != rooms.end(); ++it) if (it->number == number) { if (it->status == OCCUPIED || it->status == RESERVED) { cout << "Cannot delete an occupied or reserved room.\n"; return; } if (yesNo("Delete this room")) { rooms.erase(it); cout << "Room deleted successfully.\n"; } return; } cout << "Room not found.\n"; }
void searchRoom() { Room* r = findRoom(readInt("Room number: ")); if (r) printRoom(*r); else cout << "Room not found.\n"; }
void availableRooms() { bool found = false; for (size_t i = 0; i < rooms.size(); i++) if (rooms[i].status == AVAILABLE) { printRoom(rooms[i]); found = true; } if (!found) cout << "No available rooms.\n"; }
void updateRoomStatus() { Room* r = findRoom(readInt("Room number: ")); if (!r) { cout << "Room not found.\n"; return; } cout << "1 Available  2 Occupied  3 Reserved  4 Cleaning  5 Maintenance\n"; int choice = readInt("New status: "); if (choice < 1 || choice > 5) { cout << "Invalid status.\n"; return; } r->status = static_cast<RoomStatus>(choice - 1); cout << "Room status updated successfully.\n"; }
void maintenance() { Room* r = findRoom(readInt("Room number: ")); if (!r) { cout << "Room not found.\n"; return; } r->maintenanceNote = readLine("Maintenance details: "); r->status = MAINTENANCE; cout << "Maintenance record saved.\n"; if (yesNo("Mark maintenance as completed now")) { r->status = AVAILABLE; r->maintenanceNote = ""; cout << "Room is ready for booking.\n"; } }

void roomManagement() {
    int choice; do { cout << "\n--- ROOM MANAGEMENT ---\n1. Add room\n2. Update room\n3. Delete room\n4. Search room\n5. View available rooms\n6. Update room status\n7. Maintenance\n8. Back\n"; choice = readInt("Choice: "); if (choice == 1) addRoom(); else if (choice == 2) updateRoom(); else if (choice == 3) deleteRoom(); else if (choice == 4) searchRoom(); else if (choice == 5) availableRooms(); else if (choice == 6) updateRoomStatus(); else if (choice == 7) maintenance(); } while (choice != 8);
}

// ---------------- COMPONENT 2: RESERVATIONS ----------------
void displayBookingConfirmation(const Booking& b) { cout << "\n========== BOOKING CONFIRMATION ==========\n"; printBooking(b); cout << "==========================================\n"; }
void bookRoom() { Customer* c = findCustomer(readInt("Customer ID (register first): ")); if (!c) { cout << "Customer not found.\n"; return; } availableRooms(); Room* r = findRoom(readInt("Room number: ")); if (!r || r->status != AVAILABLE) { cout << "Selected room is not available.\n"; return; } Booking b; b.id = nextBookingId++; b.customerId = c->id; b.roomNumber = r->number; b.checkIn = readLine("Check-in date (YYYY-MM-DD): "); b.checkOut = readLine("Check-out date (YYYY-MM-DD): "); b.nights = readInt("Number of nights: "); b.status = "Reserved"; b.discount = 0; b.paid = false; b.paymentMethod = ""; b.paymentDate = ""; bookings.push_back(b); r->status = RESERVED; cout << "Booking successful. Booking ID: " << b.id << '\n'; displayBookingConfirmation(b); }
void searchBooking() { Booking* b = findBooking(readInt("Booking ID: ")); if (b) printBooking(*b); else cout << "Reservation not found.\n"; }
void updateBooking() { Booking* b = findBooking(readInt("Booking ID: ")); if (!b) { cout << "Reservation not found.\n"; return; } printBooking(*b); Room* oldRoom = findRoom(b->roomNumber); int newNumber = readInt("New room number (enter current to keep): "); Room* newRoom = findRoom(newNumber); if (!newRoom || (newRoom->status != AVAILABLE && newNumber != b->roomNumber)) { cout << "New room is not available.\n"; return; } if (newNumber != b->roomNumber) { oldRoom->status = AVAILABLE; newRoom->status = RESERVED; b->roomNumber = newNumber; } b->checkIn = readLine("New check-in date: "); b->checkOut = readLine("New check-out date: "); b->nights = readInt("New number of nights: "); cout << "Reservation updated successfully.\n"; }
void cancelBooking() { Booking* b = findBooking(readInt("Booking ID: ")); if (!b) { cout << "Reservation not found.\n"; return; } if (yesNo("Cancel this reservation")) { b->status = "Cancelled"; Room* r = findRoom(b->roomNumber); if (r) r->status = AVAILABLE; cout << "Reservation cancelled successfully.\n"; } }
void checkIn() { Booking* b = findBooking(readInt("Booking ID: ")); if (!b || b->status != "Reserved") { cout << "Invalid reservation.\n"; return; } b->status = "Checked-in"; Room* r = findRoom(b->roomNumber); if (r) r->status = OCCUPIED; cout << "Check-in successful.\n"; }

double foodTotalForBooking(int bookingId) { double total = 0; for (size_t i = 0; i < foodOrders.size(); i++) if (foodOrders[i].bookingId == bookingId) for (size_t j = 0; j < foodOrders[i].lines.size(); j++) { FoodItem* item = findFood(foodOrders[i].lines[j].foodId); if (item) total += item->price * foodOrders[i].lines[j].quantity; } return total; }
double roomCharge(const Booking& b) { Room* r = findRoom(b.roomNumber); return r ? r->price * b.nights : 0; }
double finalBill(const Booking& b) { double subtotal = roomCharge(b) + foodTotalForBooking(b.id); double service = subtotal * SERVICE_CHARGE_RATE; double afterDiscount = subtotal + service - b.discount; return afterDiscount + afterDiscount * TAX_RATE; }
void checkout() { Booking* b = findBooking(readInt("Booking ID: ")); if (!b || b->status != "Checked-in") { cout << "Reservation not found or customer is not checked in.\n"; return; } cout << "Final bill: $" << fixed << setprecision(2) << finalBill(*b) << '\n'; b->paymentMethod = readLine("Payment method (Cash/Card/Online): "); b->paid = true; b->paymentDate = currentDate(); b->status = "Checked-out"; Room* r = findRoom(b->roomNumber); if (r) r->status = AVAILABLE; cout << "Payment successful. Check-out completed.\n"; }

void reservationManagement() {
    int choice; do { cout << "\n--- RESERVATIONS ---\n1. Book room\n2. Search reservation\n3. Update reservation\n4. Cancel reservation\n5. Check room availability\n6. Booking confirmation\n7. Check-in\n8. Check-out\n9. Back\n"; choice = readInt("Choice: "); if (choice == 1) bookRoom(); else if (choice == 2) searchBooking(); else if (choice == 3) updateBooking(); else if (choice == 4) cancelBooking(); else if (choice == 5) availableRooms(); else if (choice == 6) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) displayBookingConfirmation(*b); else cout << "Reservation not found.\n"; } else if (choice == 7) checkIn(); else if (choice == 8) checkout(); } while (choice != 9);
}

// ---------------- COMPONENT 5: RESTAURANT ----------------
void displayMenu() { cout << "\n--- FOOD MENU ---\n"; for (size_t i = 0; i < menuItems.size(); i++) if (menuItems[i].available) cout << menuItems[i].id << ". " << menuItems[i].name << " (" << menuItems[i].category << ") $" << menuItems[i].price << '\n'; }
void addFood() { FoodItem item = {nextFoodId++, readLine("Food name: "), readLine("Category: "), readDouble("Price: "), true}; menuItems.push_back(item); cout << "Food item added successfully.\n"; }
void updateFood() { FoodItem* item = findFood(readInt("Food ID: ")); if (!item) { cout << "Food item not found.\n"; return; } item->name = readLine("New name: "); item->category = readLine("New category: "); item->price = readDouble("New price: "); cout << "Menu updated successfully.\n"; }
void removeFood() { FoodItem* item = findFood(readInt("Food ID: ")); if (item && yesNo("Remove this food item")) { item->available = false; cout << "Food item removed successfully.\n"; } else if (!item) cout << "Food item not found.\n"; }
void placeOrder() { int bookingId = readInt("Booking ID: "); if (!findBooking(bookingId)) { cout << "Booking not found.\n"; return; } FoodOrder order = {nextOrderId++, bookingId, vector<OrderLine>(), "New"}; displayMenu(); while (true) { int foodId = readInt("Food ID (0 to finish): "); if (foodId == 0) break; FoodItem* item = findFood(foodId); if (!item || !item->available) { cout << "Food item unavailable.\n"; continue; } order.lines.push_back((OrderLine){foodId, readInt("Quantity: ")}); } if (order.lines.empty()) { cout << "No order placed.\n"; return; } foodOrders.push_back(order); cout << "Order placed successfully. Total: $" << foodTotalForBooking(bookingId) << '\n'; }
void tableReservation() { TableReservation table = {nextTableReservationId, nextTableReservationId, readInt("Customer ID: "), readLine("Date: "), readLine("Time: "), "Reserved"}; nextTableReservationId++; tableReservations.push_back(table); cout << "Table " << table.tableNumber << " reserved successfully.\n"; }
void kitchenOrders() { for (size_t i = 0; i < foodOrders.size(); i++) { cout << "Order " << foodOrders[i].id << " - " << foodOrders[i].status << '\n'; if (yesNo("Mark this order ready to serve")) foodOrders[i].status = "Ready to Serve"; } }
void restaurantManagement() { int choice; do { cout << "\n--- RESTAURANT ---\n1. Display menu\n2. Add food item\n3. Update menu\n4. Remove menu item\n5. Place order\n6. Calculate food bill\n7. Reserve table\n8. Kitchen orders\n9. Back\n"; choice = readInt("Choice: "); if (choice == 1) displayMenu(); else if (choice == 2) addFood(); else if (choice == 3) updateFood(); else if (choice == 4) removeFood(); else if (choice == 5) placeOrder(); else if (choice == 6) cout << "Food bill: $" << foodTotalForBooking(readInt("Booking ID: ")) << '\n'; else if (choice == 7) tableReservation(); else if (choice == 8) kitchenOrders(); } while (choice != 9); }

// ---------------- COMPONENT 6: STAFF ----------------
void addStaff() { Staff member = {nextStaffId++, readLine("Name: "), readLine("Position: "), readLine("Department: "), readLine("Phone: "), readLine("Address: "), readDouble("Monthly salary: ")}; staffMembers.push_back(member); cout << "Staff added successfully.\n"; }
void printStaff(const Staff& member) { cout << member.id << " | " << member.name << " | " << member.position << " | " << member.department << " | " << member.phone << " | $" << member.salary << '\n'; }
void staffManagement() { int choice; do { cout << "\n--- STAFF MANAGEMENT ---\n1. Add staff\n2. Search staff\n3. Update staff\n4. Remove staff\n5. Assign job role\n6. Record attendance\n7. Calculate monthly salary\n8. Display staff\n9. Back\n"; choice = readInt("Choice: "); if (choice == 1) addStaff(); else if (choice == 2) { Staff* s = findStaff(readInt("Staff ID: ")); if (s) printStaff(*s); else cout << "Staff member not found.\n"; } else if (choice == 3) { Staff* s = findStaff(readInt("Staff ID: ")); if (s) { s->name = readLine("New name: "); s->phone = readLine("New phone: "); s->address = readLine("New address: "); cout << "Staff details updated successfully.\n"; } else cout << "Staff ID not found.\n"; } else if (choice == 4) { int id = readInt("Staff ID: "); for (vector<Staff>::iterator it = staffMembers.begin(); it != staffMembers.end(); ++it) if (it->id == id) { if (yesNo("Remove this staff member")) staffMembers.erase(it); break; } } else if (choice == 5) { Staff* s = findStaff(readInt("Staff ID: ")); if (s) { s->position = readLine("New job role: "); cout << "Job role assigned successfully.\n"; } } else if (choice == 6) { int id = readInt("Staff ID: "); if (findStaff(id)) { Attendance record = {id, currentDate(), readLine("Attendance (Present/Absent/Leave): ")}; attendanceRecords.push_back(record); cout << "Attendance recorded successfully.\n"; } } else if (choice == 7) { Staff* s = findStaff(readInt("Staff ID: ")); if (s) cout << "Monthly salary: $" << s->salary << '\n'; } else if (choice == 8) for (size_t i = 0; i < staffMembers.size(); i++) printStaff(staffMembers[i]); } while (choice != 9); }

// ---------------- COMPONENT 7: BILLING ----------------
void printBill(const Booking& b) { double room = roomCharge(b), food = foodTotalForBooking(b.id), service = (room + food) * SERVICE_CHARGE_RATE; double discounted = room + food + service - b.discount, tax = discounted * TAX_RATE; cout << "\n============= FINAL BILL =============\nBooking: " << b.id << "\nRoom charges: $" << room << "\nRestaurant: $" << food << "\nService charges: $" << service << "\nDiscount: $" << b.discount << "\nTax: $" << tax << "\nTOTAL: $" << discounted + tax << "\nPayment: " << (b.paid ? b.paymentMethod : "Pending") << "\n=======================================\n"; }
void billingManagement() { int choice; do { cout << "\n--- BILLING ---\n1. Room charges\n2. Restaurant charges\n3. Service charges\n4. Apply discount\n5. Calculate tax\n6. Generate final bill\n7. Process payment\n8. Save invoice\n9. Back\n"; choice = readInt("Choice: "); if (choice == 1) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) cout << "Room charges: $" << roomCharge(*b) << '\n'; } else if (choice == 2) cout << "Restaurant charges: $" << foodTotalForBooking(readInt("Booking ID: ")) << '\n'; else if (choice == 3) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) cout << "Service charges: $" << (roomCharge(*b) + foodTotalForBooking(b->id)) * SERVICE_CHARGE_RATE << '\n'; } else if (choice == 4) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) { b->discount = readDouble("Discount amount: "); cout << "Discount applied.\n"; } } else if (choice == 5) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) { double subtotal = roomCharge(*b) + foodTotalForBooking(b->id); cout << "Tax: $" << (subtotal + subtotal * SERVICE_CHARGE_RATE - b->discount) * TAX_RATE << '\n'; } } else if (choice == 6) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) printBill(*b); } else if (choice == 7) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) { b->paymentMethod = readLine("Payment method: "); b->paid = true; b->paymentDate = currentDate(); cout << "Payment successful.\n"; } } else if (choice == 8) { Booking* b = findBooking(readInt("Booking ID: ")); if (b) { string filename = "invoice_" + to_string(b->id) + ".txt"; ofstream file(filename.c_str()); file << "HOTEL INVOICE\nBooking: " << b->id << "\nTotal: $" << finalBill(*b) << '\n'; file.close(); cout << "Invoice saved to " << filename << "\n"; } } } while (choice != 9); }

// ---------------- COMPONENT 8: REPORTS ----------------
void reports() { double roomIncome = 0, restaurantIncome = 0; int reserved = 0, occupied = 0, available = 0, cleaning = 0; for (size_t i = 0; i < bookings.size(); i++) if (bookings[i].paid) { roomIncome += roomCharge(bookings[i]); restaurantIncome += foodTotalForBooking(bookings[i].id); } for (size_t i = 0; i < rooms.size(); i++) { if (rooms[i].status == AVAILABLE) available++; else if (rooms[i].status == OCCUPIED) occupied++; else if (rooms[i].status == RESERVED) reserved++; else cleaning++; } cout << "\n========== MANAGEMENT REPORT ==========\nDate: " << currentDate() << "\nIncome tracked in this session: $" << roomIncome + restaurantIncome << "\nRoom income: $" << roomIncome << "\nRestaurant sales: $" << restaurantIncome << "\nTotal bookings: " << bookings.size() << "\nRooms available: " << available << "\nRooms reserved: " << reserved << "\nRooms occupied: " << occupied << "\nRooms cleaning/maintenance: " << cleaning << "\nCustomers: " << customers.size() << "\nStaff: " << staffMembers.size() << "\nAttendance records: " << attendanceRecords.size() << "\n========================================\n"; cout << "Daily/monthly comparisons require saved historical data, which can be added with a database later.\n"; }

void mainMenu(User* currentUser) { int choice; do { cout << "\n=============== MAIN MENU ===============\n1. User administration\n2. Reservations and bookings\n3. Customer management\n4. Room management\n5. Restaurant and food\n6. Staff management\n7. Billing and payments\n8. Reports and analysis\n9. Logout\n"; choice = readInt("Choice: "); if (choice == 1) userManagement(currentUser); else if (choice == 2) reservationManagement(); else if (choice == 3) customerManagement(); else if (choice == 4) roomManagement(); else if (choice == 5) restaurantManagement(); else if (choice == 6) staffManagement(); else if (choice == 7) billingManagement(); else if (choice == 8) reports(); } while (choice != 9); cout << "Logged out successfully.\n"; }

int main() { seedData(); while (true) { User* currentUser = 0; if (!login(currentUser)) { cout << "Too many failed attempts. Program closed.\n"; return 0; } mainMenu(currentUser); if (!yesNo("Log in again")) break; } cout << "Thank you for using the Hotel Management System.\n"; return 0; }
